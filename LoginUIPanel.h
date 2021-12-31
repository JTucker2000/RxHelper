#ifndef LOGINUIPANEL_H
#define LOGINUIPANEL_H

#include "wx/wx.h"

class LoginUIPanel : public wxPanel
{
public:
	LoginUIPanel(wxWindow* parent);
	~LoginUIPanel();

private:
	void printTest(wxCommandEvent& event);
};

#endif // LOGINUIPANEL_H
