#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <vector>
#include <string>
#include "PhoneTypeEnum.h"
#include "TimeUnitEnum.h"
#include "Medication.h"

class Patient
{
public:
	Patient();
	Patient(unsigned int id, unsigned short int agenum, TimeUnitEnum ageunit, std::string fname, std::string lname,
		std::string addr, std::string cty, std::string zip, std::string phnum,
		std::string insname, PhoneTypeEnum phtype, std::string st, std::vector<Medication*>* medlist);

	// Adds the given medication to the patient's med_list.
	void addMedToList(Medication* m);

	// Removes the medication with the given id from the patient's list if it exists.
	void delMedFromList(unsigned int id);

	unsigned int getUniqueID();
	unsigned short int getAge();
	TimeUnitEnum getAgeUnit();
	std::string getFirstName();
	std::string getLastName();
	std::string getStreetAddr();
	std::string getCity();
	std::string getZipCode();
	std::string getPhoneNum();
	std::string getInsuranceName();
	PhoneTypeEnum getPhoneType();
	std::string getState();
	std::vector<Medication*>* getMedList();

	~Patient();

private:
	unsigned int unique_id;
	unsigned short int age;
	TimeUnitEnum age_unit;
	std::string first_name;
	std::string last_name;
	std::string street_addr;
	std::string city;
	std::string zip_code;
	std::string phone_number;
	std::string insurance_name;
	PhoneTypeEnum phone_type;
	std::string state;
	std::vector<Medication*> med_list;

	// Clears all memory associated with med_list.
	void deleteMedList();
};

#endif // PATIENT_H
