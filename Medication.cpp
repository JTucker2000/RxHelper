#include "Medication.h"

Medication::Medication()
{
	drug_name = "";
	dosage = 0;
	price_dollars = 0;
	price_cents = 0;
}

Medication::Medication(std::string drugname, unsigned int dose, unsigned int priced, unsigned int pricec)
{
	drug_name = drugname;
	dosage = dose;
	price_dollars = priced;
	price_cents = pricec;
}

Medication::~Medication()
{

}