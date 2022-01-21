#ifndef LOGINUIPANEL_H
#define LOGINUIPANEL_H

#include <vector>
#include "wx/wx.h"
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

	// Textctrl pointers for this panel.
	wxTextCtrl* user_txtctrl = nullptr;
	wxTextCtrl* pass_txtctrl = nullptr;

	// Frees all memory associated with the user list.
	void deleteUserList();
};

#endif // LOGINUIPANEL_H
