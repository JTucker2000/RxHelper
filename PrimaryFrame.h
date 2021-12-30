#ifndef PRIMARYFRAME_H
#define PRIMARYFRAME_H

#include "wx/wx.h"
#include "LoginUI.h"

class PrimaryFrame : public wxFrame
{
public:
	PrimaryFrame();
	~PrimaryFrame();

private:
	LoginUI* login_ui = nullptr;
};

#endif // PRIMARYFRAME_H
