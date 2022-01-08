#include "MainSearchUIPanel.h"

MainSearchUIPanel::MainSearchUIPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, 2621440L, wxPanelNameStr)
{
	wxStaticText* psearch_txt = new wxStaticText(this, wxID_ANY, "Patient Search", wxDefaultPosition, wxDefaultSize, 0L, wxStaticTextNameStr); // Create patient search static text.
	wxFont tempf = psearch_txt->GetFont(); // Make font bigger.
	tempf.SetPointSize(14);
	psearch_txt->SetFont(tempf);

	wxBoxSizer* main_search_sizer = new wxBoxSizer(wxVERTICAL); // Sizer for the main search panel.
	main_search_sizer->Add
	(
		psearch_txt,
		wxSizerFlags().Center().Border(wxALL, 10)
	);

	SetSizer(main_search_sizer);
}

MainSearchUIPanel::~MainSearchUIPanel()
{

}