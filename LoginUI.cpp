#include "LoginUI.h"

LoginUI::LoginUI(wxWindow* parent)
{
	if (!parent) {
		std::cout << "ERROR: LoginUI's parent window is NULL. Exiting . . ." << std::endl;
		exit(-1);
	}

	vertical_sizer = new wxBoxSizer(wxVERTICAL);

	vertical_sizer->AddStretchSpacer(1);
	vertical_sizer->Add
	(
		new wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(100, 50), 2621440L, "test"),
		wxSizerFlags().Center().Border(wxALL, 10)
	);
	vertical_sizer->AddStretchSpacer(1);
}

wxBoxSizer* LoginUI::getSizer() 
{
	return vertical_sizer;
}

LoginUI::~LoginUI() 
{

}