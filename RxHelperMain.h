#pragma once

#include "wx/wx.h"
#include "PrimaryFrame.h"

class RxHelperMain : public wxApp
{
public:
	RxHelperMain();
	~RxHelperMain();
	virtual bool OnInit();

private:
	PrimaryFrame* primary_frame = nullptr;
};

