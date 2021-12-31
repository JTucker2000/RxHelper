#include "PrimaryFrame.h"

PrimaryFrame::PrimaryFrame() : wxFrame(nullptr, wxID_ANY, "RxHelper", wxPoint(0,0) , wxSize(1280, 720))
{
	login_ui = new LoginUIPanel(this);

	// Sizer for login screen.
	sizer = new wxBoxSizer(wxVERTICAL);
	sizer->AddStretchSpacer(1);
	sizer->Add
	(
		login_ui,
		wxSizerFlags().Center().Border(wxALL, 10)
	);
	sizer->AddStretchSpacer(1);
	SetSizer(sizer);
	SetMinSize(sizer->GetMinSize());

	Center();
}

PrimaryFrame::~PrimaryFrame()
{
	delete(login_ui);
}