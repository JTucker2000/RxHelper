#include "Patient.h"

Patient::Patient() : unique_id(0)
{
	age = 0;
	age_unit = TimeUnitEnum::years;
	first_name = "";
	last_name = "";
	street_addr = "";
	city = "";
	zip_code = "";
	phone_number = "";
	insurance_name = "";
	phone_type = PhoneTypeEnum::Other;
	state = "";
	med_list = {};
}

Patient::Patient(unsigned int id, unsigned short int agenum, TimeUnitEnum ageunit, std::string fname, std::string lname,
	std::string addr, std::string cty, std::string zip, std::string phnum,
	std::string insname, PhoneTypeEnum phtype, std::string st, std::vector<Medication*>* medlist) : unique_id(id)
{
	age = agenum;
	age_unit = ageunit;
	first_name = fname;
	last_name = lname;
	street_addr = addr;
	city = cty;
	zip_code = zip;
	phone_number = phnum;
	insurance_name = insname;
	phone_type = phtype;
	state = st;
	if(medlist) med_list = *medlist;
}

void Patient::addMedToList(Medication* m)
{
	if (m == nullptr)
	{
		std::cout << "Nullptr medication in addMedToList(), exiting." << std::endl;
		exit(-1);
	}

	med_list.push_back(m);
}

void Patient::delMedFromList(unsigned int id)
{
	if (id == 0) return;

	for (int i = 0; i < med_list.size(); i++)
	{
		if (med_list[i]->getUniqueID() == id)
		{
			delete(med_list[i]);
			med_list.erase(med_list.begin() + i);
			break;
		}
	}
}

const unsigned int Patient::getUniqueID() { return unique_id; }
unsigned short int Patient::getAge() { return age; }
TimeUnitEnum Patient::getAgeUnit() { return age_unit; }
std::string Patient::getFirstName() { return first_name; }
std::string Patient::getLastName() { return last_name; }
std::string Patient::getStreetAddr() { return street_addr; }
std::string Patient::getCity() { return city; }
std::string Patient::getZipCode() { return zip_code; }
std::string Patient::getPhoneNum() { return phone_number; }
std::string Patient::getInsuranceName() { return insurance_name; }
PhoneTypeEnum Patient::getPhoneType() { return phone_type; }
std::string Patient::getState() { return state; }
std::vector<Medication*>* Patient::getMedList() { return &med_list; }

void Patient::deleteMedList()
{
	for (int i = 0; i < med_list.size(); i++)
	{
		delete(med_list[i]);
	}
	med_list.clear();
}

Patient::~Patient()
{
	deleteMedList();
}