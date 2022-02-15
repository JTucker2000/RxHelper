#ifndef DATABASEFUNCTIONS_H
#define DATABASEFUNCTIONS_H

#include <mysql/jdbc.h>
#include "wx/wx.h"
#include "HelperFunctions.h"
#include "Patient.h"
#include "Medication.h"

namespace DatabaseFunctions
{
	// Removes the patient and their associated medications from the database.
	void removePatientFromDatabase(unsigned int id);

	// Adds the medication to the database.
	// Sets the given medication's ID to the assigned ID from the database.
	// Medication is assigned to the given patient.
	void addMedicationToDatabase(Medication* m, Patient* p);

	// Modifies the medication in the database associated with the ID of the given medication.
	// Changes values in the database to match the given medication.
	void modifyMedicationInDatabase(Medication* m);

	// Removes the medication with the given id from the database.
	void removeMedicationFromDatabase(unsigned int id);
}

#endif // DATABASEFUNCTIONS_H

