#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;

void LibraryBooks::setNumPrivate(int num) { num1 = num; }
void LibraryBooks::setNumProtected(int num) { num2 = num; }
void LibraryBooks::setNumPublic(int num) { num3 = num; }
void LibraryBooks::displayNum() {
	cout << " ***** Task 8 ***** " << endl;
	cout << " Num Private : " << num1 << endl;
	cout << " Num Protected : " << num2 << endl;
	cout << " Num Public : " << num3 << endl;

}
LibraryBooks::LibraryBooks() {
	//cout << "Create Book from library. " << endl;
}
LibraryBooks::~LibraryBooks() {
	//cout << "Destroy Book from library." << endl;
}