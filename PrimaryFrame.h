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

	// Creates and prepares everything needed for the Login UI.
	void initializeLoginUI();

	// Creates and prepares everything needed for the main page UI.
	void initializeMainPageUI();

	// Handles the event when the login button is pressed.
	void loginButtonPress(wxCommandEvent& event);

	// Handles the event when the add patient button is pressed.
	void addPatientButtonPress(wxCommandEvent& event);

	// Handles the event when the save patient button is pressed.
	void savePatientButtonPress(wxCommandEvent& event);

	// Handles the event when the search button is pressed.
	void searchButtonPress(wxCommandEvent& event);

	// Handles the event when the clear search button is pressed.
	void clearSearchButtonPress(wxCommandEvent& event);

	// Handles the event when an item is selected in the patient listctrl.
	void patientListctrlItemSelect(wxCommandEvent& event);

	// Handles the event when a patient is removed from the listctrl.
	// This function clears the PatientInfoUIPanel when a patient is removed.
	void clearPatientInfoOnRemove(wxCommandEvent& event);

	// Handles the event when the patient information needs to be updated in the patient list ui.
	// Currently triggered by remove / add medication buttons.
	void updatePatient(wxCommandEvent& event);
};

#endif // PRIMARYFRAME_H
