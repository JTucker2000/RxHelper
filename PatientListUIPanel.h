#ifndef PATIENTLISTUIPANEL_H
#define PATIENTLISTUIPANEL_H

#include <string>
#include "wx/wx.h"
#include "wx/listctrl.h"
#include "Patient.h"
#include "PatientListBtnPanel.h"

class PatientListUIPanel : public wxPanel
{
public:
	PatientListUIPanel(wxWindow* parent);
	~PatientListUIPanel();

private:
	wxListCtrl* patient_listctrl = nullptr;

	// Resizes columns in listctrl. Evt version runs after window resize event.
	void resizeColumns();
	void resizeColumnsEvt(wxSizeEvent& event);

	// Adds the patient to the listctrl.
	void addPatient(Patient* p);

	// Removes the patient at index from the listctrl.
	void removePatient(int index);
};

#endif // PATIENTLISTUIPANEL_H
