#ifndef USER_H
#define USER_H

#include <string>
#include "StateEnum.h"
#include "PhoneTypeEnum.h"

class User
{
public:
	User();
	User(std::string user, std::string pass, std::string fname, std::string lname,
		std::string addr, std::string cty, std::string zip, std::string job, std::string phnum,
		PhoneTypeEnum phtype, StateEnum st);

private:
	std::string username;
	// plaintext password for now, can add encryption later.
	std::string password;
	std::string first_name;
	std::string last_name;
	std::string street_addr;
	std::string city;
	std::string zip_code;
	std::string job_title;
	std::string phone_number;
	PhoneTypeEnum phone_type;
	StateEnum state;
};

#endif // USER_H
