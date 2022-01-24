CREATE DATABASE IF NOT EXISTS RxHelperDB;
USE RxHelperDB;

CREATE TABLE IF NOT EXISTS User (
    id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    username TEXT,
    password VARCHAR(50),
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    street_addr VARCHAR(100),
    city VARCHAR(50),
    zip_code VARCHAR(10),
    state VARCHAR(2),
    phone_number VARCHAR(10),
    phone_type VARCHAR(6),
    job_title VARCHAR(50)
); 

CREATE TABLE IF NOT EXISTS Patient (
    id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    age TINYINT UNSIGNED,
    age_unit VARCHAR(8),
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    street_addr VARCHAR(100),
    city VARCHAR(50),
    zip_code VARCHAR(10),
    state VARCHAR(2),
    phone_number VARCHAR(10),
    phone_type VARCHAR(6),
    insurance_name VARCHAR(50)
); 

CREATE TABLE IF NOT EXISTS Medication (
	id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    patient_id INT,
    FOREIGN KEY (patient_id) REFERENCES Patient(id),
    drug_name TEXT,
    description TEXT,
    dosage INT UNSIGNED,
    dosage_unit VARCHAR(20),
    time_num INT UNSIGNED,
    time_unit VARCHAR(8),
    price_dollars INT UNSIGNED,
    price_cents INT UNSIGNED
);