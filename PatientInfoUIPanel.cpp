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

	resizeColumns();

	medication_listctrl->Bind(wxEVT_SIZE, &PatientInfoUIPanel::resizeColumnsEvt, this); // Automatically resize columns.
	patient_info_middle->Bind(wxEVT_BUTTON, &PatientInfoUIPanel::removeMedicationEvt, this, REMOVEMEDICATIONBTN_ID); // Remove medication button click.

	SetSizer(pinfo_sizer);
}

void PatientInfoUIPanel::fillInfo(Patient* p)
{
	patient_info_top->clearPanel();
	patient_info_middle->clearPanel();
	medication_listctrl->DeleteAllItems();
	patient_info_top->fillPanel(p);
	fillListFromPatient(p);
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

void PatientInfoUIPanel::fillListFromPatient(Patient* p)
{
	std::vector<Medication*>* med_list_pointer = p->getMedList();
	if (med_list_pointer == nullptr) return;

	for (int i = 0; i < med_list_pointer->size(); i++)
	{
		addMedicationToList(med_list_pointer->at(i));
	}
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