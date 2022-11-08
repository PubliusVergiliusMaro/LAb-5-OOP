#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;
void chiefLibrarian::speak(Librarian& l) {
	cout << "************* Task 17 **********" << endl;
	cout << " Today become a data when our librarian " << l.Name << " works in our library already " << l.year_l + 1 << " year, congratulations" << endl;
}
void chiefLibrarian::myTask() {
	

		cout << getName() << " is main Librarian \n";


}
