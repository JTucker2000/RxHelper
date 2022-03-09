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
	pass_txtctrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD, wxDefaultValidator, wxTextCtrlNameStr);
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
	lbutton_sizer->Add
	(
		new wxButton(this, wxID_ANY, "Create Account", wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxButtonNameStr),
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

	initUsersFromDatabase();
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

void LoginUIPanel::initUsersFromDatabase()
{
	sql::Driver* driver = nullptr;
	sql::Connection* con = nullptr;
	sql::Statement* stmt = nullptr;
	sql::ResultSet* user_res_tab = nullptr;

	try
	{
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
		con->setSchema("RxHelperDB");
		stmt = con->createStatement();
		user_res_tab = stmt->executeQuery("SELECT * FROM user");

		// For each user in the database.
		while (user_res_tab->next())
		{
			unsigned int u_id = user_res_tab->getUInt(1);
			std::string u_username = user_res_tab->getString(2).asStdString();
			std::string u_password = user_res_tab->getString(3).asStdString();
			std::string u_first_name = user_res_tab->getString(4).asStdString();
			std::string u_last_name = user_res_tab->getString(5).asStdString();
			std::string u_str_addr = user_res_tab->getString(6).asStdString();
			std::string u_city = user_res_tab->getString(7).asStdString();
			std::string u_zip_code = user_res_tab->getString(8).asStdString();
			std::string u_state = user_res_tab->getString(9).asStdString();
			std::string u_phone_num = user_res_tab->getString(10).asStdString();
			PhoneTypeEnum u_phone_type = HelperFunctions::strtopte(user_res_tab->getString(11).asStdString());
			std::string u_job_title = user_res_tab->getString(12).asStdString();

			User* new_u = new User(u_id, u_username, u_password, u_first_name, u_last_name, u_str_addr, u_city, u_zip_code, u_state, u_phone_num, u_phone_type, u_job_title);

			user_list.push_back(new_u);
		}
	}
	catch (sql::SQLException& e)
	{
		wxLogDebug(e.what());
	}

	delete user_res_tab;
	delete stmt;
	delete con;
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