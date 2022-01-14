#include "HelperFunctions.h"

unsigned int HelperFunctions::stoui(std::string input)
{
	unsigned int sum = 0;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] >= '0' && input[i] <= '9') 
		{
			sum += (input[i] - '0');
		}
		else 
		{
			std::cout << "Error: String cannot be converted into unsigned int. Exiting." << std::endl;
			exit(-1);
		}
	}

	return sum;
}

std::string HelperFunctions::duetostr(DoseUnitEnum d)
{
	std::string ans;
	switch (d)
	{
	case DoseUnitEnum::milligrams:
		ans = "milligrams";
		return ans;
		break;
	case DoseUnitEnum::milliliters:
		ans = "milliliters";
		return ans;
		break;
	default:
		std::cout << "Error: Invalid DoseUnitEnum in duetostr. Exiting." << std::endl;
		exit(-1);
	}
}

std::string HelperFunctions::tuetostr(TimeUnitEnum t)
{
	std::string ans;
	switch (t)
	{
	case TimeUnitEnum::days:
		ans = "days";
		return ans;
		break;
	case TimeUnitEnum::hours:
		ans = "hours";
		return ans;
		break;
	case TimeUnitEnum::minutes:
		ans = "minutes";
		return ans;
		break;
	default:
		std::cout << "Error: Invalid TimeUnitEnum in tuetostr. Exiting." << std::endl;
		exit(-1);
	}
}

std::string HelperFunctions::pricetostr(unsigned int dollars, unsigned int cents)
{
	if (cents > 99) return "Error: pricetostr cents value over 99.";

	std::string cents_str;
	if (cents < 10)
	{
		cents_str = "0" + std::to_string(cents);
	}
	else
	{
		cents_str = std::to_string(cents);
	}
	std::string price_str = "$" + std::to_string(dollars) + "." + cents_str;
	
	return price_str;
}