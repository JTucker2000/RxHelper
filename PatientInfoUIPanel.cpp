#include "PatientInfoUIPanel.h"

PatientInfoUIPanel::PatientInfoUIPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, 2621440L, wxPanelNameStr)
{
	wxBoxSizer* pinfo_sizer = new wxBoxSizer(wxVERTICAL); // Sizer for the patient info panel.
	patient_info_top = new PatientInfoTopPanel(this);
	pinfo_sizer->Add
	(
		patient_info_top,
		wxSizerFlags(1).Expand().Border(wxALL, 5)
	);
	patient_info_middle = new PatientInfoMiddlePanel(this);
	pinfo_sizer->Add
	(
		patient_info_middle,
		wxSizerFlags().Expand().Border(wxLEFT | wxRIGHT | wxUP, 5)
	);
	medication_listctrl = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
	pinfo_sizer->Add
	(
		medication_listctrl,
		wxSizerFlags(2).Expand().Border(wxLEFT | wxRIGHT | wxDOWN, 5)
	);
	wxFont tempf = medication_listctrl->GetFont(); // Make listctrl font bigger.
	tempf.SetPointSize(12);
	medication_listctrl->SetFont(tempf);
	medication_listctrl->InsertColumn(0, "ID Number"); // Add columns to listctrl.
	medication_listctrl->InsertColumn(1, "Drug Name"); 
	medication_listctrl->InsertColumn(2, "Dosage");
	medication_listctrl->InsertColumn(3, "Price");
	medication_listctrl->InsertColumn(4, "Description");

	Medication* med1 = new Medication(1, "Advil", "Pain reliever", 10, DoseUnitEnum::milligrams, 6, TimeUnitEnum::hours, 10, 99);
	Medication* med2 = new Medication(2, "Morphine", "Pain reliever", 5, DoseUnitEnum::milligrams, 3, TimeUnitEnum::days, 500, 0);
	Medication* med3 = new Medication(3, "Pepto", "Relieves indigestion", 50, DoseUnitEnum::milliliters, 6, TimeUnitEnum::hours, 15, 5);
	addMedicationToList(med1);
	addMedicationToList(med2);
	addMedicationToList(med3);
	delete(med1);
	delete(med2);
	delete(med3);

	resizeColumns();

	medication_listctrl->Bind(wxEVT_SIZE, &PatientInfoUIPanel::resizeColumnsEvt, this); // Automatically resize columns.
	patient_info_middle->Bind(wxEVT_BUTTON, &PatientInfoUIPanel::removeMedicationEvt, this, REMOVEMEDICATIONBTN_ID); // Remove medication button click.

	SetSizer(pinfo_sizer);
}

void PatientInfoUIPanel::fillInfo(Patient* p)
{
	// Steps to create this function
	patient_info_top->clearPanel(); // 1. Clear Top Panel Info
	patient_info_middle->clearPanel(); // 2. Clear Middle Panel Info
	medication_listctrl->DeleteAllItems(); // 3. Clear Medication listctrl
	// 4. Fill information for Top panel and medication listctrl (Middle panel info not needed until user makes a selection)
	patient_info_top->fillPanel(p); // a. Fill top panel
	// b. Fill listctrl
}

void PatientInfoUIPanel::resizeColumns()
{
	if (!medication_listctrl) return;
	medication_listctrl->SetColumnWidth(0, wxLIST_AUTOSIZE_USEHEADER);
	medication_listctrl->SetColumnWidth(1, wxLIST_AUTOSIZE_USEHEADER);
	medication_listctrl->SetColumnWidth(2, wxLIST_AUTOSIZE_USEHEADER);
	medication_listctrl->SetColumnWidth(3, wxLIST_AUTOSIZE_USEHEADER);
	medication_listctrl->SetColumnWidth(4, wxLIST_AUTOSIZE_USEHEADER);
}

void PatientInfoUIPanel::resizeColumnsEvt(wxSizeEvent& event)
{
	resizeColumns();
}

void PatientInfoUIPanel::addMedicationToList(Medication* m)
{
	if (m == nullptr) return;

	std::string doseage_unit_str;
	std::string time_unit_str;
	DoseUnitEnum dose_unit = m->getDosageUnit();
	TimeUnitEnum time_unit = m->getTimeUnit();
	if (dose_unit == DoseUnitEnum::milligrams)
	{
		doseage_unit_str = "milligrams";
	}
	else if (dose_unit == DoseUnitEnum::milliliters)
	{
		doseage_unit_str = "milliliters";
	}
	else
	{
		doseage_unit_str = "Error, invalid dose_unit";
	}
	if (time_unit == TimeUnitEnum::days)
	{
		time_unit_str = "days";
	}
	else if (time_unit == TimeUnitEnum::hours)
	{
		time_unit_str = "hours";
	}
	else if (time_unit == TimeUnitEnum::minutes)
	{
		time_unit_str = "minutes";
	}
	else
	{
		time_unit_str = "Error, invalid time_unit";
	}
	std::string dosage_str = std::to_string(m->getDosage()) + " " + doseage_unit_str + " every " + std::to_string(m->getTimeNum()) + " " + time_unit_str;

	std::string id_num = std::to_string(m->getUniqueID());
	std::string cents_str;
	if (m->getPriceCents() < 10)
	{
		cents_str = "0" + std::to_string(m->getPriceCents());
	}
	else
	{
		cents_str = std::to_string(m->getPriceCents());
	}
	std::string price_str = "$" + std::to_string(m->getPriceDollars()) + "." + cents_str;
	int cur_index = medication_listctrl->GetItemCount();

	medication_listctrl->InsertItem(cur_index, id_num);
	medication_listctrl->SetItem(cur_index, 1, m->getDrugName());
	medication_listctrl->SetItem(cur_index, 2, dosage_str);
	medication_listctrl->SetItem(cur_index, 3, price_str);
	medication_listctrl->SetItem(cur_index, 4, m->getDescription());
	resizeColumns();
}

void PatientInfoUIPanel::removeMedication(int index)
{
	medication_listctrl->DeleteItem(index);
}

void PatientInfoUIPanel::removeMedicationEvt(wxCommandEvent& event)
{
	long selected_item = medication_listctrl->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
	removeMedication(selected_item);
}

PatientInfoUIPanel::~PatientInfoUIPanel()
{

}