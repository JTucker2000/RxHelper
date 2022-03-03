# RxHelper (Work in progress)
An application that allows pharmacists to easily view, add, or modify patient information.

## --- About ---
I was inspired to work on this project partly because I am currently working part-time at a CVS Pharmacy.
As a part of my job, I give customers their prescriptions which have been prepared by the pharmacist.
If you could interact with their system, you would think that the designers of the software were trying
to make it as unintuitive as possible to use. So, that in combination with me already trying to find something to
create led to me choosing to make a pharmacy application.

## --- Technologies ---
This application is being built using the following:
- C++14
- MySQL Server 8.0, Workbench 8.0, Connector C++ 8.0
- wxWidgets 3.1.5

## --- How to build ---
Currently, the easiest way to build this project would be to compile the source code (not including the .sql files)
linked with the wxWidgets 3.1.5 and MySQL Connector C++ 8.0 libraries. The application will build and run in this state,
but most of its functionality comes from being connected to a MySQL database. I have provided .sql files which can be used
to create a local database (using MySQL Server 8.0) in the same format as the program requires. There is also a .sql file
which will load test values into the database.

## --- Current goals ---
I would consider these remaining goals to be the bare minimum of what needs to be done in order to consider this project finished.
Once these are completed, I will likely continue to improve the application and add new features.

These goals are listed in the order in which they will be completed.
- Add the ability to create new accounts
- Refactor disorganized / repetative code
