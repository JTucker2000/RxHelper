#ifndef PRIMARYFRAME_H
#define PRIMARYFRAME_H

#include "wx/wx.h"
#include "LoginUIPanel.h"

class PrimaryFrame : public wxFrame
{
public:
	PrimaryFrame();
	void printTest(wxCommandEvent& event);
	~PrimaryFrame();

private:
	wxPanel* login_ui = nullptr;
	wxBoxSizer* sizer = nullptr;
};

#endif // PRIMARYFRAME_H
