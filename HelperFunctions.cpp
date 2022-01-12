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