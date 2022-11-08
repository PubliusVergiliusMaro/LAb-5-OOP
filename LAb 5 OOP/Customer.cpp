#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;
void Customer::myTask() {
	
		cout << getName() << " buy books\n";
	
}
void Customer::setName(string name) { name_human = name; }
void Customer::setName(string name, string surname) { name_human = name; surname_human = surname; }
void Customer::setName(string name, string surname, string patronymic)
{
	name_human = name; surname_human = surname; patronymic_human = patronymic;
}
void Customer::setNation(string nation) { nationality_human = nation; }
void Customer::setAge(int age) { age_human = age; }
void Customer::setPhone(int phone) { phone_human = phone; }
void Customer::setExp(int year) { year_human = year; }
void Customer::setId(int id) { id_human = id; }

string Customer::getCustomerName() { return name_human; }

void Customer::print() {
	cout << "Customer data: " << endl;
	cout << " Full name : " << name_human << " " << surname_human << " " << patronymic_human << endl;
	cout << " Phone number : +380" << phone_human << endl;

	cout << " Age : " << age_human << " y.o" << endl;
	cout << " Member since " << year_human << " year " << endl;
	cout << "Nationality " << nationality_human << endl;
	cout << "ID: " << id_human << endl;
	//cout << " Book of the student :" << "\n";
	//printBook();
	cout << "\n";
}
Customer::Customer():Customer("Kolya", "Semenyuk","Oleksandrovich", "UA",18,14133,3,5342) {
	//name_human = "Kolya";
	//surname_human = "Semenyuk";
	//patronymic_human = "Oleksandrovich";
	//nationality_human = "UA";
	//age_human = 18;
	//phone_human = 5342422;
	//year_human = 3;
	//id_human = 6654321;

	cout << "Create " << name_human << endl;
};
Customer::Customer(string name, string surname, string patro, string nation, int age, int phone, int year, int id)
{
	name_human = name;
	surname_human = surname;
	patronymic_human = patro;
	nationality_human = nation;
	age_human = age;
	phone_human = phone;
	year_human = year;
	id_human = id;

	cout << "Create " << name_human << endl;

}
Customer::~Customer()
{
	cout << "Kill "<<getName() << endl;
}
void Customer::saveToFile() {


	ofstream file_save("customer.txt", ios::out);
	file_save << name_human << endl;
	file_save << surname_human << endl;
	file_save << patronymic_human << endl;
	file_save << age_human << endl;
	file_save << nationality_human << endl;
	file_save << year_human << endl;
	file_save << id_human << endl;
}