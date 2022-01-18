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

	// Patients and medications for UI testing.
	Medication* testmed1 = new Medication(1, "Advil", "Pain Reliever", 5, DoseUnitEnum::milligrams, 6, TimeUnitEnum::hours, 5, 0);
	Medication* testmed2 = new Medication(2, "Atorvastatin", "Reduces high cholesterol", 10, DoseUnitEnum::milligrams, 1, TimeUnitEnum::days, 20, 0);
	Medication* testmed3 = new Medication(3, "Pepto", "Relieves indigestion", 20, DoseUnitEnum::milliliters, 6, TimeUnitEnum::hours, 12, 0);
	Medication* testmed4 = new Medication(4, "Metformin", "Antidiabetic medication", 10, DoseUnitEnum::milligrams, 5, TimeUnitEnum::hours, 50, 0);
	Medication* testmed5 = new Medication(5, "Duloxetine", "Antidepressant medication", 15, DoseUnitEnum::milliliters, 30, TimeUnitEnum::minutes, 46, 50);
	Medication* testmed6 = new Medication(6, "Advil", "Pain Reliever", 10, DoseUnitEnum::milligrams, 3, TimeUnitEnum::hours, 5, 0);
	Medication* testmed7 = new Medication(7, "Atorvastatin", "Reduces high cholesterol", 20, DoseUnitEnum::milligrams, 1, TimeUnitEnum::days, 30, 0);
	Medication* testmed8 = new Medication(8, "Pepto", "Relieves indigestion", 20, DoseUnitEnum::milliliters, 6, TimeUnitEnum::hours, 12, 0);
	Medication* testmed9 = new Medication(9, "Metformin", "Antidiabetic medication", 10, DoseUnitEnum::milligrams, 5, TimeUnitEnum::hours, 50, 0);
	Medication* testmed10 = new Medication(10, "Duloxetine", "Antidepressant medication", 15, DoseUnitEnum::milliliters, 30, TimeUnitEnum::minutes, 55, 99);
	std::vector<Medication*> pmedlist;
	pmedlist.push_back(testmed1);
	pmedlist.push_back(testmed10);
	std::vector<Medication*> xmedlist;
	xmedlist.push_back(testmed2);
	xmedlist.push_back(testmed9);
	std::vector<Medication*> dmedlist;
	dmedlist.push_back(testmed3);
	dmedlist.push_back(testmed8);
	std::vector<Medication*> ymedlist;
	ymedlist.push_back(testmed4);
	ymedlist.push_back(testmed7);
	std::vector<Medication*> amedlist;
	amedlist.push_back(testmed5);
	amedlist.push_back(testmed6);
	Patient* p = new Patient(1, 21, TimeUnitEnum::years, "Jonathan", "Tucker", "5 Yeet Street", "Springfield", "65654", "777-777-7676", "Medicare", PhoneTypeEnum::Home, "MA", &pmedlist);
	Patient* x = new Patient(2, 54, TimeUnitEnum::years, "David", "Doe", "567 Washington Street", "Newton", "63290", "123-674-1649", "Blue Cross Blue Shield", PhoneTypeEnum::Mobile, "DE", &xmedlist);
	Patient* d = new Patient(3, 16, TimeUnitEnum::years, "Samantha", "Garth", "66 Rifton Road", "Jard", "12397", "926-548-5395", "None", PhoneTypeEnum::Mobile, "NH", &dmedlist);
	Patient* y = new Patient(4, 33, TimeUnitEnum::years, "Guy", "Harmouth", "5432 Temple Lane", "Marshfield", "59345", "124-862-1548", "Blue Cross Blue Shield", PhoneTypeEnum::Other, "OH", &ymedlist);
	Patient* a = new Patient(5, 42, TimeUnitEnum::years, "Julie", "Carlson", "4 Tennis Road", "Denham", "54823", "361-578-7835", "Cigna", PhoneTypeEnum::Mobile, "ME", &amedlist);
	patient_list.push_back(p);
	patient_list.push_back(x);
	patient_list.push_back(d);
	patient_list.push_back(y);
	patient_list.push_back(a);
	addPatientToList(patient_list[0]);
	addPatientToList(patient_list[1]);
	addPatientToList(patient_list[2]);
	addPatientToList(patient_list[3]);
	addPatientToList(patient_list[4]);
	// End of testing block.

	resizeColumns();

	patient_listctrl->Bind(wxEVT_SIZE, &PatientListUIPanel::resizeColumnsEvt, this); // Automatically resize columns.
	lc_btn_panel->Bind(wxEVT_BUTTON, &PatientListUIPanel::removePatientEvt, this, REMOVEPATIENTBTN_ID); // Remove patient button click.

	SetSizer(lc_sizer);
}

Patient* PatientListUIPanel::getSelectedPatient()
{
	long selected_item = patient_listctrl->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED); // Get selected item.
	if (selected_item == -1) return nullptr;

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
	if (!patient_listctrl) return;
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

void PatientListUIPanel::addPatientToList(Patient* p)
{
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

void PatientListUIPanel::removePatient(int index)
{
	patient_listctrl->DeleteItem(index);
}

void PatientListUIPanel::removePatientEvt(wxCommandEvent& event)
{
	long selected_item = patient_listctrl->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
	removePatient(selected_item);
	event.Skip(true);
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