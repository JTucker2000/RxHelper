#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <iostream>
#include <string>

namespace HelperFunctions
{
	// Takes in an std::string and returns its unsigned integer equivalient. 
	// Fails if there are any characters other than the digits.
	unsigned int stoui(std::string input);
}

#endif // HELPERFUNCTIONS_H
