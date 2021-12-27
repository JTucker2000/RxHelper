#include "PrimaryFrame.h"

PrimaryFrame::PrimaryFrame() : wxFrame(nullptr, wxID_ANY, "RxHelper", wxPoint(0,0) , wxSize(1280, 720))
{
	login_ui = new LoginUI(this);

	SetSizer(login_ui->getSizer());

	Center();
}

PrimaryFrame::~PrimaryFrame()
{

}