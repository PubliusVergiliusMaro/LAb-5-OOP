#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;


Catalog::Catalog(string n, Books* b) {
	cout << "Catalog" << endl;
	name_catalog = n;
	book = b;
}
string Catalog::getBookName() {
	return book->getBookName();
}
Catalog::~Catalog() {

};