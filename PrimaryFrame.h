#ifndef PRIMARYFRAME_H
#define PRIMARYFRAME_H

#include "wx/wx.h"
#include "LoginUIPanel.h"
#include "MainSearchUIPanel.h"
#include "PatientInfoUIPanel.h"
#include "PatientListUIPanel.h"
#include "ObjectIDs.h"

class PrimaryFrame : public wxFrame
{
public:
	PrimaryFrame();
	~PrimaryFrame();

private:
	// Login screen
	wxPanel* login_ui_panel = nullptr;
	wxBoxSizer* login_sizer = nullptr;

	// Main screen
	wxPanel* main_search_ui_panel = nullptr;
	wxPanel* patient_info_ui_panel = nullptr;
	wxPanel* patient_list_ui_panel = nullptr;
	wxBoxSizer* main_page_sizer = nullptr;

	void initializeLoginUI();
	void initializeMainPageUI();
	void loginButtonPress(wxCommandEvent& event);
	void viewPatientButtonPress(wxCommandEvent& event);
};

#endif // PRIMARYFRAME_H
