#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;
Library::Library(Librarian* l, Customer* cus, Catalog* cat) :
	librarian(l), customer(cus), catalog(cat) {
	cout << "Customer " << this->customer->name_human << " comes to Library" << endl;
	cout << "Today in our libary works " << this->librarian->Name << endl;
	cout << "This month katalog of library have name " << catalog->getBookName() << endl;
	cout << "Librarian have got new book, it`s name is " << catalog->getBookName() << endl;
};
void Library::giveBook() {
	cout << "After a few minutes, " << customer->name_human << " decided, that he want to take " << catalog->getBookName()
		<< " librarian " << librarian->Name << " make notice in his notebook and give it for him." << endl;
}
Library::~Library() {

}