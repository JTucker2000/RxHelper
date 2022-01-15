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
	LoginUIPanel* login_ui_panel = nullptr;
	wxBoxSizer* login_sizer = nullptr;

	// Main screen
	MainSearchUIPanel* main_search_ui_panel = nullptr;
	PatientInfoUIPanel* patient_info_ui_panel = nullptr;
	PatientListUIPanel* patient_list_ui_panel = nullptr;
	wxBoxSizer* main_page_sizer = nullptr;

	void initializeLoginUI();
	void initializeMainPageUI();
	void loginButtonPress(wxCommandEvent& event);
	void patientListctrlItemSelect(wxCommandEvent& event);
};

#endif // PRIMARYFRAME_H
