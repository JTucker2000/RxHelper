#include "User.h"

User::User()
{
	username = "";
	password = "";
	first_name = "";
	last_name = "";
	street_addr = "";
	city = "";
	zip_code = "";
	job_title = "";
	phone_number = "";
	phone_type = PhoneTypeEnum::Other;
	state = StateEnum::AL;
}

User::User(std::string user, std::string pass, std::string fname, std::string lname,
	std::string addr, std::string cty, std::string zip, std::string job, std::string phnum,
	PhoneTypeEnum phtype, StateEnum st)
{
	// TODO: Sanitize these before putting them in the container.
	username = user;
	password = pass;
	first_name = fname;
	last_name = lname;
	street_addr = addr;
	city = cty;
	zip_code = zip;
	job_title = job;
	phone_number = phnum;
	phone_type = phtype;
	state = st;
}