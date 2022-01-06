#ifndef PATIENTINFOUIPANEL_H
#define PATIENTINFOUIPANEL_H

#include "wx/wx.h"
#include "wx/listctrl.h"
#include "PatientInfoTopPanel.h"
#include "PatientInfoMiddlePanel.h"

class PatientInfoUIPanel : public wxPanel
{
public:
	PatientInfoUIPanel(wxWindow* parent);
	~PatientInfoUIPanel();

private:
	wxListCtrl* medication_listctrl = nullptr;
	PatientInfoTopPanel* patient_info_top = nullptr;
	PatientInfoMiddlePanel* patient_info_middle = nullptr;

	// Resizes columns in listctrl. Evt version runs after window resize event.
	void resizeColumns();
	void resizeColumnsEvt(wxSizeEvent& event);
};

#endif // PATIENTINFOUIPANEL_H
