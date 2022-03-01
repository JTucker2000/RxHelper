#include "PatientListUIPanel.h"

PatientListUIPanel::PatientListUIPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, 2621440L, wxPanelNameStr)
{
	// Sizer for listctrl and its buttons.
	wxBoxSizer* lc_sizer = new wxBoxSizer(wxVERTICAL);
	PatientListBtnPanel* lc_btn_panel = new PatientListBtnPanel(this);
	lc_sizer->Add
	(
		lc_btn_panel,
		wxSizerFlags().Expand()
	);
	patient_listctrl = new wxListCtrl(this, PATIENTLISTCTRL_ID, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
	lc_sizer->Add
	(
		patient_listctrl,
		wxSizerFlags(1).Expand().Border(wxLEFT | wxRIGHT | wxDOWN, 5)
	);
	wxFont tempf = patient_listctrl->GetFont(); // Make listctrl font bigger.
	tempf.SetPointSize(12);
	patient_listctrl->SetFont(tempf);
	patient_listctrl->InsertColumn(0, "ID Number"); // Add columns to listctrl.
	patient_listctrl->InsertColumn(1, "Name"); 
	patient_listctrl->InsertColumn(2, "Address");
	patient_listctrl->InsertColumn(3, "Zip");
	patient_listctrl->InsertColumn(4, "State");
	patient_listctrl->InsertColumn(5, "Phone");
	patient_listctrl->InsertColumn(6, "# of Medications");

	initPatientsFromDatabase();

	resizeColumns();

	patient_listctrl->Bind(wxEVT_SIZE, &PatientListUIPanel::resizeColumnsEvt, this); // Automatically resize columns.
	lc_btn_panel->Bind(wxEVT_BUTTON, &PatientListUIPanel::removePatientEvt, this, REMOVEPATIENTBTN_ID); // Remove patient button click.

	SetSizer(lc_sizer);
}

Patient* PatientListUIPanel::getSelectedPatient()
{
	long selected_item = patient_listctrl->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED); // Get selected item.
	if (selected_item == -1)
	{
		wxLogDebug("Warning: No patient selected in PatientListUIPanel::getSelectedPatient(). Returning nullptr.");
		return nullptr;
	}

	wxListItem* rowinfo = new wxListItem(); // Get patient ID of selected item.
	rowinfo->SetMask(wxLIST_MASK_TEXT);
	rowinfo->SetId(selected_item);
	rowinfo->SetColumn(0);
	patient_listctrl->GetItem(*rowinfo);
	std::string patient_id_string(rowinfo->GetText());
	delete(rowinfo);

	unsigned int patient_id = HelperFunctions::stoui(patient_id_string); // Convert ID to unsigned int.

	return getPatientByID(patient_id); // Return patient associated with that ID.
}

void PatientListUIPanel::addPatient(Patient* p)
{
	DatabaseFunctions::addPatientToDatabase(p);
	patient_list.push_back(p);
	addPatientToListCtrl(p);
}

void PatientListUIPanel::updatePatient()
{
	long selected_item = patient_listctrl->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED); // Get selected item.
	if (selected_item == -1)
	{
		wxLogDebug("Warning: No patient selected in PatientListUIPanel::updatePatient(). Cannot update patient.");
		return;
	}

	wxListItem* rowinfo = new wxListItem(); // Get patient ID of selected item.
	rowinfo->SetMask(wxLIST_MASK_TEXT);
	rowinfo->SetId(selected_item);
	rowinfo->SetColumn(0);
	patient_listctrl->GetItem(*rowinfo);
	std::string patient_id_string(rowinfo->GetText());
	delete(rowinfo);

	unsigned int patient_id = HelperFunctions::stoui(patient_id_string); // Convert ID to unsigned int.
	
	Patient* p = getPatientByID(patient_id); // Get the selected patient.

	// Replace old information with current information.
	std::string pname = p->getLastName() + ", " + p->getFirstName();
	std::string num_meds = std::to_string(p->getMedList()->size());
	std::string id_num = std::to_string(p->getUniqueID());
	patient_listctrl->SetItem(selected_item, 0, id_num);
	patient_listctrl->SetItem(selected_item, 1, pname);
	patient_listctrl->SetItem(selected_item, 2, p->getStreetAddr());
	patient_listctrl->SetItem(selected_item, 3, p->getZipCode());
	patient_listctrl->SetItem(selected_item, 4, p->getState());
	patient_listctrl->SetItem(selected_item, 5, p->getPhoneNum());
	patient_listctrl->SetItem(selected_item, 6, num_meds);
	resizeColumns();
}

