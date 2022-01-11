#include "Medication.h"

Medication::Medication() : unique_id(-1)
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

Medication::Medication(unsigned int id, std::string drugname, std::string desc, unsigned int dose, DoseUnitEnum doseunit,
	unsigned int time, TimeUnitEnum timeunit, unsigned int priced, unsigned int pricec) : unique_id(id) // TODO: Generate unique IDs for each medication, patient, and user. Hardcoded for now.
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

const unsigned int Medication::getUniqueID() { return unique_id; }

Medication::~Medication()
{

}