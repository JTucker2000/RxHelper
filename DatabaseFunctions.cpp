#include "DatabaseFunctions.h"

void DatabaseFunctions::addPatientToDatabase(Patient* p)
{
	if (p == nullptr)
	{
		wxLogDebug("Warning: Nullptr in addPatientToDatabase(). Unable to add patient to database.");
		return;
	}

	sql::Driver* driver = nullptr;
	sql::Connection* con = nullptr;
	sql::PreparedStatement* p_stmt = nullptr;
	sql::ResultSet* res = nullptr;

	try
	{
		driver = get_driver_instance(); // Insert patient into the database.
		con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
		con->setSchema("RxHelperDB");
		p_stmt = con->prepareStatement("INSERT INTO patient(age, age_unit, first_name, last_name, street_addr, city, zip_code, state, phone_number, phone_type, insurance_name) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);");
		p_stmt->setInt(1, p->getAge());
		p_stmt->setString(2, HelperFunctions::tuetostr(p->getAgeUnit()));
		p_stmt->setString(3, p->getFirstName());
		p_stmt->setString(4, p->getLastName());
		p_stmt->setString(5, p->getStreetAddr());
		p_stmt->setString(6, p->getCity());
		p_stmt->setString(7, p->getZipCode());
		p_stmt->setString(8, p->getState());
		p_stmt->setString(9, p->getPhoneNum());
		p_stmt->setString(10, HelperFunctions::ptetostr(p->getPhoneType()));
		p_stmt->setString(11, p->getInsuranceName());
		delete(p_stmt->executeQuery());
		delete(p_stmt);

		p_stmt = con->prepareStatement("SELECT LAST_INSERT_ID();"); // Update patient's ID.
		res = p_stmt->executeQuery();
		res->next();
		p->setUniqueID(res->getUInt(1));

		for (int i = 0; i < p->getMedList()->size(); i++) // Put all of the patient's medications into the database.
		{
			DatabaseFunctions::addMedicationToDatabase(p->getMedList()->at(i), p);
		}
	}
	catch (sql::SQLException& e)
	{
		wxLogDebug(e.what());
	}

	delete con;
	delete p_stmt;
	delete res;
}

void DatabaseFunctions::modifyPatientInDatabase(Patient* p)
{
	if (p == nullptr)
	{
		wxLogDebug("Warning: Nullptr in modifyPatientInDatabase(). Unable to modify patient in database.");
		return;
	}

	sql::Driver* driver = nullptr;
	sql::Connection* con = nullptr;
	sql::PreparedStatement* p_stmt = nullptr;
	sql::ResultSet* res = nullptr;

	try
	{
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
		con->setSchema("RxHelperDB");
		p_stmt = con->prepareStatement("UPDATE patient SET age = ?, age_unit = ?, first_name = ?, last_name = ?, street_addr = ?, city = ?, zip_code = ?, state = ?, phone_number = ?, phone_type = ?, insurance_name = ? WHERE id = ?;");
		p_stmt->setInt(1, p->getAge());
		p_stmt->setString(2, HelperFunctions::tuetostr(p->getAgeUnit()));
		p_stmt->setString(3, p->getFirstName());
		p_stmt->setString(4, p->getLastName());
		p_stmt->setString(5, p->getStreetAddr());
		p_stmt->setString(6, p->getCity());
		p_stmt->setString(7, p->getZipCode());
		p_stmt->setString(8, p->getState());
		p_stmt->setString(9, p->getPhoneNum());
		p_stmt->setString(10, HelperFunctions::ptetostr(p->getPhoneType()));
		p_stmt->setString(11, p->getInsuranceName());
		p_stmt->setUInt(12, p->getUniqueID());
		delete(p_stmt->executeQuery());
	}
	catch (sql::SQLException& e)
	{
		wxLogDebug(e.what());
	}

	delete con;
	delete p_stmt;
	delete res;
}

