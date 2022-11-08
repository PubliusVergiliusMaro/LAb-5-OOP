
#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;

void Librarian::myTask() {
	cout << getName() << " sold books\n";
}
void Librarian::setName(string name) { Name = name, Surname = "unknown", Patron = "unknown"; }
void Librarian::setName(string name, string surname) {
	Name = name, Surname = surname, Patron = "unknown";
}
void Librarian::setName(string name, string surname, string patronymic)
{
	Name = name, Surname = surname, Patron = patronymic;
}
void Librarian::setNation(string nation) { nationality_human = nation; }
void Librarian::setAge(int age) { Age = age; }
void Librarian::setPhone(int phone) { phone = phone; }
void Librarian::setExp(int experience) { year_l = experience; }
void Librarian::setId(int id) { id_l = id; }
string Librarian::getName() { return Name; }
void Librarian::setNumericData(int age, int phone, int year, int id) {
	nationality_human = "Ukr";
	Age = age;
	Phone = phone;
	year_l = year;
	id_l = id;
}
void Librarian::print() {

	cout << "Customer data: " << endl;
	cout << " Full name : " << Name << " " << Surname << " " << Patron << endl;
	cout << " Phone number : +380" << Phone << endl;
	cout << " Age : " << Age << " y.o" << endl;
	cout << "Work here for " << year_l << " year " << endl;
	cout << "Nationality " << nationality_human << endl;
	cout << "ID: " << id_l << endl;
	cout << " Book of the student :" << "\n";
	printBook();
	cout << "\n";
}
void Librarian::print(int val) {

	cout << "Librarian " << Name << " have book :" << book->getBookName() << ", and Librarian give this book to " << custom->getCustomerName();
	cout << "Librarian data: " << endl;
	cout << " Full name : " << Name << " " << Surname << " " << Patron << endl;
	cout << " Phone number : +380" << Phone << endl;
	cout << " Age : " << Age << " y.o" << endl;
	cout << " Work here for " << year_l << " year " << endl;
	cout << "Nationality " << nationality_human << endl;
	cout << "ID: " << id_l << endl;
	//cout << " Book of the student :" << "\n";
	printCustomer();
	printBook();
	cout << "\n";
}
void Librarian::setBook(Books* b) { book = b; }


Librarian::Librarian() :Name("Anton"), Surname("Grechka"), Patron("Konstantinovich"), nationality_human("GER"), Age(19), Phone(757873), year_l(3), id_l(123456), book(nullptr) {
	objectCount++; //cout << book;
	cout << "Create " << Name << endl;

};
Librarian::Librarian(string name, string surname, string patronymic, string nation, int age, int phone, int experience, int id)
	:Name{ name }, Surname{ surname }, Patron{ patronymic }, nationality_human{ nation }, Age{ age }, Phone{ phone }, year_l{ experience }, id_l{ id }, book(nullptr)
{

	cout << "Create " << Name << endl;
	objectCount++;
};
Librarian::Librarian(string name, string surname, string patronymic, string nation, int age, int phone, int experience, int id, Books* b, Customer* c) :
	Name{ name }, Surname{ surname }, Patron{ patronymic }, nationality_human{ nation }, Age{ age }, Phone{ phone }, year_l{ experience }, id_l{ id }, book(nullptr), custom(nullptr) {
	book = b;
	custom = c;
	cout << "Create " << Name << endl;
	objectCount++;
}
Librarian::Librarian(string name, string surname, string patronymic, string nation, int age, int phone, int experience, int id, const Books& boo) :
	Name{ name }, Surname{ surname }, Patron{ patronymic }, nationality_human{ nation }, Age{ age }, Phone{ phone }, year_l{ experience }, id_l{ id }, book(nullptr) {
	bo = boo;

	cout << "Create " << Name << endl;
	objectCount++;
}   
Librarian::Librarian(const Librarian& p1)
	:Name(p1.Name), Surname(p1.Surname), Patron(p1.Patron), nationality_human(p1.nationality_human), Age(p1.Age), Phone(p1.Phone), year_l(p1.year_l), id_l(p1.id_l)
{
	objectCount++;
	cout << "Create " << Name << endl;
};



void Librarian::giveBook(Books* book) {
	book->print();

}
void Librarian::showBookPackage(BookPackage* package) {
	package->display();
}
void Librarian::printCustomer() {
	if (custom != 0) {
		custom->print();
	}
	else cout << "...";
}
void Librarian::printBook() {
	if (book != 0) {
		book->print();
	}
	else cout << "...";
}

Librarian::~Librarian() {
	cout << Name << " is deleted" << endl;

}