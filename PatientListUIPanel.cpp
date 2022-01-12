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
	patient_listctrl = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
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

	Patient* p = new Patient(1, "Jonathan", "Tucker", "5 Yeet Street", "Springfield", "65654", "777-777-7676", "Medicare", PhoneTypeEnum::Home, "MA", {}); // Add dummy patient for now.
	Patient* x = new Patient(2, "John", "Doe", "5 Yeet Street", "Springfield", "65654", "777-777-7676", "Medicare", PhoneTypeEnum::Home, "MA", {});
	addPatient(p);
	addPatient(x);
	delete(p);
	delete(x);

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

	wxMessageBox(patient_id_string); // Output ID for testing for now.

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

void PatientListUIPanel::addPatient(Patient* p) 
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
}

PatientListUIPanel::~PatientListUIPanel()
{
	
}