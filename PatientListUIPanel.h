#ifndef PATIENTLISTUIPANEL_H
#define PATIENTLISTUIPANEL_H

#include "wx/wx.h"
#include "PatientListBtnPanel.h"

class PatientListUIPanel : public wxPanel
{
public:
	PatientListUIPanel(wxWindow* parent);
	~PatientListUIPanel();

private:
	wxListBox* patient_listbox = nullptr;
};

#endif // PATIENTLISTUIPANEL_H
