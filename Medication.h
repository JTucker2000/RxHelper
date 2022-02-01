#ifndef MEDICATION_H
#define MEDICATION_H

#include <string>
#include "DoseUnitEnum.h"
#include "TimeUnitEnum.h"

class Medication
{
public:
	Medication();
	Medication(unsigned int id, std::string drugname, std::string desc, unsigned int dose, DoseUnitEnum doseunit,
		unsigned int time, TimeUnitEnum timeunit, unsigned int priced, unsigned int pricec);

	unsigned int getUniqueID();
	std::string getDrugName();
	std::string getDescription();
	unsigned int getDosage();
	unsigned int getTimeNum();
	unsigned int getPriceDollars();
	unsigned int getPriceCents();
	DoseUnitEnum getDosageUnit();
	TimeUnitEnum getTimeUnit();

	~Medication();

private:
	unsigned int unique_id;
	std::string drug_name;
	std::string description;
	unsigned int dosage;
	DoseUnitEnum dosage_unit;
	unsigned int time_num;
	TimeUnitEnum time_unit;
	unsigned int price_dollars; // All prices are in USD for now.
	unsigned int price_cents;
};

#endif // MEDICATION_H
