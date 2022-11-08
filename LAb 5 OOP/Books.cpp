#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;


void Books::setBook(string nameBook) { nameBook_b = nameBook; }
void Books::setBook(string nameBook, string author) { nameBook_b = nameBook, author_b = author; }
void Books::setBook(string nameBook, string author, string publisher) { nameBook_b = nameBook, author_b = author, publisher_b = publisher; }
void Books::setGenre(string genre) { Genre_b = genre; }
void Books::setNumb(int year, int circulation, int serialNum, int size) { year_b = year, circulation_b = circulation, serialNum_b = serialNum, size_b = size; }
string Books::getBookName() { return nameBook_b; }
int Books::getSize() { return size_b; }

Books::Books() {
	nameBook_b = "name";
	author_b = "author";
	publisher_b = "publisher";
	year_b = 12345;
	circulation_b = 123;
	Genre_b = "genre";
	serialNum_b = 7685;
	size_b = 4234;
};
Books::Books(string name, string author, string publisher, int year, int circulation, string genre, int serialnum, int size) {
	nameBook_b = name;
	author_b = author;
	publisher_b = publisher;
	year_b = year;
	circulation_b = circulation;
	Genre_b = genre;
	serialNum_b = serialnum;
	size_b = size;
}
Books::~Books()
{

}
void Books::print() {
	cout << " Books data " << endl;
	cout << " Name of book : " << nameBook_b << endl;
	cout << " Author of book : " << author_b << endl;
	cout << " Publisher of book : " << publisher_b << endl;
	cout << " Year of publishing : " << year_b << " year" << endl;
	cout << " Circulation of a book : " << circulation_b << " od" << endl;
	cout << " Genre of a book : " << Genre_b << endl;
	cout << " Serial Number : " << serialNum_b << endl;
	cout << " Size of a book : " << size_b << " pages" << endl;
}

void Books::saveToFile() {
	ofstream file_in("books.txt", ios::out);
	file_in << nameBook_b << endl;
	file_in << author_b << endl;
	file_in << publisher_b << endl;
	file_in << year_b << endl;
	file_in << circulation_b << endl;
	file_in << Genre_b << endl;
	file_in << serialNum_b << endl;
	file_in << size_b << endl;
	file_in.close();
}

