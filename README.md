# RxHelper
A Windows application that allows users to easily view, search, add, or modify patient information.

## --- About ---
I was inspired to work on this project because I am currently working part-time at a CVS Pharmacy.
As a part of my job, I give customers prescriptions which have been prepared by a pharmacist.
It gave me the idea to try and create my own pharmacy-based application. The final product I've
created doesn't have much real world functionality; but it did teach me a lot about Windows application
development and databases. The program takes patient data from a MySQL database and displays it as shown
in the screenshots below. Since I don't have access to any real patient information, the patients can
be added by running a provided script that inputs test values. Alternatively, the user can add patients
inside the program directly. The user also has the ability to modify existing information, search through
the patient list, add medications to a patient, and more.

## --- Screenshots ---

![RxHelperScreenshot1](https://user-images.githubusercontent.com/91383127/181661556-d0cec518-a64c-4add-a7dc-11f8727fcacf.PNG)
![RxHelperScreenshot2](https://user-images.githubusercontent.com/91383127/181661567-7bb4939f-2a0f-4f66-8a33-a199fa0d5c0b.PNG)
![RxHelperScreenshot3](https://user-images.githubusercontent.com/91383127/181661572-7bfb900b-edb4-414b-a133-43b0cf0a5193.PNG)


## --- Technologies ---
This application was built using the following:
- C++14
- MySQL Server 8.0, Workbench 8.0, Connector C++ 8.0
- wxWidgets 3.1.5

## --- How to build ---
The easiest way to build this project is to compile the source code (not including the .sql files) linked with the
wxWidgets 3.1.5 and MySQL Connector C++ 8.0 libraries. The application will build and run in this state, but most of 
its functionality comes from being connected to a MySQL database. I have provided .sql files which can be used
to create a local database (using MySQL Server 8.0) in the same format as the program requires. There is also a .sql file
which will load test values into the database.
