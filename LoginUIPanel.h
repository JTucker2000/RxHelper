#ifndef LOGINUIPANEL_H
#define LOGINUIPANEL_H

#include <vector>
#include <mysql/jdbc.h>
#include "wx/wx.h"
#include "HelperFunctions.h"
#include "ObjectIDs.h"
#include "User.h"

class LoginUIPanel : public wxPanel
{
public:
	LoginUIPanel(wxWindow* parent);

	// Validates whether or not the currently entered information is attached to a valid account.
	// Returns true if they can log in using the entered username and password, false otherwise.
	bool validateUser();

	~LoginUIPanel();

private:
	std::vector<User*> user_list;

	// Sizer for login page.
	wxBoxSizer* lpanel_sizer = nullptr;

	// Sizer for account creation page.
	wxBoxSizer* newacc_sizer = nullptr;

	// Textctrl pointers for this panel.
	wxTextCtrl* user_txtctrl = nullptr;
	wxTextCtrl* pass_txtctrl = nullptr;

	// Pulls all user information from the database. Only happens once on program startup when this object is created.
	void initUsersFromDatabase();
	
	// Handles the event when the create account button is pressed.
	void createAccountButtonPress(wxCommandEvent& event);

	// Frees all memory associated with the user list.
	void deleteUserList();
};

#endif // LOGINUIPANEL_H
