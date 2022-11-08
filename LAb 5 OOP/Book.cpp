#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;

BookFromPackage::BookFromPackage() {};
BookFromPackage::BookFromPackage(BookPackage* bookes, string Bookname) {
	cout << "Book" << endl;
	arrbook = bookes;
	if (NULL != arrbook) {
		nameBook_b = Bookname;
	}
	else cout << " Book Package is not created" << endl;
}
void BookFromPackage::display() {
	cout << "Book :" << nameBook_b << endl;
}

BookFromPackage::~BookFromPackage() {
	cout << "Destroy book"<<endl;
}