#ifndef PATIENTINFOMIDDLEPANEL_H
#define PATIENTINFOMIDDLEPANEL_H

#include "wx/wx.h"
#include "ObjectIDs.h"

class PatientInfoMiddlePanel : public wxPanel
{
public:
	PatientInfoMiddlePanel(wxWindow* parent);

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
