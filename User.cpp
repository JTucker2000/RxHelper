#include "User.h"

User::User()
{
	unique_id = 0;
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
	state = "";
}

User::User(unsigned int id, std::string user, std::string pass, std::string fname, std::string lname,
	std::string addr, std::string cty, std::string zip, std::string job, std::string phnum,
	PhoneTypeEnum phtype, std::string st)
{
	unique_id = id;
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

unsigned int User::getUniqueID() { return unique_id; }
std::string User::getUsername() { return username; }
std::string User::getPassword() { return password; }
std::string User::getFirstName() { return first_name; }
std::string User::getLastName() { return last_name; }
std::string User::getStreetAddr() { return street_addr; }
std::string User::getCity() { return city; }
std::string User::getZipCode() { return zip_code; }
std::string User::getJob() { return job_title; }
std::string User::getPhoneNum() { return phone_number; }
PhoneTypeEnum User::getPhoneType() { return phone_type; }
std::string User::getState() { return state; }

void User::setUniqueID(unsigned int val) { unique_id = val; }
void User::setUsername(std::string val) { username = val; }
void User::setPassword(std::string val) { password = val; }
void User::setFirstName(std::string val) { first_name = val; }
void User::setLastName(std::string val) { last_name = val; }
void User::setStreetAddr(std::string val) { street_addr = val; }
void User::setCity(std::string val) { city = val; }
void User::setZipCode(std::string val) { zip_code = val; }
void User::setJob(std::string val) { job_title = val; }
void User::setPhoneNum(std::string val) { phone_number = val; }
void User::setPhoneType(PhoneTypeEnum val) { phone_type = val; }
void User::setState(std::string val) { state = val; }

User::~User()
{

}