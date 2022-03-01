#ifndef PATIENTLISTUIPANEL_H
#define PATIENTLISTUIPANEL_H

#include <mysql/jdbc.h>
#include <string>
#include <vector>
#include "wx/wx.h"
#include "wx/listctrl.h"
#include "Patient.h"
#include "PatientListBtnPanel.h"
#include "HelperFunctions.h"
#include "DatabaseFunctions.h"

class PatientListUIPanel : public wxPanel
{
public:
	PatientListUIPanel(wxWindow* parent);
	~PatientListUIPanel();

	// Returns a pointer to the currently selected patient in the listctrl.
	Patient* getSelectedPatient();

	// Adds the given patient to the database, patient_list, and listctrl.
	void addPatient(Patient* p);

	// Updates all information for the patient currently selected in the listctrl.
	void updatePatient();

	// Sorts patient_listctrl so that only patients with matching values to patient p are shown. 
	// If a value in patient p is empty, it will be ignored when sorting.
	void sortListByPatient(Patient* p);

private:
	std::vector<Patient*> patient_list;

	wxListCtrl* patient_listctrl = nullptr;

	// Pulls all patient information from the database. Only happens once on program startup when this object is created.
	void initPatientsFromDatabase();

	// Returns pointer to patient in patient_list based on its ID, nullptr if there is no patient with the ID.
	Patient* getPatientByID(unsigned int id);

	// Resizes columns in listctrl. Evt version runs after window resize event.
	void resizeColumns();
	void resizeColumnsEvt(wxSizeEvent& event);

	// Adds the patient to the listctrl.
	void addPatientToListCtrl(Patient* p);

	// Removes the patient at index from the list / listctrl. Evt version runs after remove button click.
	void removePatient(int index, int id);
	void removePatientEvt(wxCommandEvent& event);

	// Frees all memory associated with the patient list.
	void deletePatientList();
};

#endif // PATIENTLISTUIPANEL_H
