#include "PrimaryFrame.h"

PrimaryFrame::PrimaryFrame() : wxFrame(nullptr, wxID_ANY, "RxHelper", wxPoint(0,0) , wxSize(1280, 720))
{
	// Create the login UI.
	initializeLoginUI();
	
	// Set sizer to login sizer, login UI appears on program start.
	SetSizer(login_sizer);
	SetMinSize(login_sizer->GetMinSize());

	// Create the main page UI.
	initializeMainPageUI();

	Center();
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
	main_search_ui_panel->Hide();
	patient_info_ui_panel->Hide();
	patient_list_ui_panel->Hide();
	main_page_sizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* left_main_sizer = new wxBoxSizer(wxVERTICAL);
	left_main_sizer->Add
	(
		main_search_ui_panel,
		wxSizerFlags(1).Expand().Border(wxLEFT | wxUP, 10)
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
	// For now, this function simply switches from the login UI
	// to the main UI when the login button is pressed.
	login_ui_panel->Hide();
	main_search_ui_panel->Show();
	patient_info_ui_panel->Show();
	patient_list_ui_panel->Show();
	SetSizer(main_page_sizer);
	Layout();
}

PrimaryFrame::~PrimaryFrame()
{
	delete(login_ui_panel);
	delete(main_search_ui_panel);
	delete(patient_info_ui_panel);
	delete(patient_list_ui_panel);
}