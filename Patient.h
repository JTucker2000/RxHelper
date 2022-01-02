#ifndef PATIENT_H
#define PATIENT_H

#include <vector>
#include <string>
#include "StateEnum.h"
#include "PhoneTypeEnum.h"
#include "Medication.h"

class Patient
{
public:
	Patient();
	Patient(std::string fname, std::string lname,
		std::string addr, std::string cty, std::string zip, std::string phnum,
		std::string insname, PhoneTypeEnum phtype, StateEnum st, std::vector<Medication>* medlist);
	~Patient();

private:
	std::string first_name;
	std::string last_name;
	std::string street_addr;
	std::string city;
	std::string zip_code;
	std::string phone_number;
	std::string insurance_name;
	PhoneTypeEnum phone_type;
	StateEnum state;
	std::vector<Medication> med_list;
};

#endif // PATIENT_H
