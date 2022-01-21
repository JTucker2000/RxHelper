#include "LoginUIPanel.h"

LoginUIPanel::LoginUIPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(300, 180), 2621440L, wxPanelNameStr)
{
	// Sizer for Username.
	wxBoxSizer* user_sizer = new wxBoxSizer(wxVERTICAL);
	user_sizer->Add
	(
		new wxStaticText(this, wxID_ANY, "Username: ", wxDefaultPosition, wxDefaultSize, 0, wxStaticTextNameStr),
		wxSizerFlags().Center().Border(wxALL, 5)
	);
	user_sizer->Add
	(
		new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxTextCtrlNameStr),
		wxSizerFlags(1).Expand().Border(wxALL, 10)
	);

	// Sizer for Password.
	wxBoxSizer* pass_sizer = new wxBoxSizer(wxVERTICAL);
	pass_sizer->Add
	(
		new wxStaticText(this, wxID_ANY, "Password:  ", wxDefaultPosition, wxDefaultSize, 0, wxStaticTextNameStr),
		wxSizerFlags().Center().Border(wxALL, 5)
	);
	pass_sizer->Add
	(
		new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxTextCtrlNameStr),
		wxSizerFlags(1).Expand().Border(wxALL, 10)
	);

	// Sizer for login button.
	wxBoxSizer* lbutton_sizer = new wxBoxSizer(wxHORIZONTAL);
	lbutton_sizer->AddStretchSpacer(1);
	lbutton_sizer->Add
	(
		new wxButton(this, LOGINBUTTON_ID, "Log In", wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxButtonNameStr),
		wxSizerFlags().Center().Border(wxALL, 10)
	);
	lbutton_sizer->AddStretchSpacer(1);

	// Sizer for login panel.
	wxBoxSizer* lpanel_sizer = new wxBoxSizer(wxVERTICAL);
	lpanel_sizer->Add
	(
		user_sizer,
		wxSizerFlags().Expand()
	);
	lpanel_sizer->Add
	(
		pass_sizer,
		wxSizerFlags().Expand()
	);
	lpanel_sizer->Add
	(
		lbutton_sizer,
		wxSizerFlags().Expand()
	);
	SetSizer(lpanel_sizer);
}

bool LoginUIPanel::validateUser()
{
	return true; // Placeholder
}

LoginUIPanel::~LoginUIPanel()
{
	
}