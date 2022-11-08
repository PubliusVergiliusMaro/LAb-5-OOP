#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;
OldCustomer::OldCustomer(int age, int phone, int year, int id)
{
	age_human = age;
	phone_human = phone;
	year_human = year;
	id_human = id;
}

OldCustomer::~OldCustomer() {

}