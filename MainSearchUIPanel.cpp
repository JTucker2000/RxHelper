#include "MainSearchUIPanel.h"

MainSearchUIPanel::MainSearchUIPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, 2621440L, wxPanelNameStr)
{
	wxStaticText* psearch_txt = new wxStaticText(this, wxID_ANY, "Patient Search", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr); // Create patient search static text.
	wxFont tempf1 = psearch_txt->GetFont(); // Make font bigger.
	tempf1.SetPointSize(14);
	psearch_txt->SetFont(tempf1);

	wxFont tempf2 = tempf1; // Make slightly smaller font for textctrl and comboboxes.
	tempf2.SetPointSize(12);

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
	fname_txtctrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr);
	fname_txt->SetFont(tempf1);
	fname_txtctrl->SetFont(tempf2);
	fname_sizer->Add
	(
		fname_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	fname_sizer->Add
	(
		fname_txtctrl,
		wxSizerFlags(3).Expand()
	);

	wxBoxSizer* age_sizer = new wxBoxSizer(wxHORIZONTAL); // Age sizer.
	wxStaticText* age_txt = new wxStaticText(this, wxID_ANY, "Age:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	age_txtctrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr);
	age_txt->SetFont(tempf1);
	age_txtctrl->SetFont(tempf2);
	age_sizer->Add
	(
		age_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	age_sizer->Add
	(
		age_txtctrl,
		wxSizerFlags(3).Expand()
	);

	wxBoxSizer* addr_sizer = new wxBoxSizer(wxHORIZONTAL); // Address sizer.
	wxStaticText* addr_txt = new wxStaticText(this, wxID_ANY, "Street Addr:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	addr_txtctrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr);
	addr_txt->SetFont(tempf1);
	addr_txtctrl->SetFont(tempf2);
	addr_sizer->Add
	(
		addr_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	addr_sizer->Add
	(
		addr_txtctrl,
		wxSizerFlags(3).Expand()
	);

	wxBoxSizer* zip_sizer = new wxBoxSizer(wxHORIZONTAL); // Zipcode sizer.
	wxStaticText* zip_txt = new wxStaticText(this, wxID_ANY, "Zip Code:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	zip_txtctrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr);
	zip_txt->SetFont(tempf1);
	zip_txtctrl->SetFont(tempf2);
	zip_sizer->Add
	(
		zip_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	zip_sizer->Add
	(
		zip_txtctrl,
		wxSizerFlags(3).Expand()
	);

	wxBoxSizer* phnum_sizer = new wxBoxSizer(wxHORIZONTAL); // Phone Number sizer.
	wxStaticText* phnum_txt = new wxStaticText(this, wxID_ANY, "Phone Num:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	phnum_txtctrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr);
	phnum_txt->SetFont(tempf1);
	phnum_txtctrl->SetFont(tempf2);
	phnum_sizer->Add
	(
		phnum_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	phnum_sizer->Add
	(
		phnum_txtctrl,
		wxSizerFlags(3).Expand()
	);

	// Add first name, age, street address, zip code, and phone number to left middle sizer.
	left_middle_sizer->Add
	(
		fname_sizer,
		wxSizerFlags(1).Expand().Border(wxRIGHT | wxDOWN, 10)
	);
	left_middle_sizer->Add
	(
		age_sizer,
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
	lname_txtctrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr);
	lname_txt->SetFont(tempf1);
	lname_txtctrl->SetFont(tempf2);
	lname_sizer->Add
	(
		lname_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	lname_sizer->Add
	(
		lname_txtctrl,
		wxSizerFlags(3).Expand()
	);

	wxBoxSizer* age_unit_sizer = new wxBoxSizer(wxHORIZONTAL); // Age unit sizer.
	wxArrayString* aunit_choices = new wxArrayString();
	aunit_choices->Add("Years");
	aunit_choices->Add("Months");
	aunit_choices->Add("Weeks");
	aunit_choices->Add("Days");
	wxStaticText* age_unit_txt = new wxStaticText(this, wxID_ANY, "Time Unit:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	age_unit_cmbox = new wxComboBox(this, wxID_ANY, "Time Unit", wxDefaultPosition, wxDefaultSize, *aunit_choices, 0L, wxDefaultValidator, wxComboBoxNameStr);
	age_unit_txt->SetFont(tempf1);
	age_unit_cmbox->SetFont(tempf2);
	age_unit_sizer->Add
	(
		age_unit_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	age_unit_sizer->Add
	(
		age_unit_cmbox,
		wxSizerFlags(3).Expand()
	);
	delete(aunit_choices);

	wxBoxSizer* city_sizer = new wxBoxSizer(wxHORIZONTAL); // City sizer.
	wxStaticText* city_txt = new wxStaticText(this, wxID_ANY, "City:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	city_txtctrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr);
	city_txt->SetFont(tempf1);
	city_txtctrl->SetFont(tempf2);
	city_sizer->Add
	(
		city_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	city_sizer->Add
	(
		city_txtctrl,
		wxSizerFlags(3).Expand()
	);

	wxBoxSizer* state_sizer = new wxBoxSizer(wxHORIZONTAL); // State sizer.
	wxStaticText* state_txt = new wxStaticText(this, wxID_ANY, "State:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	state_txtctrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr);
	state_txt->SetFont(tempf1);
	state_txtctrl->SetFont(tempf2);
	state_sizer->Add
	(
		state_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	state_sizer->Add
	(
		state_txtctrl,
		wxSizerFlags(3).Expand()
	);

	wxBoxSizer* phtype_sizer = new wxBoxSizer(wxHORIZONTAL); // Phone type sizer.
	wxArrayString* phtype_choices = new wxArrayString();
	phtype_choices->Add("Home");
	phtype_choices->Add("Mobile");
	phtype_choices->Add("Other");
	phtype_cmbox = new wxComboBox(this, wxID_ANY, "Phone Type", wxDefaultPosition, wxDefaultSize, *phtype_choices, 0L, wxDefaultValidator, wxComboBoxNameStr);
	wxStaticText* phtype_txt = new wxStaticText(this, wxID_ANY, "Type:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	phtype_txt->SetFont(tempf1);
	phtype_cmbox->SetFont(tempf2);

	phtype_sizer->Add
	(
		phtype_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	phtype_sizer->Add
	(
		phtype_cmbox,
		wxSizerFlags(3).Expand()
	);
	delete(phtype_choices);

	// Add last name, age unit, city, state, and phone type to right middle sizer.
	right_middle_sizer->Add
	(
		lname_sizer,
		wxSizerFlags(1).Expand().Border(wxDOWN, 10)
	);
	right_middle_sizer->Add
	(
		age_unit_sizer,
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
	insname_txtctrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr);
	insname_txt->SetFont(tempf1);
	insname_txtctrl->SetFont(tempf2);
	insname_sizer->Add
	(
		insname_txt,
		wxSizerFlags().Border(wxRIGHT, 10)
	);
	insname_sizer->Add
	(
		insname_txtctrl,
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
		new wxButton(this, CLEARSEARCHBTN_ID, "Clear Search", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxButtonNameStr),
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

	Bind(wxEVT_BUTTON, &MainSearchUIPanel::clearSearch, this, CLEARSEARCHBTN_ID); // Handle main search UI events.

	SetSizer(main_search_sizer);
}

Patient* MainSearchUIPanel::createPatient()
{
	unsigned int p_age = HelperFunctions::stoui(age_txtctrl->GetValue().ToStdString());
	std::string p_fname = fname_txtctrl->GetValue().ToStdString();
	std::string p_lname = lname_txtctrl->GetValue().ToStdString();
	std::string p_addr = addr_txtctrl->GetValue().ToStdString();
	std::string p_city = city_txtctrl->GetValue().ToStdString();
	std::string p_zip = zip_txtctrl->GetValue().ToStdString();
	std::string p_phnum = phnum_txtctrl->GetValue().ToStdString();
	std::string p_insname = insname_txtctrl->GetValue().ToStdString();
	std::string p_state = state_txtctrl->GetValue().ToStdString();

	TimeUnitEnum p_ageunit;
	switch (age_unit_cmbox->GetCurrentSelection())
	{
	case -1:
		wxMessageBox("No time unit selected for added patient. Defaults to years.");
		p_ageunit = TimeUnitEnum::years;
		break;
	case 0:
		p_ageunit = TimeUnitEnum::years;
		break;
	case 1:
		p_ageunit = TimeUnitEnum::months;
		break;
	case 2:
		p_ageunit = TimeUnitEnum::weeks;
		break;
	case 3:
		p_ageunit = TimeUnitEnum::days;
		break;
	default:
		wxLogDebug("Error: Invalid TimeUnitEnum in createPatient() in PatientInfoTopPanel. Exiting.");
		exit(-1);
		break;
	}

	PhoneTypeEnum p_phtype;
	switch (phtype_cmbox->GetCurrentSelection())
	{
	case -1:
		wxMessageBox("No phone type selected for added patient. Defaults to mobile.");
		p_phtype = PhoneTypeEnum::Mobile;
		break;
	case 0:
		p_phtype = PhoneTypeEnum::Home;
		break;
	case 1:
		p_phtype = PhoneTypeEnum::Mobile;
		break;
	case 2:
		p_phtype = PhoneTypeEnum::Other;
		break;
	default:
		wxLogDebug("Error: Invalid PhoneTypeEnum in createPatient() in PatientInfoTopPanel. Exiting.");
		exit(-1);
		break;
	}

	return new Patient(0, p_age, p_ageunit, p_fname, p_lname, p_addr, p_city, p_zip, p_phnum, p_insname, p_phtype, p_state, {});
}

void MainSearchUIPanel::clearSearch(wxCommandEvent& event)
{
	fname_txtctrl->Clear();
	age_txtctrl->Clear();
	addr_txtctrl->Clear();
	zip_txtctrl->Clear();
	phnum_txtctrl->Clear();
	lname_txtctrl->Clear();
	city_txtctrl->Clear();
	state_txtctrl->Clear();
	insname_txtctrl->Clear();
	phtype_cmbox->SetSelection(wxNOT_FOUND);
	phtype_cmbox->SetLabelText("Phone Type");
	age_unit_cmbox->SetSelection(wxNOT_FOUND);
	age_unit_cmbox->SetLabelText("Time Unit");
}

MainSearchUIPanel::~MainSearchUIPanel()
{

}