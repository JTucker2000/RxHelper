#include "PatientInfoMiddlePanel.h"

PatientInfoMiddlePanel::PatientInfoMiddlePanel(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, 2621440L, wxPanelNameStr)
{
	wxStaticText* minfo_txt = new wxStaticText(this, wxID_ANY, "Medication Info", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr); // Create medication info static text.
	wxFont tempf = minfo_txt->GetFont(); // Make font bigger.
	tempf.SetPointSize(14);
	minfo_txt->SetFont(tempf);

	wxBoxSizer* middle_sizer = new wxBoxSizer(wxHORIZONTAL); // Sizer for the middle of this panel.
	wxBoxSizer* left_middle_sizer = new wxBoxSizer(wxVERTICAL); // Sizer for left side of middle.
	wxBoxSizer* right_middle_sizer = new wxBoxSizer(wxVERTICAL); // Sizer for right side of middle.
	middle_sizer->Add
	(
		left_middle_sizer,
		wxSizerFlags(1).Expand()
	);
	middle_sizer->Add
	(
		right_middle_sizer,
		wxSizerFlags(1).Expand()
	);

	wxBoxSizer* dname_sizer = new wxBoxSizer(wxHORIZONTAL); // Drug name sizer.
	wxStaticText* dname_txt = new wxStaticText(this, wxID_ANY, "Drug Name:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	dname_txt->SetFont(tempf);
	dname_sizer->Add
	(
		dname_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	dname_sizer->Add
	(
		new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr),
		wxSizerFlags(3).Expand()
	);

	wxBoxSizer* dosage_sizer = new wxBoxSizer(wxHORIZONTAL); // Dosage sizer.
	wxStaticText* dosage_txt = new wxStaticText(this, wxID_ANY, "Dosage:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	dosage_txt->SetFont(tempf);
	dosage_sizer->Add
	(
		dosage_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	dosage_sizer->Add
	(
		new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr),
		wxSizerFlags(3).Expand()
	);

	wxBoxSizer* tnum_sizer = new wxBoxSizer(wxHORIZONTAL); // Time number sizer.
	wxStaticText* tnum_txt = new wxStaticText(this, wxID_ANY, "Frequency:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	tnum_txt->SetFont(tempf);
	tnum_sizer->Add
	(
		tnum_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	tnum_sizer->Add
	(
		new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr),
		wxSizerFlags(3).Expand()
	);

	// Add drug name, dosage, and time number to left middle sizer.
	left_middle_sizer->Add
	(
		dname_sizer,
		wxSizerFlags(1).Expand().Border(wxRIGHT | wxDOWN, 10)
	);
	left_middle_sizer->Add
	(
		dosage_sizer,
		wxSizerFlags(1).Expand().Border(wxRIGHT | wxDOWN, 10)
	);
	left_middle_sizer->Add
	(
		tnum_sizer,
		wxSizerFlags(1).Expand().Border(wxRIGHT | wxDOWN, 10)
	);

	wxBoxSizer* price_sizer = new wxBoxSizer(wxHORIZONTAL); // Price sizer.
	wxStaticText* price_txt = new wxStaticText(this, wxID_ANY, "Price:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	price_txt->SetFont(tempf);
	price_sizer->Add
	(
		price_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	price_sizer->Add
	(
		new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr),
		wxSizerFlags(3).Expand()
	);

	wxBoxSizer* dunit_sizer = new wxBoxSizer(wxHORIZONTAL); // Dosage unit sizer.
	wxStaticText* dunit_txt = new wxStaticText(this, wxID_ANY, "Dose Unit:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	dunit_txt->SetFont(tempf);
	dunit_sizer->Add
	(
		dunit_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	dunit_sizer->Add
	(
		new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr),
		wxSizerFlags(3).Expand()
	);

	wxBoxSizer* tunit_sizer = new wxBoxSizer(wxHORIZONTAL); // Time unit sizer.
	wxStaticText* tunit_txt = new wxStaticText(this, wxID_ANY, "Time Unit:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	tunit_txt->SetFont(tempf);
	tunit_sizer->Add
	(
		tunit_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	tunit_sizer->Add
	(
		new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr),
		wxSizerFlags(3).Expand()
	);

	// Add price, dosage unit, and time unit to right middle sizer.
	right_middle_sizer->Add
	(
		price_sizer,
		wxSizerFlags(1).Expand().Border(wxDOWN, 10)
	);
	right_middle_sizer->Add
	(
		dunit_sizer,
		wxSizerFlags(1).Expand().Border(wxDOWN, 10)
	);
	right_middle_sizer->Add
	(
		tunit_sizer,
		wxSizerFlags(1).Expand().Border(wxDOWN, 10)
	);

	wxBoxSizer* desc_sizer = new wxBoxSizer(wxHORIZONTAL); // Description sizer.
	wxStaticText* desc_txt = new wxStaticText(this, wxID_ANY, "Description:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	desc_txt->SetFont(tempf);
	desc_sizer->Add
	(
		desc_txt,
		wxSizerFlags().Border(wxRIGHT, 10)
	);
	desc_sizer->Add
	(
		new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr),
		wxSizerFlags(5).Expand()
	);

	wxBoxSizer* med_button_sizer = new wxBoxSizer(wxHORIZONTAL); // Sizer for this panel's buttons.
	med_button_sizer->Add
	(
		new wxButton(this, wxID_ANY, "View Medication", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxButtonNameStr),
		wxSizerFlags(1).Expand().Border(wxRIGHT | wxUP | wxDOWN, 5)
	);
	med_button_sizer->Add
	(
		new wxButton(this, wxID_ANY, "Save Medication", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxButtonNameStr),
		wxSizerFlags(1).Expand().Border(wxALL, 5)
	);
	med_button_sizer->Add
	(
		new wxButton(this, wxID_ANY, "Add Medication", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxButtonNameStr),
		wxSizerFlags(1).Expand().Border(wxALL, 5)
	);
	med_button_sizer->Add
	(
		new wxButton(this, wxID_ANY, "Remove Medication", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxButtonNameStr),
		wxSizerFlags(1).Expand().Border(wxLEFT | wxUP | wxDOWN, 5)
	);

	wxBoxSizer* top_sizer = new wxBoxSizer(wxVERTICAL); // Main sizer for this panel.
	top_sizer->Add
	(
		minfo_txt,
		wxSizerFlags().Center().Border(wxALL, 5)
	);
	top_sizer->Add
	(
		middle_sizer,
		wxSizerFlags().Center().Border(wxALL, 5)
	);
	top_sizer->Add
	(
		desc_sizer,
		wxSizerFlags().Expand().Border(wxLEFT | wxRIGHT | wxDOWN, 10)
	);
	top_sizer->Add
	(
		med_button_sizer,
		wxSizerFlags().Expand()
	);

	SetSizer(top_sizer);
}

PatientInfoMiddlePanel::~PatientInfoMiddlePanel()
{

}