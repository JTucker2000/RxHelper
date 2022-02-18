#ifndef PATIENTINFOTOPPANEL_H
#define PATIENTINFOTOPPANEL_H

#include "wx/wx.h"
#include "HelperFunctions.h"
#include "Patient.h"
#include "PhoneTypeEnum.h"

class PatientInfoTopPanel : public wxPanel
{
public:
	PatientInfoTopPanel(wxWindow* parent);

	// Creates a patient object using the information currently entered in the top panel.
	// Returns a pointer to that object. Returned object does not contain any medications.
	// Patient ID = 0, as it has not been added to the database yet.
	Patient* createPatient();

	// Resets all textctrls and comboboxes back to their default state.
	void clearPanel();

	// Fills the top panel with patient information.
	void fillPanel(Patient* p);

	~PatientInfoTopPanel();

private:
	// Textctrl pointers for this panel.
	wxTextCtrl* fname_txtctrl = nullptr;
	wxTextCtrl* age_txtctrl = nullptr;
	wxTextCtrl* addr_txtctrl = nullptr;
	wxTextCtrl* zip_txtctrl = nullptr;
	wxTextCtrl* phnum_txtctrl = nullptr;
	wxTextCtrl* lname_txtctrl = nullptr;
	wxTextCtrl* city_txtctrl = nullptr;
	wxTextCtrl* state_txtctrl = nullptr;
	wxTextCtrl* insname_txtctrl = nullptr;

	// Combobox pointers.
	wxComboBox* phtype_cmbox = nullptr;
	wxComboBox* age_unit_cmbox = nullptr;
};

#endif // PATIENTINFOTOPPANEL_H
