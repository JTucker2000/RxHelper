#include "LoginUIPanel.h"

LoginUIPanel::LoginUIPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(300, 180), 2621440L, wxPanelNameStr)
{
	// Sizer for Username.
	wxBoxSizer* user_sizer = new wxBoxSizer(wxVERTICAL);
	user_txtctrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxTextCtrlNameStr);
	user_sizer->Add
	(
		new wxStaticText(this, wxID_ANY, "Username: ", wxDefaultPosition, wxDefaultSize, 0, wxStaticTextNameStr),
		wxSizerFlags().Center().Border(wxALL, 5)
	);
	user_sizer->Add
	(
		user_txtctrl,
		wxSizerFlags(1).Expand().Border(wxALL, 10)
	);

	// Sizer for Password.
	wxBoxSizer* pass_sizer = new wxBoxSizer(wxVERTICAL);
	pass_txtctrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxTextCtrlNameStr);
	pass_sizer->Add
	(
		new wxStaticText(this, wxID_ANY, "Password:  ", wxDefaultPosition, wxDefaultSize, 0, wxStaticTextNameStr),
		wxSizerFlags().Center().Border(wxALL, 5)
	);
	pass_sizer->Add
	(
		pass_txtctrl,
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

	// Add users for testing.
	User* user1 = new User(1, "Jondoe12", "Thegrapes1123", "Jon", "Doe", "54 Tree Street", "Jacksonville", "02345", "Pharmacist", "745-465-2454", PhoneTypeEnum::Home, "ME");
	User* user2 = new User(2, "ITSTIM1998", "NowayMYMAN759", "Tim", "Timson", "5 Tim Road", "Timsville", "53563", "Pharmacist", "467-135-2784", PhoneTypeEnum::Home, "MA");
	User* user3 = new User(3, "Default", "password", "", "", "", "", "", "", "", PhoneTypeEnum::Other, "");
	user_list.push_back(user1);
	user_list.push_back(user2);
	user_list.push_back(user3);
}

bool LoginUIPanel::validateUser()
{
	std::string user_input = user_txtctrl->GetValue().ToStdString();
	std::string pass_input = pass_txtctrl->GetValue().ToStdString();

	for (int i = 0; i < user_list.size(); i++)
	{
		if ((user_list[i]->getUsername().compare(user_input) == 0) && (user_list[i]->getPassword().compare(pass_input) == 0))
		{
			return true;
		}
	}

	return false;
}

void LoginUIPanel::deleteUserList()
{
	for (int i = 0; i < user_list.size(); i++)
	{
		delete(user_list[i]);
	}
	user_list.clear();
}

LoginUIPanel::~LoginUIPanel()
{
	deleteUserList();
}