#include "PatientListUIPanel.h"

PatientListUIPanel::PatientListUIPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, 2621440L, wxPanelNameStr)
{
	// Sizer for listbox and its buttons.
	wxBoxSizer* lb_sizer = new wxBoxSizer(wxVERTICAL);
	lb_sizer->Add
	(
		new PatientListBtnPanel(this),
		wxSizerFlags(1).Expand()
	);
	patient_listbox = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
	lb_sizer->Add
	(
		patient_listbox,
		wxSizerFlags(8).Expand().Border(wxLEFT | wxRIGHT | wxDOWN, 5)
	);
	wxFont tempf = patient_listbox->GetFont(); // Make listbox font bigger.
	tempf.SetPointSize(15);
	patient_listbox->SetFont(tempf);

	SetSizer(lb_sizer);
}

PatientListUIPanel::~PatientListUIPanel()
{
	
}