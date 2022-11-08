#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;


void Human::setNation(string nation) { nationality_human = nation; }

string  Human::getName() { return name_human; }
string  Human::getSurname() { return surname_human; }
string  Human::gePatronymic() { return patronymic_human; }
int  Human::getAge() { return age_human; }
int  Human::getPhone() { return phone_human; }
int  Human::getId() { return id_human; }
string  Human::getNation() { return nationality_human; }
int  Human::getExp() { return year_human; }
Human::Human() {
	
};
Human::~Human() {

}
void Human::myTask() {

}

