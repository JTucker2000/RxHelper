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
		wxSizerFlags().Expand().Border(wxALL, 5)
	);
	medication_listctrl = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
	pinfo_sizer->Add
	(
		medication_listctrl,
		wxSizerFlags(1).Expand().Border(wxALL, 5)
	);
	wxFont tempf = medication_listctrl->GetFont(); // Make listctrl font bigger.
	tempf.SetPointSize(12);
	medication_listctrl->SetFont(tempf);
	medication_listctrl->InsertColumn(0, "Drug Name"); // Add columns to listctrl.
	medication_listctrl->InsertColumn(1, "Dosage");
	medication_listctrl->InsertColumn(2, "Price");
	medication_listctrl->InsertColumn(3, "Description");

	medication_listctrl->InsertItem(0, "Advil"); // Insert example medication.
	medication_listctrl->SetItem(0, 1, "2 Pills every 6 hours");
	medication_listctrl->SetItem(0, 2, "$10.00");
	medication_listctrl->SetItem(0, 3, "A mild pain reliever");

	resizeColumns();

	medication_listctrl->Bind(wxEVT_SIZE, &PatientInfoUIPanel::resizeColumnsEvt, this); // Automatically resize columns.

	SetSizer(pinfo_sizer);
}

void PatientInfoUIPanel::resizeColumns()
{
	if (!medication_listctrl) return;
	medication_listctrl->SetColumnWidth(0, wxLIST_AUTOSIZE_USEHEADER);
	medication_listctrl->SetColumnWidth(1, wxLIST_AUTOSIZE_USEHEADER);
	medication_listctrl->SetColumnWidth(2, wxLIST_AUTOSIZE_USEHEADER);
	medication_listctrl->SetColumnWidth(3, wxLIST_AUTOSIZE_USEHEADER);
}

void PatientInfoUIPanel::resizeColumnsEvt(wxSizeEvent& event)
{
	resizeColumns();
}

PatientInfoUIPanel::~PatientInfoUIPanel()
{

}