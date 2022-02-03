#include "PrimaryFrame.h"

PrimaryFrame::PrimaryFrame() : wxFrame(nullptr, wxID_ANY, "RxHelper", wxPoint(0,0) , wxSize(1920, 1000))
{
	// Create the login UI.
	initializeLoginUI();
	
	// Set sizer to login sizer, login UI appears on program start.
	SetSizer(login_sizer, true);
	SetMinSize(login_sizer->GetMinSize());

	// Create the main page UI.
	initializeMainPageUI();

	Center();
	Refresh();
	Update();
}

void PrimaryFrame::initializeLoginUI() 
{
	login_ui_panel = new LoginUIPanel(this);

	login_ui_panel->Bind(wxEVT_BUTTON, &PrimaryFrame::loginButtonPress, this, LOGINBUTTON_ID); // Handle login UI events.

	login_sizer = new wxBoxSizer(wxVERTICAL); // Prepare login UI sizer.
	login_sizer->AddStretchSpacer(1);
	login_sizer->Add
	(
		login_ui_panel,
		wxSizerFlags().Center().Border(wxALL, 10)
	);
	login_sizer->AddStretchSpacer(1);
}

void PrimaryFrame::initializeMainPageUI()
{
	main_search_ui_panel = new MainSearchUIPanel(this);
	patient_info_ui_panel = new PatientInfoUIPanel(this);
	patient_list_ui_panel = new PatientListUIPanel(this);

	patient_list_ui_panel->Bind(wxEVT_LIST_ITEM_SELECTED, &PrimaryFrame::patientListctrlItemSelect, this, PATIENTLISTCTRL_ID); // Handle main page UI events.
	patient_list_ui_panel->Bind(wxEVT_BUTTON, &PrimaryFrame::clearPatientInfoOnRemove, this, REMOVEPATIENTBTN_ID);
	patient_info_ui_panel->Bind(wxEVT_BUTTON, &PrimaryFrame::updatePatientMedNum, this, REMOVEMEDICATIONBTN_ID);
	patient_info_ui_panel->Bind(wxEVT_BUTTON, &PrimaryFrame::updatePatientMedNum, this, ADDMEDICATIONBTN_ID);

	main_search_ui_panel->Hide(); // Hidden on program start.
	patient_info_ui_panel->Hide();
	patient_list_ui_panel->Hide();

	main_page_sizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* left_main_sizer = new wxBoxSizer(wxVERTICAL);
	left_main_sizer->Add
	(
		main_search_ui_panel,
		wxSizerFlags().Expand().Border(wxLEFT | wxUP, 10)
	);
	left_main_sizer->Add
	(
		patient_list_ui_panel,
		wxSizerFlags(1).Expand().Border(wxLEFT | wxUP | wxDOWN, 10)
	);
	main_page_sizer->Add
	(
		left_main_sizer,
		wxSizerFlags(1).Expand()
	);
	main_page_sizer->Add
	(
		patient_info_ui_panel,
		wxSizerFlags(1).Expand().Border(wxALL, 10)
	);
}

void PrimaryFrame::loginButtonPress(wxCommandEvent& event)
{
	if (login_ui_panel->validateUser()) 
	{
		login_ui_panel->Hide();
		main_search_ui_panel->Show();
		patient_info_ui_panel->Show();
		patient_list_ui_panel->Show();
		SetSizer(main_page_sizer, false);
		Layout();
		Refresh();
		Update();
	}
}

void PrimaryFrame::patientListctrlItemSelect(wxCommandEvent& event)
{
	Patient* selected_patient = patient_list_ui_panel->getSelectedPatient(); // Get a pointer to the currently selected patient.
	if (selected_patient == nullptr) { return; }

	patient_info_ui_panel->fillPatientInfo(selected_patient); // Fill patient info UI with patient information.
}

void PrimaryFrame::clearPatientInfoOnRemove(wxCommandEvent& event)
{
	patient_info_ui_panel->clearPanel();
}

void PrimaryFrame::updatePatientMedNum(wxCommandEvent& event)
{
	wxMessageBox("TEST");
}

PrimaryFrame::~PrimaryFrame()
{
	SetSizer(nullptr, false);
	delete(login_ui_panel);
	delete(login_sizer);
	delete(main_search_ui_panel);
	delete(patient_info_ui_panel);
	delete(patient_list_ui_panel);
	delete(main_page_sizer);
}