void PatientListUIPanel::sortListByPatient(Patient* p)
{
	patient_listctrl->DeleteAllItems(); // Start with an empty list.

	for (int i = 0; i < patient_list.size(); i++) // Go through each patient to see if it should be included in the listctrl.
	{
		if (((p->getAge() == patient_list[i]->getAge()) || (p->getAge() == 0)) &&
			((p->getAgeUnit() == patient_list[i]->getAgeUnit()) || (p->getAgeUnit() == TimeUnitEnum::error)) &&
			((p->getFirstName() == patient_list[i]->getFirstName()) || (p->getFirstName() == "")) &&
			((p->getLastName() == patient_list[i]->getLastName()) || (p->getLastName() == "")) &&
			((p->getStreetAddr() == patient_list[i]->getStreetAddr()) || (p->getStreetAddr() == "")) &&
			((p->getCity() == patient_list[i]->getCity()) || (p->getCity() == "")) &&
			((p->getZipCode() == patient_list[i]->getZipCode()) || (p->getZipCode() == "")) &&
			((p->getPhoneNum() == patient_list[i]->getPhoneNum()) || (p->getPhoneNum() == "")) &&
			((p->getInsuranceName() == patient_list[i]->getInsuranceName()) || (p->getInsuranceName() == "")) &&
			((p->getPhoneType() == patient_list[i]->getPhoneType()) || (p->getPhoneType() == PhoneTypeEnum::error)) &&
			((p->getState() == patient_list[i]->getState()) || (p->getState() == "")))
		{
			addPatientToListCtrl(patient_list[i]);
		}
	}
}

void PatientListUIPanel::initPatientsFromDatabase()
{
	sql::Driver* driver = nullptr;
	sql::Connection* con = nullptr;
	sql::Statement* stmt = nullptr;
	sql::PreparedStatement* p_stmt = nullptr;
	sql::ResultSet* patient_res_tab = nullptr;
	sql::ResultSet* med_res_tab = nullptr;
	std::vector<Medication*>* m_list = nullptr;

	try 
	{
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
		con->setSchema("RxHelperDB");
		stmt = con->createStatement();
		p_stmt = con->prepareStatement("SELECT * FROM medication WHERE patient_id = ?");
		patient_res_tab = stmt->executeQuery("SELECT * FROM patient");

		// For each patient in the database.
		while (patient_res_tab->next())
		{
			// 1. Put patient information into approprate variables.
			unsigned int p_id = patient_res_tab->getUInt(1);
			unsigned short int p_age = patient_res_tab->getUInt(2);
			TimeUnitEnum p_age_unit = HelperFunctions::strtotue(patient_res_tab->getString(3).asStdString());
			std::string p_first_name = patient_res_tab->getString(4).asStdString();
			std::string p_last_name = patient_res_tab->getString(5).asStdString();
			std::string p_str_addr = patient_res_tab->getString(6).asStdString();
			std::string p_city = patient_res_tab->getString(7).asStdString();
			std::string p_zip_code = patient_res_tab->getString(8).asStdString();
			std::string p_state = patient_res_tab->getString(9).asStdString();
			std::string p_phone_num = patient_res_tab->getString(10).asStdString();
			PhoneTypeEnum p_phone_type = HelperFunctions::strtopte(patient_res_tab->getString(11).asStdString());
			std::string p_ins_name = patient_res_tab->getString(12).asStdString();

			// 2. Grab medications for that specific patient (based on the patient's ID) and put them into a vector of Medication object pointers.
			m_list = new std::vector<Medication*>();
			p_stmt->setUInt64(1, p_id);
			med_res_tab = p_stmt->executeQuery();
			while (med_res_tab->next())
			{
				unsigned int m_id = med_res_tab->getUInt(1);
				std::string m_drug_name = med_res_tab->getString(3).asStdString();
				std::string m_description = med_res_tab->getString(4).asStdString();
				unsigned int m_dosage = med_res_tab->getUInt(5);
				DoseUnitEnum m_dose_unit = HelperFunctions::strtodue(med_res_tab->getString(6).asStdString());
				unsigned int m_time_num = med_res_tab->getUInt(7);
				TimeUnitEnum m_time_unit = HelperFunctions::strtotue(med_res_tab->getString(8).asStdString());
				unsigned int m_price_dollars = med_res_tab->getUInt(9);
				unsigned int m_price_cents = med_res_tab->getUInt(10);

				Medication* new_m = new Medication(m_id, m_drug_name, m_description, m_dosage, m_dose_unit, m_time_num, m_time_unit, m_price_dollars, m_price_cents);
				m_list->push_back(new_m);
			}
			delete med_res_tab;
			med_res_tab = nullptr;

			// 3. Use both of the previous steps to create a Patient object.
			Patient* new_p = new Patient(p_id, p_age, p_age_unit, p_first_name, p_last_name, p_str_addr, p_city, p_zip_code, p_phone_num, p_ins_name, p_phone_type, p_state, m_list);
			delete m_list;
			m_list = nullptr;
			
			// 4. Add the Patient to patient_list.
			patient_list.push_back(new_p);
			
			// 5. Add the Patient to the listctrl with addPatientToListCtrl
			addPatientToListCtrl(new_p);
		}
	}
	catch (sql::SQLException& e) 
	{
		wxLogDebug(e.what());
		if (m_list != nullptr) delete m_list;
	}

	delete patient_res_tab;
	delete stmt;
	delete p_stmt;
	delete con;
	if (med_res_tab != nullptr) delete med_res_tab;
}

