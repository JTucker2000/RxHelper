#ifndef MAINSEARCHUIPANEL_H
#define MAINSEARCHUIPANEL_H

#include "wx/wx.h"
#include "ObjectIDs.h"

class MainSearchUIPanel : public wxPanel
{
public:
	MainSearchUIPanel(wxWindow* parent);
	~MainSearchUIPanel();

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

	// Resets all textctrls and comboboxes back to their default state.
	void clearSearch(wxCommandEvent& event);
};

#endif // MAINSEARCHUIPANEL_H
