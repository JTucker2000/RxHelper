#ifndef PRIMARYFRAME_H
#define PRIMARYFRAME_H

#include "wx/wx.h"

class PrimaryFrame : public wxFrame
{
public:
	PrimaryFrame();
	~PrimaryFrame();

private:
	wxBoxSizer* horizontal_sizer = nullptr;
};

#endif // PRIMARYFRAME_H
