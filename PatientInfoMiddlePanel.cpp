#include "PatientInfoMiddlePanel.h"

PatientInfoMiddlePanel::PatientInfoMiddlePanel(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, 2621440L, wxPanelNameStr)
{
	wxStaticText* minfo_txt = new wxStaticText(this, wxID_ANY, "Medication Info", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr); // Create medication info static text.
	wxFont tempf1 = minfo_txt->GetFont(); // Make font bigger.
	tempf1.SetPointSize(14);
	minfo_txt->SetFont(tempf1);

	wxFont tempf2 = tempf1; // Make slightly smaller font for textctrl and comboboxes.
	tempf2.SetPointSize(12);

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
	dname_txtctrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr);
	dname_txt->SetFont(tempf1);
	dname_txtctrl->SetFont(tempf2);
	dname_sizer->Add
	(
		dname_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	dname_sizer->Add
	(
		dname_txtctrl,
		wxSizerFlags(3).Expand()
	);

	wxBoxSizer* dosage_sizer = new wxBoxSizer(wxHORIZONTAL); // Dosage sizer.
	wxStaticText* dosage_txt = new wxStaticText(this, wxID_ANY, "Dosage:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	dosage_txtctrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr);
	dosage_txt->SetFont(tempf1);
	dosage_txtctrl->SetFont(tempf2);
	dosage_sizer->Add
	(
		dosage_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	dosage_sizer->Add
	(
		dosage_txtctrl,
		wxSizerFlags(3).Expand()
	);

	wxBoxSizer* tnum_sizer = new wxBoxSizer(wxHORIZONTAL); // Time number sizer.
	wxStaticText* tnum_txt = new wxStaticText(this, wxID_ANY, "Taken every:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	tnum_txtctrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr);
	tnum_txt->SetFont(tempf1);
	tnum_txtctrl->SetFont(tempf2);
	tnum_sizer->Add
	(
		tnum_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	tnum_sizer->Add
	(
		tnum_txtctrl,
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
	price_txtctrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr);
	price_txt->SetFont(tempf1);
	price_txtctrl->SetFont(tempf2);
	price_sizer->Add
	(
		price_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	price_sizer->Add
	(
		price_txtctrl,
		wxSizerFlags(3).Expand()
	);

	wxBoxSizer* dunit_sizer = new wxBoxSizer(wxHORIZONTAL); // Dosage unit sizer.
	wxStaticText* dunit_txt = new wxStaticText(this, wxID_ANY, "Dose Unit:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	dunit_txt->SetFont(tempf1);
	wxArrayString* dunit_choices = new wxArrayString();
	dunit_choices->Add("Milligrams");
	dunit_choices->Add("Milliliters");
	dunit_cmbox = new wxComboBox(this, wxID_ANY, "Dose Unit", wxDefaultPosition, wxDefaultSize, *dunit_choices, 0L, wxDefaultValidator, wxComboBoxNameStr);
	dunit_cmbox->SetFont(tempf2);

	dunit_sizer->Add
	(
		dunit_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	dunit_sizer->Add
	(
		dunit_cmbox,
		wxSizerFlags(3).Expand()
	);
	delete(dunit_choices);

	wxBoxSizer* tunit_sizer = new wxBoxSizer(wxHORIZONTAL); // Time unit sizer.
	wxStaticText* tunit_txt = new wxStaticText(this, wxID_ANY, "Time Unit:", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr);
	tunit_txt->SetFont(tempf1);
	wxArrayString* tunit_choices = new wxArrayString();
	tunit_choices->Add("Minutes");
	tunit_choices->Add("Hours");
	tunit_choices->Add("Days");
	tunit_cmbox = new wxComboBox(this, wxID_ANY, "Time Unit", wxDefaultPosition, wxDefaultSize, *tunit_choices, 0L, wxDefaultValidator, wxComboBoxNameStr);
	tunit_cmbox->SetFont(tempf2);

	tunit_sizer->Add
	(
		tunit_txt,
		wxSizerFlags(1).Border(wxRIGHT, 5)
	);
	tunit_sizer->Add
	(
		tunit_cmbox,
		wxSizerFlags(3).Expand()
	);
	delete(tunit_choices);

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
	desc_txtctrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxTextCtrlNameStr);
	desc_txt->SetFont(tempf1);
	desc_txtctrl->SetFont(tempf2);
	desc_sizer->Add
	(
		desc_txt,
		wxSizerFlags().Border(wxRIGHT, 10)
	);
	desc_sizer->Add
	(
		desc_txtctrl,
		wxSizerFlags(5).Expand()
	);

	wxBoxSizer* med_button_sizer = new wxBoxSizer(wxHORIZONTAL); // Sizer for this panel's buttons.
	med_button_sizer->Add
	(
		new wxButton(this, SAVEMEDICATIONBTN_ID, "Save Medication", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxButtonNameStr),
		wxSizerFlags(1).Expand().Border(wxRIGHT | wxUP | wxDOWN, 5)
	);
	med_button_sizer->Add
	(
		new wxButton(this, ADDMEDICATIONBTN_ID, "Add Medication", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxButtonNameStr),
		wxSizerFlags(1).Expand().Border(wxALL, 5)
	);
	med_button_sizer->Add
	(
		new wxButton(this, REMOVEMEDICATIONBTN_ID, "Remove Medication", wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, wxButtonNameStr),
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

Medication* PatientInfoMiddlePanel::createMedication()
{
	std::string m_name = dname_txtctrl->GetValue().ToStdString();
	std::string m_desc = desc_txtctrl->GetValue().ToStdString();
	unsigned int m_price = HelperFunctions::strtoprice(price_txtctrl->GetValue().ToStdString());
	unsigned int m_price_dollars = m_price / 100;
	unsigned int m_price_cents = m_price % 100;
	unsigned int m_dosage = HelperFunctions::stoui(dosage_txtctrl->GetValue().ToStdString());
	unsigned int m_tnum = HelperFunctions::stoui(tnum_txtctrl->GetValue().ToStdString());

	DoseUnitEnum m_dunit;
	switch (dunit_cmbox->GetCurrentSelection())
	{
	case -1:
		wxMessageBox("No dose unit selected for added medication. Defaults to milligrams.");
		m_dunit = DoseUnitEnum::milligrams;
		break;
	case 0:
		m_dunit = DoseUnitEnum::milligrams;
		break;
	case 1:
		m_dunit = DoseUnitEnum::milliliters;
		break;
	default:
		std::cout << "Error, invalid DoseUnitEnum in createMedication() in PatientInfoMiddlePanel. Exiting." << std::endl;
		exit(-1);
		break;
	}

	TimeUnitEnum m_tunit;
	switch (tunit_cmbox->GetCurrentSelection())
	{
	case -1:
		wxMessageBox("No time unit selected for added medication. Defaults to hours.");
		m_tunit = TimeUnitEnum::hours;
		break;
	case 0:
		m_tunit = TimeUnitEnum::minutes;
		break;
	case 1:
		m_tunit = TimeUnitEnum::hours;
		break;
	case 2:
		m_tunit = TimeUnitEnum::days;
		break;
	default:
		std::cout << "Error, invalid TimeUnitEnum in createMedication() in PatientInfoMiddlePanel. Exiting." << std::endl;
		exit(-1);
		break;
	}

	return new Medication(0, m_name, m_desc, m_dosage, m_dunit, m_tnum, m_tunit, m_price_dollars, m_price_cents);
}

void PatientInfoMiddlePanel::modifyMedication(Medication* m)
{
	if (m == nullptr)
	{
		wxLogDebug("Warning: Nullptr in modifyMedication(). Unable to modify medication.");
		return;
	}

	std::string m_name = dname_txtctrl->GetValue().ToStdString();
	std::string m_desc = desc_txtctrl->GetValue().ToStdString();
	unsigned int m_price = HelperFunctions::strtoprice(price_txtctrl->GetValue().ToStdString());
	unsigned int m_price_dollars = m_price / 100;
	unsigned int m_price_cents = m_price % 100;
	unsigned int m_dosage = HelperFunctions::stoui(dosage_txtctrl->GetValue().ToStdString());
	unsigned int m_tnum = HelperFunctions::stoui(tnum_txtctrl->GetValue().ToStdString());

	DoseUnitEnum m_dunit;
	switch (dunit_cmbox->GetCurrentSelection())
	{
	case -1:
		wxMessageBox("No dose unit selected for modified medication. Defaults to milligrams.");
		m_dunit = DoseUnitEnum::milligrams;
		break;
	case 0:
		m_dunit = DoseUnitEnum::milligrams;
		break;
	case 1:
		m_dunit = DoseUnitEnum::milliliters;
		break;
	default:
		std::cout << "Error, invalid DoseUnitEnum in modifyMedication() in PatientInfoMiddlePanel. Exiting." << std::endl;
		exit(-1);
		break;
	}

	TimeUnitEnum m_tunit;
	switch (tunit_cmbox->GetCurrentSelection())
	{
	case -1:
		wxMessageBox("No time unit selected for modified medication. Defaults to hours.");
		m_tunit = TimeUnitEnum::hours;
		break;
	case 0:
		m_tunit = TimeUnitEnum::minutes;
		break;
	case 1:
		m_tunit = TimeUnitEnum::hours;
		break;
	case 2:
		m_tunit = TimeUnitEnum::days;
		break;
	default:
		std::cout << "Error, invalid TimeUnitEnum in modifyMedication() in PatientInfoMiddlePanel. Exiting." << std::endl;
		exit(-1);
		break;
	}

	m->setDrugName(m_name);
	m->setDescription(m_desc);
	m->setDosage(m_dosage);
	m->setDosageUnit(m_dunit);
	m->setTimeNum(m_tnum);
	m->setTimeUnit(m_tunit);
	m->setPriceDollars(m_price_dollars);
	m->setPriceCents(m_price_cents);
}

void PatientInfoMiddlePanel::fillMedicationInfo(Medication* m)
{
	if (m == nullptr) return;
	dname_txtctrl->SetValue(m->getDrugName());
	dosage_txtctrl->SetValue(std::to_string(m->getDosage()));
	tnum_txtctrl->SetValue(std::to_string(m->getTimeNum()));
	desc_txtctrl->SetValue(m->getDescription());
	price_txtctrl->SetValue(HelperFunctions::pricetostr(m->getPriceDollars(), m->getPriceCents()));

	switch (m->getDosageUnit())
	{
	case DoseUnitEnum::milligrams:
		dunit_cmbox->SetSelection(0);
		break;
	case DoseUnitEnum::milliliters:
		dunit_cmbox->SetSelection(1);
		break;
	default:
		std::cout << "Error, invalid DoseUnitEnum in fillMedicationInfo() in PatientInfoMiddlePanel. Exiting." << std::endl;
		exit(-1);
		break;
	}
	switch (m->getTimeUnit())
	{
	case TimeUnitEnum::minutes:
		tunit_cmbox->SetSelection(0);
		break;
	case TimeUnitEnum::hours:
		tunit_cmbox->SetSelection(1);
		break;
	case TimeUnitEnum::days:
		tunit_cmbox->SetSelection(2);
		break;
	default:
		std::cout << "Error, invalid TimeUnitEnum in fillMedicationInfo() in PatientInfoMiddlePanel. Exiting." << std::endl;
		exit(-1);
		break;
	}
}

void PatientInfoMiddlePanel::clearPanel()
{
	dname_txtctrl->Clear();
	dosage_txtctrl->Clear();
	tnum_txtctrl->Clear();
	price_txtctrl->Clear();
	desc_txtctrl->Clear();
	dunit_cmbox->SetSelection(wxNOT_FOUND);
	tunit_cmbox->SetSelection(wxNOT_FOUND);
	dunit_cmbox->SetLabelText("");
	tunit_cmbox->SetLabelText("");
}

PatientInfoMiddlePanel::~PatientInfoMiddlePanel()
{

}