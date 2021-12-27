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
	wxBoxSizer* vertical_sizer = nullptr;
};

#endif // LOGINUI_H
