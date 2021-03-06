#include "PatientListBtnPanel.h"

PatientListBtnPanel::PatientListBtnPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, 2621440L, wxPanelNameStr)
{
	// Sizer for patient list buttons.
	wxBoxSizer* button_sizer = new wxBoxSizer(wxHORIZONTAL);
	button_sizer->Add
	(
		new wxButton(this, SAVEPATIENTBTN_ID, "Save Patient", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxButtonNameStr),
		wxSizerFlags(1).Expand().Border(wxALL, 5)
	);
	button_sizer->Add
	(
		new wxButton(this, ADDPATIENTBTN_ID, "Add Patient", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxButtonNameStr),
		wxSizerFlags(1).Expand().Border(wxALL, 5)
	);
	button_sizer->Add
	(
		new wxButton(this, REMOVEPATIENTBTN_ID, "Remove Patient", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxButtonNameStr),
		wxSizerFlags(1).Expand().Border(wxALL, 5)
	);

	SetSizer(button_sizer);
}

PatientListBtnPanel::~PatientListBtnPanel()
{

}