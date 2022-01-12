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
	medication_listctrl = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
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

	medication_listctrl->InsertItem(0, "1"); // Insert example medication.
	medication_listctrl->SetItem(0, 1, "Advil");
	medication_listctrl->SetItem(0, 2, "2 Pills every 6 hours");
	medication_listctrl->SetItem(0, 3, "$10.00");
	medication_listctrl->SetItem(0, 4, "A mild pain reliever");

	medication_listctrl->InsertItem(1, "2");
	medication_listctrl->SetItem(1, 1, "Pepto");
	medication_listctrl->SetItem(1, 2, "10 mL when needed");
	medication_listctrl->SetItem(1, 3, "$15.00");
	medication_listctrl->SetItem(1, 4, "Reduces nausea and heartburn");

	resizeColumns();

	medication_listctrl->Bind(wxEVT_SIZE, &PatientInfoUIPanel::resizeColumnsEvt, this); // Automatically resize columns.
	patient_info_middle->Bind(wxEVT_BUTTON, &PatientInfoUIPanel::removeMedicationEvt, this, REMOVEMEDICATIONBTN_ID); // Remove medication button click.

	SetSizer(pinfo_sizer);
}

void PatientInfoUIPanel::fillInfo(Patient* p)
{
	// Steps to create this function
	patient_info_top->clearPanel(); // 1. Clear Top Panel Info
	patient_info_middle->clearPanel(); // 2. Clear Middle Panel Info
	medication_listctrl->DeleteAllItems(); // 3. Clear Medication listctrl
	// 4. Fill information for Top panel and medication listctrl (Middle panel info not needed until user makes a selection)
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

void PatientInfoUIPanel::removeMedication(int index)
{
	medication_listctrl->DeleteItem(index);
}

void PatientInfoUIPanel::removeMedicationEvt(wxCommandEvent& event)
{
	long selected_item = medication_listctrl->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
	removeMedication(selected_item);
}

PatientInfoUIPanel::~PatientInfoUIPanel()
{

}