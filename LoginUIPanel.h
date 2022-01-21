#ifndef LOGINUIPANEL_H
#define LOGINUIPANEL_H

#include "wx/wx.h"
#include "ObjectIDs.h"

class LoginUIPanel : public wxPanel
{
public:
	LoginUIPanel(wxWindow* parent);

	// Validates whether or not the currently entered information is attached to a valid account.
	// Returns true if they can log in using the entered username and password, false otherwise.
	bool validateUser();

	~LoginUIPanel();
};

#endif // LOGINUIPANEL_H
