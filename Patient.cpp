#include "Patient.h"

Patient::Patient() : unique_id(-1)
{
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

Patient::Patient(unsigned int id, std::string fname, std::string lname,
	std::string addr, std::string cty, std::string zip, std::string phnum,
	std::string insname, PhoneTypeEnum phtype, std::string st, std::vector<Medication*>* medlist) : unique_id(id) // TODO: Generate unique IDs for each medication, patient, and user. Hardcoded for now.
{
	// TODO: Sanitize these before putting them in the container.
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

const unsigned int Patient::getUniqueID() { return unique_id; }
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

Patient::~Patient()
{

}