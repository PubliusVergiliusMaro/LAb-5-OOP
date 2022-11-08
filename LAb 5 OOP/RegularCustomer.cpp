#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;
void RegularCustomer::myTask() {
	cout << getName() << " buy books regularly.";
}
RegularCustomer::RegularCustomer(string name, string surname, string patronymic, string nation, int age, int phone, int year, int id) :
	YoungCustomer(name, surname, patronymic, nation), OldCustomer(age, phone, year, id) {	}



void RegularCustomer::display() {
	cout << "****** Task 10 ********* " << endl;
	cout << "Name :" << YoungCustomer::getName() << endl;
	cout << "Surname :" << YoungCustomer::getSurname() << endl;
	cout << "Patronymic :" << YoungCustomer::gePatronymic() << endl;
	cout << "Age :" << OldCustomer::getAge() << endl;
	cout << "Nation :" << YoungCustomer::getNation() << endl;
	cout << "Phone :" << OldCustomer::getPhone() << endl;
	cout << "Expirience :" << OldCustomer::getExp() << endl;
	cout << "Id :" << OldCustomer::getId() << endl;
	cout << " \n\n\n\n" << endl;
}

RegularCustomer::~RegularCustomer() {

}