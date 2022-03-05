#ifndef USER_H
#define USER_H

#include <string>
#include "PhoneTypeEnum.h"

class User
{
public:
	User();
	User(unsigned int id, std::string user, std::string pass, std::string fname, std::string lname,
		std::string addr, std::string cty, std::string zip, std::string job, std::string phnum,
		PhoneTypeEnum phtype, std::string st);

	unsigned int getUniqueID();
	std::string getUsername();
	std::string getPassword();
	std::string getFirstName();
	std::string getLastName();
	std::string getStreetAddr();
	std::string getCity();
	std::string getZipCode();
	std::string getJob();
	std::string getPhoneNum();
	PhoneTypeEnum getPhoneType();
	std::string getState();

	void setUniqueID(unsigned int val);
	void setUsername(std::string val);
	void setPassword(std::string val);
	void setFirstName(std::string val);
	void setLastName(std::string val);
	void setStreetAddr(std::string val);
	void setCity(std::string val);
	void setZipCode(std::string val);
	void setJob(std::string val);
	void setPhoneNum(std::string val);
	void setPhoneType(PhoneTypeEnum val);
	void setState(std::string val);

	~User();

private:
	unsigned int unique_id;
	std::string username;
	std::string password;
	std::string first_name;
	std::string last_name;
	std::string street_addr;
	std::string city;
	std::string zip_code;
	std::string job_title;
	std::string phone_number;
	PhoneTypeEnum phone_type;
	std::string state;
};

#endif // USER_H
