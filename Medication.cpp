#include "Medication.h"

Medication::Medication()
{
	unique_id = 0;
	drug_name = "";
	description = "";
	dosage = 0;
	dosage_unit = DoseUnitEnum::milligrams;
	time_num = 0;
	time_unit = TimeUnitEnum::minutes;
	price_dollars = 0;
	price_cents = 0;
}

Medication::Medication(unsigned int id, std::string drugname, std::string desc, unsigned int dose, DoseUnitEnum doseunit,
	unsigned int time, TimeUnitEnum timeunit, unsigned int priced, unsigned int pricec)
{
	unique_id = id;
	drug_name = drugname;
	description = desc;
	dosage = dose;
	dosage_unit = doseunit;
	time_num = time;
	time_unit = timeunit;
	price_dollars = priced;
	price_cents = pricec;
}

unsigned int Medication::getUniqueID() { return unique_id; }
std::string Medication::getDrugName() { return drug_name; }
std::string Medication::getDescription() { return description; }
unsigned int Medication::getDosage() { return dosage; }
unsigned int Medication::getTimeNum() { return time_num; }
unsigned int Medication::getPriceDollars() { return price_dollars; }
unsigned int Medication::getPriceCents() { return price_cents; }
DoseUnitEnum Medication::getDosageUnit() { return dosage_unit; }
TimeUnitEnum Medication::getTimeUnit() { return time_unit; }

Medication::~Medication()
{

}