Patient* PatientListUIPanel::getPatientByID(unsigned int id)
{
	for (int i = 0; i < patient_list.size(); i++) 
	{
		if (patient_list[i]->getUniqueID() == id) return patient_list[i];
	}

	return nullptr;
}

void PatientListUIPanel::resizeColumns()
{
	if (patient_listctrl == nullptr)
	{
		wxLogDebug("Warning: Nullptr patient_listctrl in PatientListUIPanel::resizeColumns(). Cannot resize columns.");
		return;
	}

	patient_listctrl->SetColumnWidth(0, wxLIST_AUTOSIZE_USEHEADER);
	patient_listctrl->SetColumnWidth(1, wxLIST_AUTOSIZE_USEHEADER);
	patient_listctrl->SetColumnWidth(2, wxLIST_AUTOSIZE_USEHEADER);
	patient_listctrl->SetColumnWidth(3, wxLIST_AUTOSIZE_USEHEADER);
	patient_listctrl->SetColumnWidth(4, wxLIST_AUTOSIZE_USEHEADER);
	patient_listctrl->SetColumnWidth(5, wxLIST_AUTOSIZE_USEHEADER);
	patient_listctrl->SetColumnWidth(6, wxLIST_AUTOSIZE_USEHEADER);
}

void PatientListUIPanel::resizeColumnsEvt(wxSizeEvent& event)
{
	resizeColumns();
}

void PatientListUIPanel::addPatientToListCtrl(Patient* p)
{
	if (p == nullptr)
	{
		wxLogDebug("Warning: Nullptr in PatientListUIPanel::addPatientToListCtrl(). Cannot add patient to listctrl.");
		return;
	}

	std::string pname = p->getLastName() + ", " + p->getFirstName();
	std::string num_meds = std::to_string(p->getMedList()->size());
	std::string id_num = std::to_string(p->getUniqueID());
	int cur_index = patient_listctrl->GetItemCount();

	patient_listctrl->InsertItem(cur_index, id_num);
	patient_listctrl->SetItem(cur_index, 1, pname);
	patient_listctrl->SetItem(cur_index, 2, p->getStreetAddr());
	patient_listctrl->SetItem(cur_index, 3, p->getZipCode());
	patient_listctrl->SetItem(cur_index, 4, p->getState());
	patient_listctrl->SetItem(cur_index, 5, p->getPhoneNum());
	patient_listctrl->SetItem(cur_index, 6, num_meds);
	resizeColumns();
}

void PatientListUIPanel::removePatient(int index, int id)
{
	patient_listctrl->DeleteItem(index);
	for (int i = 0; i < patient_list.size(); i++)
	{
		if (patient_list[i]->getUniqueID() == id)
		{
			delete(patient_list[i]);
			patient_list.erase(patient_list.begin() + i);
		}
	}
}

void PatientListUIPanel::removePatientEvt(wxCommandEvent& event)
{
	long selected_item = patient_listctrl->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED); // Get selected item.
	if (selected_item == -1)
	{
		wxLogDebug("Warning: No patient selected in PatientListUIPanel::removePatientEvt(). Cannot remove patient.");
		return;
	}

	wxListItem* rowinfo = new wxListItem(); // Get patient ID of selected item.
	rowinfo->SetMask(wxLIST_MASK_TEXT);
	rowinfo->SetId(selected_item);
	rowinfo->SetColumn(0);
	patient_listctrl->GetItem(*rowinfo);
	std::string patient_id_string(rowinfo->GetText());
	delete(rowinfo);

	unsigned int patient_id = HelperFunctions::stoui(patient_id_string); // Convert ID to unsigned int.

	Patient* p = getPatientByID(patient_id); // Get the selected patient.

	removePatient(selected_item, p->getUniqueID()); // Remove patient from listctrl / list / database.
	DatabaseFunctions::removePatientFromDatabase(p->getUniqueID());

	event.Skip(true); // Pass event to the parent class.
}

void PatientListUIPanel::deletePatientList()
{
	for (int i = 0; i < patient_list.size(); i++) 
	{
		delete(patient_list[i]);
	}
	patient_list.clear();
}

PatientListUIPanel::~PatientListUIPanel()
{
	deletePatientList();
}