#ifndef MEDICATION_H
#define MEDICATION_H

#include <string>

class Medication
{
public:
	Medication();
	Medication(std::string drugname, unsigned int dose, unsigned int priced, unsigned int pricec);
	~Medication();

private:
	std::string drug_name;
	unsigned int dosage;
	// Add dosage unit enum.
	unsigned int price_dollars; // All prices are in USD for now.
	unsigned int price_cents;
};

#endif // MEDICATION_H
