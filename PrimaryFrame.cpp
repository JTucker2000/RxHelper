#include "PrimaryFrame.h"

PrimaryFrame::PrimaryFrame() : wxFrame(nullptr, wxID_ANY, "RxHelper", wxPoint(0,0) , wxSize(1280, 720))
{
	// Create the login UI panel.
	login_ui_panel = new LoginUIPanel(this);
	login_ui_panel->Bind(wxEVT_BUTTON, &PrimaryFrame::loginButtonPress, this, wxID_EXECUTE); // Handle login UI events.
	login_sizer = new wxBoxSizer(wxVERTICAL); // Prepare login UI sizer.
	login_sizer->AddStretchSpacer(1);
	login_sizer->Add
	(
		login_ui_panel,
		wxSizerFlags().Center().Border(wxALL, 10)
	);
	login_sizer->AddStretchSpacer(1);
	SetSizer(login_sizer);
	SetMinSize(login_sizer->GetMinSize());

	Center();
}

void PrimaryFrame::loginButtonPress(wxCommandEvent& event)
{
	wxMessageBox("TEST");
}

PrimaryFrame::~PrimaryFrame()
{
	delete(login_ui_panel);
}