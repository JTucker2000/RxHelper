#include "PatientInfoTopPanel.h"

PatientInfoTopPanel::PatientInfoTopPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, 2621440L, wxPanelNameStr)
{
	wxStaticText* pinfo_txt = new wxStaticText(this, wxID_ANY, "Patient Info", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr); // Create patient info static text.
	wxFont tempf = pinfo_txt->GetFont(); // Make font bigger.
	tempf.SetPointSize(14);
	pinfo_txt->SetFont(tempf);

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

	wxBoxSizer* fname_sizer = new wxBoxSizer(wxHORIZONTAL); // First name sizer.
	wxStaticText* fname_txt = new wxStaticText(this, wxID_ANY, "First Name:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	fname_txt->SetFont(tempf);
	fname_sizer->Add
	(
		fname_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	fname_sizer->Add
	(
		new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr),
		wxSizerFlags(3).Expand()
	);

	wxBoxSizer* addr_sizer = new wxBoxSizer(wxHORIZONTAL); // Address sizer.
	wxStaticText* addr_txt = new wxStaticText(this, wxID_ANY, "Street Addr:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	addr_txt->SetFont(tempf);
	addr_sizer->Add
	(
		addr_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	addr_sizer->Add
	(
		new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr),
		wxSizerFlags(3).Expand()
	);

	wxBoxSizer* zip_sizer = new wxBoxSizer(wxHORIZONTAL); // Zipcode sizer.
	wxStaticText* zip_txt = new wxStaticText(this, wxID_ANY, "Zip Code:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	zip_txt->SetFont(tempf);
	zip_sizer->Add
	(
		zip_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	zip_sizer->Add
	(
		new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr),
		wxSizerFlags(3).Expand()
	);

	wxBoxSizer* phnum_sizer = new wxBoxSizer(wxHORIZONTAL); // Phone Number sizer.
	wxStaticText* phnum_txt = new wxStaticText(this, wxID_ANY, "Phone Num:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	phnum_txt->SetFont(tempf);
	phnum_sizer->Add
	(
		phnum_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	phnum_sizer->Add
	(
		new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr),
		wxSizerFlags(3).Expand()
	);

	// Add first name, street address, zip code, and phone number to left middle sizer.
	left_middle_sizer->Add
	(
		fname_sizer,
		wxSizerFlags(1).Expand().Border(wxRIGHT | wxDOWN, 10)
	);
	left_middle_sizer->Add
	(
		addr_sizer,
		wxSizerFlags(1).Expand().Border(wxRIGHT | wxDOWN, 10)
	);
	left_middle_sizer->Add
	(
		zip_sizer,
		wxSizerFlags(1).Expand().Border(wxRIGHT | wxDOWN, 10)
	);
	left_middle_sizer->Add
	(
		phnum_sizer,
		wxSizerFlags(1).Expand().Border(wxRIGHT | wxDOWN, 10)
	);

	wxBoxSizer* lname_sizer = new wxBoxSizer(wxHORIZONTAL); // Last name sizer.
	wxStaticText* lname_txt = new wxStaticText(this, wxID_ANY, "Last Name:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	lname_txt->SetFont(tempf);
	lname_sizer->Add
	(
		lname_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	lname_sizer->Add
	(
		new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr),
		wxSizerFlags(3).Expand()
	);

	wxBoxSizer* city_sizer = new wxBoxSizer(wxHORIZONTAL); // City sizer.
	wxStaticText* city_txt = new wxStaticText(this, wxID_ANY, "City:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	city_txt->SetFont(tempf);
	city_sizer->Add
	(
		city_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	city_sizer->Add
	(
		new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr),
		wxSizerFlags(3).Expand()
	);

	wxBoxSizer* state_sizer = new wxBoxSizer(wxHORIZONTAL); // State sizer.
	wxStaticText* state_txt = new wxStaticText(this, wxID_ANY, "State:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	state_txt->SetFont(tempf);
	state_sizer->Add
	(
		state_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	state_sizer->Add
	(
		new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr),
		wxSizerFlags(3).Expand()
	);

	wxBoxSizer* insname_sizer = new wxBoxSizer(wxHORIZONTAL); // Insurance name sizer.
	wxStaticText* insname_txt = new wxStaticText(this, wxID_ANY, "Ins. Name:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	insname_txt->SetFont(tempf);
	insname_sizer->Add
	(
		insname_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	insname_sizer->Add
	(
		new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr),
		wxSizerFlags(3).Expand()
	);

	// Add last name, city, state, and insurance name to right middle sizer.
	right_middle_sizer->Add
	(
		lname_sizer,
		wxSizerFlags(1).Expand().Border(wxDOWN, 10)
	);
	right_middle_sizer->Add
	(
		city_sizer,
		wxSizerFlags(1).Expand().Border(wxDOWN, 10)
	);
	right_middle_sizer->Add
	(
		state_sizer,
		wxSizerFlags(1).Expand().Border(wxDOWN, 10)
	);
	right_middle_sizer->Add
	(
		insname_sizer,
		wxSizerFlags(1).Expand().Border(wxDOWN, 10)
	);

	wxBoxSizer* top_sizer = new wxBoxSizer(wxVERTICAL); // Main sizer for this panel.
	top_sizer->Add
	(
		pinfo_txt,
		wxSizerFlags().Center().Border(wxALL, 5)
	);
	top_sizer->Add
	(
		middle_sizer,
		wxSizerFlags().Center().Border(wxALL, 5)
	);

	SetSizer(top_sizer);
}

PatientInfoTopPanel::~PatientInfoTopPanel()
{

}