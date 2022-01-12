#ifndef PATIENTLISTUIPANEL_H
#define PATIENTLISTUIPANEL_H

#include <string>
#include <vector>
#include "wx/wx.h"
#include "wx/listctrl.h"
#include "Patient.h"
#include "PatientListBtnPanel.h"

class PatientListUIPanel : public wxPanel
{
public:
	PatientListUIPanel(wxWindow* parent);
	~PatientListUIPanel();

	// Returns a pointer to the currently selected patient in the listctrl.
	Patient* getSelectedPatient();

private:
	std::vector<Patient*> patient_list;

	wxListCtrl* patient_listctrl = nullptr;

	// Returns pointer to patient in patient_list based on its ID.
	// Returns nullptr if there is no patient with the ID.
	Patient* getPatientByID(unsigned int id);

	// Resizes columns in listctrl. Evt version runs after window resize event.
	void resizeColumns();
	void resizeColumnsEvt(wxSizeEvent& event);

	// Adds the patient to the listctrl.
	void addPatientToList(Patient* p);

	// Removes the patient at index from the listctrl. Evt version runs after remove button click.
	void removePatient(int index);
	void removePatientEvt(wxCommandEvent& event);

	// Frees all memory associated with the patient list.
	void deletePatientList();
};

#endif // PATIENTLISTUIPANEL_H
