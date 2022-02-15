#include "DatabaseFunctions.h"

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

void DatabaseFunctions::removeMedicationDatabase(unsigned int id)
{
	if (id == 0) return;

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
