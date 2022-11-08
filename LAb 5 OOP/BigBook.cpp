#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;

void BigBook::setData(string name, string author, string publisher, int year, int circulation, string genre, int serialnum, int size) {
	nameBook_b = name;
	author_b = author;
	publisher_b = publisher;
	year_b = year;
	circulation_b = circulation;
	Genre_b = genre;
	serialNum_b = serialnum;
	size_b = size;
}
BigBook::BigBook() {};
BigBook::BigBook(string name, string author, string publisher, int year, int circulation, string genre, int serialnum, int size) {
	nameBook_b = name;
	author_b = author;
	publisher_b = publisher;
	year_b = year;
	circulation_b = circulation;
	Genre_b = genre;
	serialNum_b = serialnum;
	size_b = size;
}
void BigBook::showData() {
	cout << "*****Task 9*******" << endl;
	cout << "I data from previous class :" << getI() << endl;
	cout << "Book name :" << nameBook_b << endl;
	cout << "Book author :" << author_b << endl;
}
BigBook::~BigBook() {

}