#include "PrimaryFrame.h"

PrimaryFrame::PrimaryFrame() : wxFrame(nullptr, wxID_ANY, "RxHelper", wxPoint(0,0) , wxSize(1280, 720))
{
	horizontal_sizer = new wxBoxSizer(wxVERTICAL);

	horizontal_sizer->AddStretchSpacer(1);
	horizontal_sizer->Add
	(
		new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(100, 50), 2621440L, "test"),
		wxSizerFlags().Center().Border(wxALL, 10)
	);
	horizontal_sizer->AddStretchSpacer(1);

	SetSizer(horizontal_sizer);

	Center();
}

PrimaryFrame::~PrimaryFrame()
{

}