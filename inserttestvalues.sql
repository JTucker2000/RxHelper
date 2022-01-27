INSERT INTO patient(age, age_unit, first_name, last_name, street_addr, city, zip_code, state, phone_number, phone_type, insurance_name)
VALUES
(55, "Years", "David", "Yelps", "23 Wonton Road", "Berton", "73425", "NH", "6573427598", "Mobile", "Medicare"),
(34, "Years", "Josh", "Repertson", "4664 Main Ave", "Dallas", "91356", "TX", "7244522345", "Mobile", "None"),
(15, "Years", "Mary", "Burke", "4 Tenee Street", "Lexington", "22456", "NY", "2634539686", "Mobile", "Cigna"),
(80, "Years", "Winston", "Hillchurch", "16 Berry Road", "Miami", "15462", "FL", "5418115538", "Home", "Small Insurance Company");

INSERT INTO medication(patient_id, drug_name, description, dosage, dosage_unit, time_num, time_unit, price_dollars, price_cents)
VALUES
(1, "Morphine", "Pain reducer", 30, "milligrams", 8, "hours", 50, 0),
(1, "Pepto", "Relieves indigestion", 50, "milliliters", 2, "hours", 12, 99),
(1, "Prozac", "Antidepressant", 25, "milligrams", 8, "hours", 75, 50),
(2, "Prozac", "Antidepressant", 25, "milligrams", 8, "hours", 75, 50),
(2, "Pepto", "Relieves indigestion", 50, "milliliters", 2, "hours", 12, 99),
(3, "Morphine", "Pain reducer", 30, "milligrams", 8, "hours", 50, 0),
(4, "Prozac", "Antidepressant", 25, "milligrams", 8, "hours", 75, 50),
(4, "Morphine", "Pain reducer", 30, "milligrams", 8, "hours", 50, 0),
(4, "Pepto", "Relieves indigestion", 50, "milliliters", 2, "hours", 12, 99);