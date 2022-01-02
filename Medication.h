#ifndef MEDICATION_H
#define MEDICATION_H

#include <string>
#include "DoseUnitEnum.h"

class Medication
{
public:
	Medication();
	Medication(std::string drugname, unsigned int dose, DoseUnitEnum doseunit, unsigned int priced, unsigned int pricec);
	~Medication();

private:
	std::string drug_name;
	unsigned int dosage;
	DoseUnitEnum dosage_unit;
	unsigned int price_dollars; // All prices are in USD for now.
	unsigned int price_cents;
};

#endif // MEDICATION_H
