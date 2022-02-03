#include "HelperFunctions.h"

unsigned int HelperFunctions::stoui(std::string input)
{
	unsigned int sum = 0;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] < '0' || input[i] > '9') 
		{
			std::cout << "Error: String cannot be converted into unsigned int. Exiting." << std::endl;
			exit(-1);
		}

		sum *= 10;
		sum += (input[i] - '0');
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

DoseUnitEnum HelperFunctions::strtodue(std::string input)
{
	std::string cur_word = "";

	for (int i = 0; i < input.size() && i < 11; i++) // Break at 11, largest DoseUnitEnum word contains 11 letters.
	{
		cur_word += input[i];

		if (cur_word == "milligrams" || cur_word == "Milligrams" || cur_word == "MILLIGRAMS")
		{
			return DoseUnitEnum::milligrams;
		}
		else if (cur_word == "milliliters" || cur_word == "Milliliters" || cur_word == "MILLILITERS")
		{
			return DoseUnitEnum::milliliters;
		}
	}

	std::cout << "Error: Invalid string in strtodue. Exiting." << std::endl;
	exit(-1);
}

std::string HelperFunctions::tuetostr(TimeUnitEnum t)
{
	std::string ans;
	switch (t)
	{
	case TimeUnitEnum::years:
		ans = "years";
		return ans;
		break;
	case TimeUnitEnum::months:
		ans = "months";
		return ans;
		break;
	case TimeUnitEnum::weeks:
		ans = "weeks";
		return ans;
		break;
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

TimeUnitEnum HelperFunctions::strtotue(std::string input)
{
	std::string cur_word = "";

	for (int i = 0; i < input.size() && i < 7; i++) // Break at 7, largest TimeUnitEnum word contains 7 letters.
	{
		cur_word += input[i];

		if (cur_word == "days" || cur_word == "Days" || cur_word == "DAYS")
		{
			return TimeUnitEnum::days;
		}
		else if (cur_word == "years" || cur_word == "Years" || cur_word == "YEARS")
		{
			return TimeUnitEnum::years;
		}
		else if (cur_word == "weeks" || cur_word == "Weeks" || cur_word == "WEEKS")
		{
			return TimeUnitEnum::weeks;
		}
		else if (cur_word == "hours" || cur_word == "Hours" || cur_word == "HOURS")
		{
			return TimeUnitEnum::hours;
		}
		else if (cur_word == "months" || cur_word == "Months" || cur_word == "MONTHS")
		{
			return TimeUnitEnum::months;
		}
		else if (cur_word == "minutes" || cur_word == "Minutes" || cur_word == "MINUTES")
		{
			return TimeUnitEnum::minutes;
		}
	}

	std::cout << "Error: Invalid string in strtotue. Exiting." << std::endl;
	exit(-1);
}

PhoneTypeEnum HelperFunctions::strtopte(std::string input)
{
	std::string cur_word = "";

	for (int i = 0; i < input.size() && i < 6; i++) // Break at 6, largest PhoneTypeEnum word contains 6 letters.
	{
		cur_word += input[i];

		if (cur_word == "home" || cur_word == "Home" || cur_word == "HOME")
		{
			return PhoneTypeEnum::Home;
		}
		else if (cur_word == "mobile" || cur_word == "Mobile" || cur_word == "MOBILE")
		{
			return PhoneTypeEnum::Mobile;
		}
		else if (cur_word == "other" || cur_word == "Other" || cur_word == "OTHER")
		{
			return PhoneTypeEnum::Other;
		}
	}

	std::cout << "Error: Invalid string in strtopte. Exiting." << std::endl;
	exit(-1);
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

unsigned int HelperFunctions::strtoprice(std::string input)
{
	unsigned int str_size = input.size();

	if ((str_size < 5) || (input[0] != '$')) // Invalid if not atleast size of '$0.00' or does not have '$' as first char.
	{
		wxMessageBox("Price is not formatted correctly. Defaults to $0.00.");
		return 0;
	}

	unsigned int p_dollars = 0;
	int i;
	for (i = 1; (i < str_size) && (input[i] != '.'); i++) // Get dollar amount by parsing string until decimal point.
	{
		if ((i == (str_size - 1)) || ((input[i] < '0') || (input[i] > '9'))) // Invalid if no decimal is reached or char isn't a digit.
		{
			wxMessageBox("Price is not formatted correctly. Defaults to $0.00.");
			return 0;
		}

		p_dollars *= 10;
		p_dollars += (input[i] - '0');
	}
	i++; // Get past the '.' char.

	unsigned int p_cents = 0;
	if ((input[str_size - 1] < '0') || (input[str_size - 1] > '9') || (input[str_size - 2] < '0') || (input[str_size - 2] > '9')) // Invalid if last two chars aren't digits.
	{
		wxMessageBox("Price is not formatted correctly. Defaults to $0.00.");
		return 0;
	}
	p_cents += (input[str_size - 2] - '0') * 10;
	p_cents += (input[str_size - 1] - '0');

	return (p_dollars * 100) + p_cents;
}