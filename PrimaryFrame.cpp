#include "PrimaryFrame.h"

PrimaryFrame::PrimaryFrame() : wxFrame(nullptr, wxID_ANY, "RxHelper", wxPoint(0,0) , wxSize(1280, 720))
{
	// Center the window on the screen.
	this->Center();
}

PrimaryFrame::~PrimaryFrame()
{

}