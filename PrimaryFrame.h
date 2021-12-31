#ifndef PRIMARYFRAME_H
#define PRIMARYFRAME_H

#include "wx/wx.h"
#include "LoginUIPanel.h"
#include "ObjectIDs.h"

class PrimaryFrame : public wxFrame
{
public:
	PrimaryFrame();
	~PrimaryFrame();

private:
	wxPanel* login_ui_panel = nullptr;
	wxBoxSizer* login_sizer = nullptr;

	void loginButtonPress(wxCommandEvent& event);
};

#endif // PRIMARYFRAME_H
