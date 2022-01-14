#ifndef PATIENTINFOMIDDLEPANEL_H
#define PATIENTINFOMIDDLEPANEL_H

#include "wx/wx.h"
#include "HelperFunctions.h"
#include "Medication.h"
#include "ObjectIDs.h"

class PatientInfoMiddlePanel : public wxPanel
{
public:
	PatientInfoMiddlePanel(wxWindow* parent);

	// Fills the medication info UI panel with the given medication's information.
	void fillMedicationInfo(Medication* m);

	// Resets all textctrls and comboboxes back to their default state.
	void clearPanel();

	~PatientInfoMiddlePanel();

private:
	// Textctrl pointers for this panel.
	wxTextCtrl* dname_txtctrl = nullptr;
	wxTextCtrl* dosage_txtctrl = nullptr;
	wxTextCtrl* tnum_txtctrl = nullptr;
	wxTextCtrl* price_txtctrl = nullptr;
	wxTextCtrl* desc_txtctrl = nullptr;

	// Combobox pointers.
	wxComboBox* dunit_cmbox = nullptr;
	wxComboBox* tunit_cmbox = nullptr;
};

#endif // PATIENTINFOMIDDLEPANEL_H
