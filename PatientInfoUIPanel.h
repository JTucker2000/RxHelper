#ifndef PATIENTINFOUIPANEL_H
#define PATIENTINFOUIPANEL_H

#include <mysql/jdbc.h>
#include "wx/wx.h"
#include "wx/listctrl.h"
#include "ObjectIDs.h"
#include "Patient.h"
#include "HelperFunctions.h"
#include "PatientInfoTopPanel.h"
#include "PatientInfoMiddlePanel.h"

class PatientInfoUIPanel : public wxPanel
{
public:
	PatientInfoUIPanel(wxWindow* parent);

	// Fills the patient info UI panel with the given patient's information.
	void fillPatientInfo(Patient* p);

	// Resets all textctrls, listctrls, and comboboxes back to their default state.
	void clearPanel();

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

	// Adds the medication to the database.
	// Sets the given medication's ID to the assigned ID from the database.
	void addMedicationToDatabase(Medication* m);

	// Fills the medication listctrl with all medications from a given patient.
	void fillListFromPatient(Patient* p);

	// Removes the medication from the listctrl / database. Evt version runs after remove button click.
	void removeMedicationListCtrl(int index);
	void removeMedicationDatabase(unsigned int id);
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