void DatabaseFunctions::removePatientFromDatabase(unsigned int id)
{
	if (id == 0)
	{
		wxLogDebug("Warning: 0 ID in removePatientFromDatabase(). Unable to remove patient from database.");
		return;
	}

	sql::Driver* driver = nullptr;
	sql::Connection* con = nullptr;
	sql::PreparedStatement* p_stmt = nullptr;

	try
	{
		driver = get_driver_instance(); // Start by deleting all medications associated with the patient.
		con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
		con->setSchema("RxHelperDB");
		p_stmt = con->prepareStatement("DELETE FROM medication WHERE patient_id = ?");
		p_stmt->setUInt(1, id);
		delete(p_stmt->executeQuery());
		delete p_stmt;

		p_stmt = con->prepareStatement("DELETE FROM patient WHERE id = ?"); // Then delete the patient.
		p_stmt->setUInt(1, id);
		delete(p_stmt->executeQuery());
	}
	catch (sql::SQLException& e)
	{
		wxLogDebug(e.what());
	}

	delete con;
	delete p_stmt;
}

void DatabaseFunctions::addMedicationToDatabase(Medication* m, Patient* p)
{
	if ((m == nullptr) || (p == nullptr))
	{
		wxLogDebug("Warning: Nullptr in addMedicationToDatabase(). Unable to add medication to database.");
		return;
	}

	sql::Driver* driver = nullptr;
	sql::Connection* con = nullptr;
	sql::PreparedStatement* p_stmt = nullptr;
	sql::ResultSet* res = nullptr;

	try
	{
		driver = get_driver_instance(); // Insert medication into the database.
		con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
		con->setSchema("RxHelperDB");
		p_stmt = con->prepareStatement("INSERT INTO medication(patient_id, drug_name, description, dosage, dosage_unit, time_num, time_unit, price_dollars, price_cents) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?);");
		p_stmt->setUInt64(1, p->getUniqueID());
		p_stmt->setString(2, m->getDrugName());
		p_stmt->setString(3, m->getDescription());
		p_stmt->setUInt(4, m->getDosage());
		p_stmt->setString(5, HelperFunctions::duetostr(m->getDosageUnit()));
		p_stmt->setUInt(6, m->getTimeNum());
		p_stmt->setString(7, HelperFunctions::tuetostr(m->getTimeUnit()));
		p_stmt->setUInt(8, m->getPriceDollars());
		p_stmt->setUInt(9, m->getPriceCents());
		delete(p_stmt->executeQuery());
		delete(p_stmt);

		p_stmt = con->prepareStatement("SELECT LAST_INSERT_ID();"); // Update medication's ID.
		res = p_stmt->executeQuery();
		res->next();
		m->setUniqueID(res->getUInt(1));
	}
	catch (sql::SQLException& e)
	{
		wxLogDebug(e.what());
	}

	delete con;
	delete p_stmt;
	delete res;
}

void DatabaseFunctions::modifyMedicationInDatabase(Medication* m)
{
	if (m == nullptr)
	{
		wxLogDebug("Warning: Nullptr in modifyMedicationInDatabase(). Unable to modify medication in database.");
		return;
	}

	sql::Driver* driver = nullptr;
	sql::Connection* con = nullptr;
	sql::PreparedStatement* p_stmt = nullptr;
	sql::ResultSet* res = nullptr;

	try
	{
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
		con->setSchema("RxHelperDB");
		p_stmt = con->prepareStatement("UPDATE medication SET drug_name = ?, description = ?, dosage = ?, dosage_unit = ?, time_num = ?, time_unit = ?, price_dollars = ?, price_cents = ? WHERE id = ?;");
		p_stmt->setString(1, m->getDrugName());
		p_stmt->setString(2, m->getDescription());
		p_stmt->setUInt(3, m->getDosage());
		p_stmt->setString(4, HelperFunctions::duetostr(m->getDosageUnit()));
		p_stmt->setUInt(5, m->getTimeNum());
		p_stmt->setString(6, HelperFunctions::tuetostr(m->getTimeUnit()));
		p_stmt->setUInt(7, m->getPriceDollars());
		p_stmt->setUInt(8, m->getPriceCents());
		p_stmt->setUInt(9, m->getUniqueID());
		delete(p_stmt->executeQuery());
	}
	catch (sql::SQLException& e)
	{
		wxLogDebug(e.what());
	}

	delete con;
	delete p_stmt;
	delete res;
}

void DatabaseFunctions::removeMedicationFromDatabase(unsigned int id)
{
	if (id == 0)
	{
		wxLogDebug("Warning: 0 ID in removeMedicationFromDatabase(). Unable to remove medication from database.");
		return;
	}

	sql::Driver* driver = nullptr;
	sql::Connection* con = nullptr;
	sql::PreparedStatement* p_stmt = nullptr;

	try
	{
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
		con->setSchema("RxHelperDB");
		p_stmt = con->prepareStatement("DELETE FROM medication WHERE id = ?");
		p_stmt->setUInt(1, id);
		delete(p_stmt->executeQuery());
	}
	catch (sql::SQLException& e)
	{
		wxLogDebug(e.what());
	}

	delete con;
	delete p_stmt;
}

