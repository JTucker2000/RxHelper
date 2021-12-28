#include "LoginUI.h"

LoginUI::LoginUI(wxWindow* parent)
{
	if (!parent) {
		std::cout << "ERROR: LoginUI's parent window is NULL. Exiting . . ." << std::endl;
		exit(-1);
	}

	// Panel for login screen.
	wxPanel* login_panel = new wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(300, 180), 2621440L, wxPanelNameStr);

	// Sizer for Username.
	wxBoxSizer* user_sizer = new wxBoxSizer(wxVERTICAL);
	user_sizer->Add
	(
		new wxStaticText(login_panel, wxID_ANY, "Username: ", wxDefaultPosition, wxDefaultSize, 0, wxStaticTextNameStr),
		wxSizerFlags().Center().Border(wxALL, 5)
	);
	user_sizer->Add
	(
		new wxTextCtrl(login_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxTextCtrlNameStr),
		wxSizerFlags(1).Expand().Border(wxALL, 10)
	);

	// Sizer for Password.
	wxBoxSizer* pass_sizer = new wxBoxSizer(wxVERTICAL);
	pass_sizer->Add
	(
		new wxStaticText(login_panel, wxID_ANY, "Password:  ", wxDefaultPosition, wxDefaultSize, 0, wxStaticTextNameStr),
		wxSizerFlags().Center().Border(wxALL, 5)
	);
	pass_sizer->Add
	(
		new wxTextCtrl(login_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxTextCtrlNameStr),
		wxSizerFlags(1).Expand().Border(wxALL, 10)
	);

	// Sizer for login button.
	wxButton* lbutton = new wxButton(login_panel, wxID_ANY, "Log In", wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxButtonNameStr);
	lbutton->Bind(wxEVT_BUTTON, &LoginUI::printTest, this);
	wxBoxSizer* lbutton_sizer = new wxBoxSizer(wxHORIZONTAL);
	lbutton_sizer->AddStretchSpacer(1);
	lbutton_sizer->Add
	(
		lbutton,
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
	login_panel->SetSizer(lpanel_sizer);

	// Sizer for login screen.
	sizer = new wxBoxSizer(wxVERTICAL);
	sizer->AddStretchSpacer(1);
	sizer->Add
	(
		login_panel,
		wxSizerFlags().Center().Border(wxALL, 10)
	);
	sizer->AddStretchSpacer(1);
}

wxBoxSizer* LoginUI::getSizer() 
{
	return sizer;
}

void LoginUI::printTest(wxCommandEvent& event)
{
	wxMessageBox("Test");
}

LoginUI::~LoginUI() 
{
	
}