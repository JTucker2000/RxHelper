#include "Medication.h"

Medication::Medication()
{
	drug_name = "";
	description = "";
	dosage = 0;
	dosage_unit = DoseUnitEnum::milligrams;
	time_num = 0;
	time_unit = TimeUnitEnum::minutes;
	price_dollars = 0;
	price_cents = 0;
}

Medication::Medication(std::string drugname, std::string desc, unsigned int dose, DoseUnitEnum doseunit,
	unsigned int time, TimeUnitEnum timeunit, unsigned int priced, unsigned int pricec)
{
	drug_name = drugname;
	description = desc;
	dosage = dose;
	dosage_unit = dosage_unit;
	time_num = time;
	time_unit = timeunit;
	price_dollars = priced;
	price_cents = pricec;
}

Medication::~Medication()
{

}