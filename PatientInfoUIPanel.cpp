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
	medication_listctrl = new wxListCtrl(this, MEDICATIONLISTCTRL_ID, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
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
	patient_info_middle->Bind(wxEVT_BUTTON, &PatientInfoUIPanel::saveMedicationEvt, this, SAVEMEDICATIONBTN_ID); // Save medication button click.
	patient_info_middle->Bind(wxEVT_BUTTON, &PatientInfoUIPanel::addMedicationEvt, this, ADDMEDICATIONBTN_ID); // Add medication button click.
	patient_info_middle->Bind(wxEVT_BUTTON, &PatientInfoUIPanel::removeMedicationEvt, this, REMOVEMEDICATIONBTN_ID); // Remove medication button click.
	Bind(wxEVT_LIST_ITEM_SELECTED, &PatientInfoUIPanel::medicationListctrlItemSelect, this, MEDICATIONLISTCTRL_ID); // Medication listctrl item select.

	SetSizer(pinfo_sizer);
}

void PatientInfoUIPanel::fillPatientInfo(Patient* p)
{
	if (p == nullptr) return;
	cur_patient = p;
	clearPanel();
	patient_info_top->fillPanel(p);
	fillListFromPatient(p);
}

void PatientInfoUIPanel::clearPanel()
{
	patient_info_top->clearPanel();
	patient_info_middle->clearPanel();
	medication_listctrl->DeleteAllItems();
}

void PatientInfoUIPanel::refreshPanel()
{
	if (cur_patient == nullptr) return;

	clearPanel();
	patient_info_top->fillPanel(cur_patient);
	fillListFromPatient(cur_patient);
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

void PatientInfoUIPanel::addMedicationToListCtrl(Medication* m)
{
	if (m == nullptr) return;

	std::string doseage_unit_str = HelperFunctions::duetostr(m->getDosageUnit());
	std::string time_unit_str = HelperFunctions::tuetostr(m->getTimeUnit());
	std::string dosage_str = std::to_string(m->getDosage()) + " " + doseage_unit_str + " every " + std::to_string(m->getTimeNum()) + " " + time_unit_str;
	std::string id_num = std::to_string(m->getUniqueID());
	int cur_index = medication_listctrl->GetItemCount();

	medication_listctrl->InsertItem(cur_index, id_num);
	medication_listctrl->SetItem(cur_index, 1, m->getDrugName());
	medication_listctrl->SetItem(cur_index, 2, dosage_str);
	medication_listctrl->SetItem(cur_index, 3, HelperFunctions::pricetostr(m->getPriceDollars(), m->getPriceCents()));
	medication_listctrl->SetItem(cur_index, 4, m->getDescription());
	resizeColumns();
}

void PatientInfoUIPanel::fillListFromPatient(Patient* p)
{
	if (p == nullptr) return;
	std::vector<Medication*>* med_list_pointer = p->getMedList();
	if (med_list_pointer == nullptr) return;

	for (int i = 0; i < med_list_pointer->size(); i++)
	{
		addMedicationToListCtrl(med_list_pointer->at(i));
	}
}

void PatientInfoUIPanel::removeMedicationListCtrl(int index)
{
	if (medication_listctrl->DeleteItem(index)) 
	{
		patient_info_middle->clearPanel();
	}
}

void PatientInfoUIPanel::removeMedicationEvt(wxCommandEvent& event)
{
	long selected_item = medication_listctrl->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
	if (selected_item == -1)
	{
		wxMessageBox("No medication selected.");
		return;
	}

	wxListItem* rowinfo = new wxListItem(); // Get medication ID of selected item.
	rowinfo->SetMask(wxLIST_MASK_TEXT);
	rowinfo->SetId(selected_item);
	rowinfo->SetColumn(0);
	medication_listctrl->GetItem(*rowinfo);
	std::string medication_id_string(rowinfo->GetText());
	delete(rowinfo);

	unsigned int medication_id = HelperFunctions::stoui(medication_id_string); // Convert ID to unsigned int.

	removeMedicationListCtrl(selected_item);
	cur_patient->delMedFromList(medication_id);
	DatabaseFunctions::removeMedicationFromDatabase(medication_id);

	event.Skip(true);
}

void PatientInfoUIPanel::medicationListctrlItemSelect(wxCommandEvent& event)
{
	Medication* selected_medication = getSelectedMedication(); // Get a pointer to the currently selected medication.
	if (selected_medication == nullptr) { return; }

	patient_info_middle->clearPanel(); // Fill medication info UI with medication information.
	patient_info_middle->fillMedicationInfo(selected_medication);
}

Medication* PatientInfoUIPanel::getSelectedMedication()
{
	long selected_item = medication_listctrl->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED); // Get selected item.
	if (selected_item == -1) return nullptr;

	wxListItem* rowinfo = new wxListItem(); // Get medication ID of selected item.
	rowinfo->SetMask(wxLIST_MASK_TEXT);
	rowinfo->SetId(selected_item);
	rowinfo->SetColumn(0);
	medication_listctrl->GetItem(*rowinfo);
	std::string medication_id_string(rowinfo->GetText());
	delete(rowinfo);

	unsigned int medication_id = HelperFunctions::stoui(medication_id_string); // Convert ID to unsigned int.

	return getMedicationByID(medication_id); // Return medication associated with that ID.
}

Medication* PatientInfoUIPanel::getMedicationByID(unsigned int id)
{
	if (cur_patient == nullptr) return nullptr;

	for (int i = 0; i < cur_patient->getMedList()->size(); i++)
	{
		if (cur_patient->getMedList()->at(i)->getUniqueID() == id) return cur_patient->getMedList()->at(i);
	}

	return nullptr;
}

void PatientInfoUIPanel::addMedicationEvt(wxCommandEvent& event)
{
	if (cur_patient == nullptr)
	{
		wxMessageBox("No patient selected.");
		return;
	}

	Medication* new_med = patient_info_middle->createMedication();
	DatabaseFunctions::addMedicationToDatabase(new_med, cur_patient);
	addMedicationToListCtrl(new_med);
	cur_patient->addMedToList(new_med);
	event.Skip(true);
}

void PatientInfoUIPanel::saveMedicationEvt(wxCommandEvent& event)
{
	Medication* m = getSelectedMedication();
	if (m == nullptr)
	{
		wxMessageBox("No medication selected.");
		return;
	}

	patient_info_middle->modifyMedication(m);
	DatabaseFunctions::modifyMedicationInDatabase(m);
	refreshPanel();
}

PatientInfoUIPanel::~PatientInfoUIPanel()
{

}