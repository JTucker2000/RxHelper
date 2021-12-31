#include "Patient.h"

Patient::Patient()
{
	first_name = "";
	last_name = "";
	street_addr = "";
	city = "";
	zip_code = "";
	phone_number = "";
	insurance_name = "";
	phone_type = PhoneTypeEnum::Other;
	state = StateEnum::AL;
}

Patient::Patient(std::string fname, std::string lname,
	std::string addr, std::string cty, std::string zip, std::string phnum,
	std::string insname, PhoneTypeEnum phtype, StateEnum st)
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
}

Patient::~Patient()
{

}