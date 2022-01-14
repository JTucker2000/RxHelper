#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <iostream>
#include <string>
#include "DoseUnitEnum.h"
#include "TimeUnitEnum.h"

namespace HelperFunctions
{
	// Takes in an std::string and returns its unsigned integer equivalient. 
	// Fails if there are any characters other than the digits.
	unsigned int stoui(std::string input);

	// Returns the std::string version of the given DoseUnitEnum.
	std::string duetostr(DoseUnitEnum d);

	// Returns the std::string version of the given TimeUnitEnum.
	std::string tuetostr(TimeUnitEnum t);
}

#endif // HELPERFUNCTIONS_H
