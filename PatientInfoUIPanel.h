#ifndef PATIENTINFOUIPANEL_H
#define PATIENTINFOUIPANEL_H

#include "wx/wx.h"
#include "wx/listctrl.h"
#include "PatientInfoTopPanel.h"

class PatientInfoUIPanel : public wxPanel
{
public:
	PatientInfoUIPanel(wxWindow* parent);
	~PatientInfoUIPanel();

private:
	wxListCtrl* medication_listctrl = nullptr;
	PatientInfoTopPanel* patient_info_top = nullptr;
};

#endif // PATIENTINFOUIPANEL_H
