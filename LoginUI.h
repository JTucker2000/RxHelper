#ifndef LOGINUI_H
#define LOGINUI_H

#include "wx/wx.h"

class LoginUI
{
public:
	LoginUI(wxWindow* parent);
	wxBoxSizer* getSizer();
	~LoginUI();

private:
	wxBoxSizer* sizer = nullptr;

	void printTest(wxCommandEvent& event);
};

#endif // LOGINUI_H
