#include "PatientInfoUIPanel.h"

PatientInfoUIPanel::PatientInfoUIPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, 2621440L, wxPanelNameStr)
{
	wxBoxSizer* pinfo_sizer = new wxBoxSizer(wxVERTICAL); // Sizer for the patient info panel.
	patient_info_top = new PatientInfoTopPanel(this);
	pinfo_sizer->Add
	(
		patient_info_top,
		wxSizerFlags(1).Expand().Border(wxALL, 5)
	);
	patient_info_middle = new PatientInfoMiddlePanel(this);
	pinfo_sizer->Add
	(
		patient_info_middle,
		wxSizerFlags().Expand().Border(wxLEFT | wxRIGHT | wxUP, 5)
	);
	medication_listctrl = new wxListCtrl(this, MEDICATIONLISTCTRL_ID, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
	pinfo_sizer->Add
	(
		medication_listctrl,
		wxSizerFlags(2).Expand().Border(wxLEFT | wxRIGHT | wxDOWN, 5)
	);
	wxFont tempf = medication_listctrl->GetFont(); // Make listctrl font bigger.
	tempf.SetPointSize(12);
	medication_listctrl->SetFont(tempf);
	medication_listctrl->InsertColumn(0, "ID Number"); // Add columns to listctrl.
	medication_listctrl->InsertColumn(1, "Drug Name"); 
	medication_listctrl->InsertColumn(2, "Dosage");
	medication_listctrl->InsertColumn(3, "Price");
	medication_listctrl->InsertColumn(4, "Description");

	resizeColumns();

	medication_listctrl->Bind(wxEVT_SIZE, &PatientInfoUIPanel::resizeColumnsEvt, this); // Automatically resize columns.
	patient_info_middle->Bind(wxEVT_BUTTON, &PatientInfoUIPanel::removeMedicationEvt, this, REMOVEMEDICATIONBTN_ID); // Remove medication button click.
	Bind(wxEVT_LIST_ITEM_SELECTED, &PatientInfoUIPanel::medicationListctrlItemSelect, this, MEDICATIONLISTCTRL_ID); // Medication listctrl item select.

	SetSizer(pinfo_sizer);
}

void PatientInfoUIPanel::fillPatientInfo(Patient* p)
{
	if (p == nullptr) return;
	cur_patient = p;
	clearPanel();
	patient_info_top->fillPanel(p);
	fillListFromPatient(p);
}

void PatientInfoUIPanel::clearPanel()
{
	patient_info_top->clearPanel();
	patient_info_middle->clearPanel();
	medication_listctrl->DeleteAllItems();
}

void PatientInfoUIPanel::resizeColumns()
{
	if (!medication_listctrl) return;
	medication_listctrl->SetColumnWidth(0, wxLIST_AUTOSIZE_USEHEADER);
	medication_listctrl->SetColumnWidth(1, wxLIST_AUTOSIZE_USEHEADER);
	medication_listctrl->SetColumnWidth(2, wxLIST_AUTOSIZE_USEHEADER);
	medication_listctrl->SetColumnWidth(3, wxLIST_AUTOSIZE_USEHEADER);
	medication_listctrl->SetColumnWidth(4, wxLIST_AUTOSIZE_USEHEADER);
}

void PatientInfoUIPanel::resizeColumnsEvt(wxSizeEvent& event)
{
	resizeColumns();
}

void PatientInfoUIPanel::addMedicationToList(Medication* m)
{
	if (m == nullptr) return;

	std::string doseage_unit_str = HelperFunctions::duetostr(m->getDosageUnit());
	std::string time_unit_str = HelperFunctions::tuetostr(m->getTimeUnit());
	std::string dosage_str = std::to_string(m->getDosage()) + " " + doseage_unit_str + " every " + std::to_string(m->getTimeNum()) + " " + time_unit_str;
	std::string id_num = std::to_string(m->getUniqueID());
	int cur_index = medication_listctrl->GetItemCount();

	medication_listctrl->InsertItem(cur_index, id_num);
	medication_listctrl->SetItem(cur_index, 1, m->getDrugName());
	medication_listctrl->SetItem(cur_index, 2, dosage_str);
	medication_listctrl->SetItem(cur_index, 3, HelperFunctions::pricetostr(m->getPriceDollars(), m->getPriceCents()));
	medication_listctrl->SetItem(cur_index, 4, m->getDescription());
	resizeColumns();
}

void PatientInfoUIPanel::addMedicationToDatabase(Medication* m)
{
	if (m == nullptr) return;

	sql::Driver* driver = nullptr;
	sql::Connection* con = nullptr;
	sql::PreparedStatement* p_stmt = nullptr;

	try
	{
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
		con->setSchema("RxHelperDB");
		p_stmt = con->prepareStatement("INSERT INTO medication(patient_id, drug_name, description, dosage, dosage_unit, time_num, time_unit, price_dollars, price_cents) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?);");

		p_stmt->setUInt64(1, cur_patient->getUniqueID());
		p_stmt->setString(2, m->getDrugName());
		p_stmt->setString(3, m->getDescription());
		p_stmt->setUInt(4, m->getDosage());
		p_stmt->setString(5, HelperFunctions::duetostr(m->getDosageUnit()));
		p_stmt->setUInt(6, m->getTimeNum());
		p_stmt->setString(7, HelperFunctions::tuetostr(m->getTimeUnit()));
		p_stmt->setUInt(8, m->getPriceDollars());
		p_stmt->setUInt(9, m->getPriceCents());

		delete(p_stmt->executeQuery()); 
	}
	catch (sql::SQLException& e)
	{
		wxLogDebug(e.what());
	}

	delete con;
	delete p_stmt;
}

void PatientInfoUIPanel::fillListFromPatient(Patient* p)
{
	if (p == nullptr) return;
	std::vector<Medication*>* med_list_pointer = p->getMedList();
	if (med_list_pointer == nullptr) return;

	for (int i = 0; i < med_list_pointer->size(); i++)
	{
		addMedicationToList(med_list_pointer->at(i));
	}
}

void PatientInfoUIPanel::removeMedication(int index)
{
	if (medication_listctrl->DeleteItem(index)) 
	{
		patient_info_middle->clearPanel();
	}
}

void PatientInfoUIPanel::removeMedicationEvt(wxCommandEvent& event)
{
	long selected_item = medication_listctrl->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
	removeMedication(selected_item);
}

void PatientInfoUIPanel::medicationListctrlItemSelect(wxCommandEvent& event)
{
	Medication* selected_medication = getSelectedMedication(); // Get a pointer to the currently selected medication.
	if (selected_medication == nullptr) { return; }

	patient_info_middle->clearPanel(); // Fill medication info UI with medication information.
	patient_info_middle->fillMedicationInfo(selected_medication);
}

Medication* PatientInfoUIPanel::getSelectedMedication()
{
	long selected_item = medication_listctrl->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED); // Get selected item.
	if (selected_item == -1) return nullptr;

	wxListItem* rowinfo = new wxListItem(); // Get medication ID of selected item.
	rowinfo->SetMask(wxLIST_MASK_TEXT);
	rowinfo->SetId(selected_item);
	rowinfo->SetColumn(0);
	medication_listctrl->GetItem(*rowinfo);
	std::string medication_id_string(rowinfo->GetText());
	delete(rowinfo);

	unsigned int medication_id = HelperFunctions::stoui(medication_id_string); // Convert ID to unsigned int.

	return getMedicationByID(medication_id); // Return medication associated with that ID.
}

Medication* PatientInfoUIPanel::getMedicationByID(unsigned int id)
{
	if (cur_patient == nullptr) return nullptr;

	for (int i = 0; i < cur_patient->getMedList()->size(); i++)
	{
		if (cur_patient->getMedList()->at(i)->getUniqueID() == id) return cur_patient->getMedList()->at(i);
	}

	return nullptr;
}

PatientInfoUIPanel::~PatientInfoUIPanel()
{

}