#ifndef PATIENT_H
#define PATIENT_H

#include <vector>
#include <string>
#include "PhoneTypeEnum.h"
#include "Medication.h"

class Patient
{
public:
	Patient();
	Patient(unsigned int id, std::string fname, std::string lname,
		std::string addr, std::string cty, std::string zip, std::string phnum,
		std::string insname, PhoneTypeEnum phtype, std::string st, std::vector<Medication*>* medlist);
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
	const unsigned int unique_id;
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
};

#endif // PATIENT_H
