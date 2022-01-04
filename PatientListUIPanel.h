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

	// Resizes columns in listctrl after a window resize event.
	void resizeColumns(wxSizeEvent& event);

	// Adds the patient to the listctrl.
	void addPatient(Patient* p);
};

#endif // PATIENTLISTUIPANEL_H
