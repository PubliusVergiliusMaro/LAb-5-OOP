#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;
YoungCustomer::YoungCustomer(string name, string surname, string patron, string nation) {
	name_human = name;
	surname_human = surname;
	patronymic_human = patron;
	nationality_human = nation;
}
string YoungCustomer::getName() { return name_human; }

YoungCustomer::YoungCustomer() {

}
void YoungCustomer::myTask() {
	cout << getName() << " buy books about superheroes." << endl;
}
YoungCustomer::~YoungCustomer() {
	cout << getName() << " has been kicked" << endl;
}