void DatabaseFunctions::addUserToDatabase(User* u)
{
	if (u == nullptr)
	{
		wxLogDebug("Warning: Nullptr in addUserToDatabase(). Unable to add user to database.");
		return;
	}

	sql::Driver* driver = nullptr;
	sql::Connection* con = nullptr;
	sql::PreparedStatement* p_stmt = nullptr;
	sql::ResultSet* res = nullptr;

	try
	{
		driver = get_driver_instance(); // Insert user into the database.
		con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
		con->setSchema("RxHelperDB");
		p_stmt = con->prepareStatement("INSERT INTO user(username, password, first_name, last_name, street_addr, city, zip_code, state, phone_number, phone_type, job_title) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);");
		p_stmt->setString(1, u->getUsername());
		p_stmt->setString(2, u->getPassword());
		p_stmt->setString(3, u->getFirstName());
		p_stmt->setString(4, u->getLastName());
		p_stmt->setString(5, u->getStreetAddr());
		p_stmt->setString(6, u->getCity());
		p_stmt->setString(7, u->getZipCode());
		p_stmt->setString(8, u->getState());
		p_stmt->setString(9, u->getPhoneNum());
		p_stmt->setString(10, HelperFunctions::ptetostr(u->getPhoneType()));
		p_stmt->setString(11, u->getJob());
		delete(p_stmt->executeQuery());
		delete(p_stmt);

		p_stmt = con->prepareStatement("SELECT LAST_INSERT_ID();"); // Update user's ID.
		res = p_stmt->executeQuery();
		res->next();
		u->setUniqueID(res->getUInt(1));
	}
	catch (sql::SQLException& e)
	{
		wxLogDebug(e.what());
	}

	delete con;
	delete p_stmt;
	delete res;
}

void DatabaseFunctions::modifyUserInDatabase(User* u)
{
	if (u == nullptr)
	{
		wxLogDebug("Warning: Nullptr in modifyUserInDatabase(). Unable to modify user in database.");
		return;
	}

	sql::Driver* driver = nullptr;
	sql::Connection* con = nullptr;
	sql::PreparedStatement* p_stmt = nullptr;
	sql::ResultSet* res = nullptr;

	try
	{
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
		con->setSchema("RxHelperDB");
		p_stmt = con->prepareStatement("UPDATE user SET username = ?, password = ?, first_name = ?, last_name = ?, street_addr = ?, city = ?, zip_code = ?, state = ?, phone_number = ?, phone_type = ?, job_title = ? WHERE id = ?;");
		p_stmt->setString(1, u->getUsername());
		p_stmt->setString(2, u->getPassword());
		p_stmt->setString(3, u->getFirstName());
		p_stmt->setString(4, u->getLastName());
		p_stmt->setString(5, u->getStreetAddr());
		p_stmt->setString(6, u->getCity());
		p_stmt->setString(7, u->getZipCode());
		p_stmt->setString(8, u->getState());
		p_stmt->setString(9, u->getPhoneNum());
		p_stmt->setString(10, HelperFunctions::ptetostr(u->getPhoneType()));
		p_stmt->setString(11, u->getJob());
		p_stmt->setUInt(12, u->getUniqueID());
		delete(p_stmt->executeQuery());
	}
	catch (sql::SQLException& e)
	{
		wxLogDebug(e.what());
	}

	delete con;
	delete p_stmt;
	delete res;
}

void DatabaseFunctions::removeUserFromDatabase(unsigned int id)
{
	if (id == 0)
	{
		wxLogDebug("Warning: 0 ID in removeUserFromDatabase(). Unable to remove user from database.");
		return;
	}

	sql::Driver* driver = nullptr;
	sql::Connection* con = nullptr;
	sql::PreparedStatement* p_stmt = nullptr;

	try
	{
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
		con->setSchema("RxHelperDB");
		p_stmt = con->prepareStatement("DELETE FROM user WHERE id = ?");
		p_stmt->setUInt(1, id);
		delete(p_stmt->executeQuery());
	}
	catch (sql::SQLException& e)
	{
		wxLogDebug(e.what());
	}

	delete con;
	delete p_stmt;
}
