#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;

BookPackage::BookPackage(string name) {
	Name = name;

	BookFromPackage::BookMass(bookList);
	BookFromPackage* book;
	BookFromPackage::createBook(book, this, "Name1");
	bookList[0] = book;
	BookFromPackage::createBook(book, this, "Name2");
	bookList[1] = book;
	BookFromPackage::createBook(book, this, "Name3");
	bookList[2] = book;
	BookFromPackage::createBook(book, this, "Name4");
	bookList[3] = book;
	BookFromPackage::createBook(book, this, "Name5");
	bookList[4] = book;

}
void BookPackage::display() {
	cout << "Name of the catalog " << Name << endl;

	cout << " Books details " << endl;
	for (int i = 0; i < 5; i++) {

		bookList[i]->display();

	}


}
BookPackage::~BookPackage() {
	for (int i = 0; i < 5; i++) {

		delete(bookList[i]);

	}
	cout << "Destroy bookPackage" << endl;
}