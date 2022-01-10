#include "MainSearchUIPanel.h"

MainSearchUIPanel::MainSearchUIPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, 2621440L, wxPanelNameStr)
{
	wxStaticText* psearch_txt = new wxStaticText(this, wxID_ANY, "Patient Search", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr); // Create patient search static text.
	wxFont tempf = psearch_txt->GetFont(); // Make font bigger.
	tempf.SetPointSize(14);
	psearch_txt->SetFont(tempf);

	wxStaticText* search_info_txt = new wxStaticText(this, wxID_ANY, "Patients are filtered by all non empty boxes", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr); // Create search info static text.

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

	wxBoxSizer* phtype_sizer = new wxBoxSizer(wxHORIZONTAL); // Phone type sizer.
	wxStaticText* phtype_txt = new wxStaticText(this, wxID_ANY, "Type:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	phtype_txt->SetFont(tempf);
	wxArrayString* phtype_choices = new wxArrayString();
	phtype_choices->Add("Home");
	phtype_choices->Add("Mobile");
	phtype_choices->Add("Other");
	phtype_sizer->Add
	(
		phtype_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	phtype_sizer->Add
	(
		new wxComboBox(this, wxID_ANY, "Phone Type", wxDefaultPosition, wxDefaultSize, *phtype_choices, 0L, wxDefaultValidator, wxComboBoxNameStr),
		wxSizerFlags(3).Expand()
	);
	delete(phtype_choices);

	// Add last name, city, state, and phone type to right middle sizer.
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
		phtype_sizer,
		wxSizerFlags(1).Expand().Border(wxDOWN, 10)
	);

	wxBoxSizer* insname_sizer = new wxBoxSizer(wxHORIZONTAL); // Insurance name sizer.
	wxStaticText* insname_txt = new wxStaticText(this, wxID_ANY, "Ins. Name:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	insname_txt->SetFont(tempf);
	insname_sizer->Add
	(
		insname_txt,
		wxSizerFlags().Border(wxRIGHT, 10)
	);
	insname_sizer->Add
	(
		new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr),
		wxSizerFlags(5).Expand()
	);

	wxBoxSizer* search_button_sizer = new wxBoxSizer(wxHORIZONTAL); // Sizer for this panel's buttons.
	search_button_sizer->Add
	(
		new wxButton(this, wxID_ANY, "Apply Search", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxButtonNameStr),
		wxSizerFlags(1).Expand().Border(wxALL, 10)
	);
	search_button_sizer->Add
	(
		new wxButton(this, wxID_ANY, "Clear Search", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxButtonNameStr),
		wxSizerFlags(1).Expand().Border(wxALL, 10)
	);

	wxBoxSizer* main_search_sizer = new wxBoxSizer(wxVERTICAL); // Sizer for the main search panel.
	main_search_sizer->Add
	(
		psearch_txt,
		wxSizerFlags().Center().Border(wxLEFT | wxRIGHT | wxUP, 10)
	);
	main_search_sizer->Add
	(
		search_info_txt,
		wxSizerFlags().Center().Border(wxALL, 5)
	);
	main_search_sizer->Add
	(
		middle_sizer,
		wxSizerFlags().Center().Border(wxALL, 5)
	);
	main_search_sizer->Add
	(
		insname_sizer,
		wxSizerFlags().Expand().Border(wxLEFT | wxRIGHT | wxDOWN, 10)
	);
	main_search_sizer->Add
	(
		search_button_sizer,
		wxSizerFlags().Center()
	);

	SetSizer(main_search_sizer);
}

MainSearchUIPanel::~MainSearchUIPanel()
{

}