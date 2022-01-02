#include "PrimaryFrame.h"

PrimaryFrame::PrimaryFrame() : wxFrame(nullptr, wxID_ANY, "RxHelper", wxPoint(0,0) , wxSize(1280, 720))
{
	// Create the login UI.
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
	
	// Set sizer to login sizer, login UI appears on program start.
	SetSizer(login_sizer);
	SetMinSize(login_sizer->GetMinSize());

	// Create the main page UI.
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
		wxSizerFlags().Expand().Border(wxALL, 10)
	);
	left_main_sizer->Add
	(
		patient_list_ui_panel,
		wxSizerFlags().Expand().Border(wxALL, 10)
	);
	main_page_sizer->Add
	(
		left_main_sizer,
		wxSizerFlags().Center()
	);
	main_page_sizer->Add
	(
		patient_info_ui_panel,
		wxSizerFlags().Expand().Border(wxALL, 10)
	);

	Center();
}

void PrimaryFrame::loginButtonPress(wxCommandEvent& event)
{
	wxMessageBox("TEST");
}

PrimaryFrame::~PrimaryFrame()
{
	delete(login_ui_panel);
	delete(main_search_ui_panel);
	delete(patient_info_ui_panel);
	delete(patient_list_ui_panel);
	delete(main_page_sizer);
}