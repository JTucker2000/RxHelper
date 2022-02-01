#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <iostream>
#include <string>
#include "DoseUnitEnum.h"
#include "TimeUnitEnum.h"
#include "PhoneTypeEnum.h"

namespace HelperFunctions
{
	// Takes in an std::string and returns its unsigned integer equivalient. 
	// Fails if there are any characters other than the digits.
	unsigned int stoui(std::string input);

	// Returns the std::string version of the given DoseUnitEnum.
	std::string duetostr(DoseUnitEnum d);

	// Converts an std::string into a DoseUnitEnum.
	DoseUnitEnum strtodue(std::string input);

	// Returns the std::string version of the given TimeUnitEnum.
	std::string tuetostr(TimeUnitEnum t);

	// Converts an std::string into a TimeUnitEnum.
	TimeUnitEnum strtotue(std::string input);

	// Converts an std::string into a PhoneTypeEnum.
	PhoneTypeEnum strtopte(std::string input);

	// Converts the given dollars and cents unsigned integers into a price formatted std::string.
	std::string pricetostr(unsigned int dollars, unsigned int cents);

	// Converts an std::string into an unsigned int, where the last first two digits are the cents.
	// Ex. input = "$99.23", returns 9923
	unsigned int strtoprice(std::string input);
}

#endif // HELPERFUNCTIONS_H
