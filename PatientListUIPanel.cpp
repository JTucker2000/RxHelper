#include "PatientListUIPanel.h"

PatientListUIPanel::PatientListUIPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, 2621440L, wxPanelNameStr)
{
	// Sizer for listctrl and its buttons.
	wxBoxSizer* lc_sizer = new wxBoxSizer(wxVERTICAL);
	lc_sizer->Add
	(
		new PatientListBtnPanel(this),
		wxSizerFlags(1).Expand()
	);
	patient_listctrl = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
	lc_sizer->Add
	(
		patient_listctrl,
		wxSizerFlags(8).Expand().Border(wxLEFT | wxRIGHT | wxDOWN, 5)
	);
	wxFont tempf = patient_listctrl->GetFont(); // Make listctrl font bigger.
	tempf.SetPointSize(12);
	patient_listctrl->SetFont(tempf);
	patient_listctrl->InsertColumn(0, "Name"); // Add columns to listctrl.
	patient_listctrl->InsertColumn(1, "Address");
	patient_listctrl->InsertColumn(2, "Zip");
	patient_listctrl->InsertColumn(3, "State");
	patient_listctrl->InsertColumn(4, "Phone");
	patient_listctrl->InsertColumn(5, "# of Medications");

	patient_listctrl->InsertItem(0, "Tucker, Jonathan"); // Add dummy patient for now.
	patient_listctrl->SetItem(0, 1, "123 Monopoly Road");
	patient_listctrl->SetItem(0, 2, "12345");
	patient_listctrl->SetItem(0, 3, "ME");
	patient_listctrl->SetItem(0, 4, "123-456-7890");
	patient_listctrl->SetItem(0, 5, "2");

	patient_listctrl->SetColumnWidth(0, wxLIST_AUTOSIZE_USEHEADER); // Resize columns
	patient_listctrl->SetColumnWidth(1, wxLIST_AUTOSIZE_USEHEADER);
	patient_listctrl->SetColumnWidth(2, wxLIST_AUTOSIZE_USEHEADER);
	patient_listctrl->SetColumnWidth(3, wxLIST_AUTOSIZE_USEHEADER);
	patient_listctrl->SetColumnWidth(4, wxLIST_AUTOSIZE_USEHEADER);
	patient_listctrl->SetColumnWidth(5, wxLIST_AUTOSIZE_USEHEADER);

	patient_listctrl->Bind(wxEVT_SIZE, &PatientListUIPanel::resizeColumns, this); // Automatically resize columns.

	SetSizer(lc_sizer);
}

void PatientListUIPanel::resizeColumns(wxSizeEvent& event)
{
	if (!patient_listctrl) return;
	patient_listctrl->SetColumnWidth(0, wxLIST_AUTOSIZE_USEHEADER);
	patient_listctrl->SetColumnWidth(1, wxLIST_AUTOSIZE_USEHEADER);
	patient_listctrl->SetColumnWidth(2, wxLIST_AUTOSIZE_USEHEADER);
	patient_listctrl->SetColumnWidth(3, wxLIST_AUTOSIZE_USEHEADER);
	patient_listctrl->SetColumnWidth(4, wxLIST_AUTOSIZE_USEHEADER);
	patient_listctrl->SetColumnWidth(5, wxLIST_AUTOSIZE_USEHEADER);
}

PatientListUIPanel::~PatientListUIPanel()
{
	
}