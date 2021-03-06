#ifndef PATIENTINFOUIPANEL_H
#define PATIENTINFOUIPANEL_H

#include "wx/wx.h"
#include "wx/listctrl.h"
#include "ObjectIDs.h"
#include "Patient.h"
#include "HelperFunctions.h"
#include "DatabaseFunctions.h"
#include "PatientInfoTopPanel.h"
#include "PatientInfoMiddlePanel.h"

class PatientInfoUIPanel : public wxPanel
{
public:
	PatientInfoUIPanel(wxWindow* parent);

	// Fills the patient info UI panel with the given patient's information.
	void fillPatientInfo(Patient* p);

	// Creates a new patient object using the information currently entered in the panel.
	// This includes all of the medications currently assigned to the patient. Returns a pointer to that object.
	// Patient ID = 0 and all Medication IDs = 0, as they have not been added to the database yet.
	Patient* createPatient();

	// Modifies the currently selected patient (cur_patient) so that it's values match the values
	// currently entered into the top panel. Also modifies the patient's values in the database.
	void modifyPatient();

	// Resets all textctrls, listctrls, and comboboxes back to their default state.
	// Resets cur_patient to nullptr.
	void clearPanel();

	// Refreshes the current patient's information throughout the panel.
	// If there is no patient selected, it does nothing.
	void refreshPanel();

	~PatientInfoUIPanel();

private:
	wxListCtrl* medication_listctrl = nullptr;
	PatientInfoTopPanel* patient_info_top = nullptr;
	PatientInfoMiddlePanel* patient_info_middle = nullptr;
	Patient* cur_patient = nullptr;

	// Resizes columns in listctrl. Evt version runs after window resize event.
	void resizeColumns();
	void resizeColumnsEvt(wxSizeEvent& event);

	// Adds the medication to the listctrl.
	void addMedicationToListCtrl(Medication* m);

	// Fills the medication listctrl with all medications from a given patient.
	void fillListFromPatient(Patient* p);

	// Removes the medication from the listctrl. Evt version runs after remove button click.
	void removeMedicationListCtrl(int index);
	void removeMedicationEvt(wxCommandEvent& event);

	// Fills the medication info panel when an item is selected in the medication listctrl.
	void medicationListctrlItemSelect(wxCommandEvent& event);

	// Returns a pointer to the currently selected medication in the listctrl.
	Medication* getSelectedMedication();

	// Returns pointer to medication in cur_patient based on its ID, nullptr if there is no medication with the ID or if cur_patient = nullptr.
	Medication* getMedicationByID(unsigned int id);

	// Handles event when the add medication button is pressed.
	void addMedicationEvt(wxCommandEvent& event);

	// Handles event when the save medication button is pressed.
	void saveMedicationEvt(wxCommandEvent& event);
};

#endif // PATIENTINFOUIPANEL_H
