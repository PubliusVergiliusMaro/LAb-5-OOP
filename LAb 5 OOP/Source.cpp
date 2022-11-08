#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include "Header.h"

using namespace std;


void changeSize(Books& value) {//task 16
	value.size_b += 100;
}


int Librarian::objectCount = 0;

void Sum(Librarian a) {//11

	int sum;
	sum = 10 * a.Age;
	cout << sum << "\n\n";
}
void Sum(Librarian* a) {//12

	int sum;
	sum = 10 * a->Age;
	cout << sum << "\n\n";
}
Librarian createLibrarian() {//13
	Librarian li;
	li.setName("Name");
	li.setNumericData(19, 9999999, 4, 674);
	li.print();
	return li;
}

void Service(Books* object) {
	bool answer;

		cout << "Do you want to Read or Write file? Read = 0/Write = 1 /Skip = 2   : ";
		cin >> answer;
	
	switch (answer) {
	case 0:
		object->readFromFile();
		object->print();
	case 1:
		object->saveToFile();
	case 2:
		break;
	}
}

int main() {

	Human* human = new Librarian; 
	delete human;// task 3
	cout << "\n\n\n";

    Books *book = new Books;
	book->print();
	Service(book);//

	Librarian librarian_one_ = Librarian("Maks","Surname1","Patr1","UA",18,3131,2,123);//task 4
	//librarian_one_->myTask();
	
	Customer customer_one_ = Customer();
	
	//customer_one_->myTask();

	
	
	Human* p;

	p = &librarian_one_;

	p->myTask();
	
	p = &customer_one_;
	p->myTask();
	cout << "/////////"<<endl;
	YoungCustomer young_customer_one("Yaroslav", "Surname2", "Patr2", "UA");
	young_customer_one.myTask();//раннє(статичне)
	cout << "/////////" << endl;
    YoungCustomer young_cust_("Fomenich", "Surname3", "Patr3", "UA");//пізнє (динамічне) скріплення
	Human* ptr = &young_cust_;
	ptr -> myTask();
	
	 


	//bool answer;
	/*cout << "do you want to clear all objects (Yes = 1/No = 0) :";
	cin >> answer;
	if (answer == true) {
		delete librarian_one_;
			delete customer_one_;
		
	}*/

	//Customer 

	//Books bk;
	//bk.setBook("Name", "Athor", "Publisher");
	//bk.setGenre("LOve story");
	//bk.setNumb(1, 2, 3, 4);

	//Books b;
	//b.setBook("Ad", "Mi", "Ber");
	//b.setGenre("LO story");
	//b.setNumb(1, 2, 3, 4);

	//Librarian obj = Librarian("Oleg", "Redko", "Mykolayovich", "UA", 18, 960051185, 5, 5645);
	//obj.print();

	//Librarian ob = Librarian(obj);
	//ob.setName("aa", "bb", "cc");
	//ob.setBook(&bk);
	//ob.print();
	//Librarian o("Ol", "Re", "Mykoch", "UA", 18, 960051185, 5, 5645);
	//o.print();
	//Librarian a = Librarian();
	//a.setBook(&bk);
	//a.print();


	//cout << "TAsk 10" << endl;
	//cout << "Total objects: " << Librarian::objectCount << ".\n\n";

	//Librarian jbo;
	//cout << "TAsk 11" << endl;
	//jbo.Age = 18;
	//cout << jbo.Age << endl;
	//Sum(jbo);

	//Librarian* jb = new Librarian();
	//cout << "TAsk 12" << endl;
	//jb->Age = 18;
	//cout << jb->Age << endl;
	//Sum(*jb);

	//Librarian li;
	//cout << "tAsk 13" << endl;
	//createLibrarian();

	//cout << "Task 14" << endl;
	//Librarian A("Oleg", "Redko1", "Mykolayovich1", "UA", 181, 9600511851, 9, 56451);// prosti
	//Librarian B = Librarian("Oleg2", "Redko2", "Mykolayovich2", "UA", 182, 9600511852, 52, 56452);// Yavnuy
	//Librarian C;// scorocheniy
	//cout << "Short" << endl;
	//A.print();
	//cout << "Yavnuy" << endl;
	//B.print();
	//cout << "Scorocheniy" << endl;
	//C.print();

	//Customer* customer = new Customer("Maksim", "Fomenko", "Petrovich", " Ukr", 19, 1213138, 3, 4353);//("Maksim", "Fomenko", "Petrovich", 6662487247, 18, 3, "wqe", 453);

	//Books bko;
	//bko.setBook("A", "B", "C");
	//bko.setGenre("LOve story");
	//bko.setNumb(1, 2, 3, 4);
	//cout << "*******************************************************************************" << endl << "Task 15" << "\n" << "*******************************************************************************" << endl;
	//Librarian* libr = new Librarian("Oleg", "Redko", "Mykolayovich", "UA", 181, 9600511851, 51, 56451);
	//Catalog catalog("Catal", &bko);//Agregation
	//Library* library = new Library(libr, customer, &catalog);//Association
	//library->giveBook();

	//BookPackage package(" Worldwide Books");//Composition
	//Librarian obk;
	//obk.showBookPackage(&package);


	//LibraryBooks oby;//task 8
	//oby.setNumPrivate(1);
	//oby.setNumProtected(2);
	//oby.setNumPublic(3);
	//oby.displayNum();




	////task 9
	//BigBook bgbk = BigBook("name", "Anton", "Kolia", 12, 31, "genre", 331, 201);
	//smallBook jfd;
	////jfd.setI(4);
	//bgbk.showData();


	////task 10 
	//RegularCustomer custumer = RegularCustomer("Name111", " Redko", " Patronymic", "Ukr", 18, 4224242, 3, 3421);
	//custumer.display();


	////task 16
	//Books booken = Books("Name3", "Author3", "Publisher3", 4, 20000, "Novel", 4232, 203);
	//cout << "********** TASK 16**********" << endl;

	//cout << " Before change :" << booken.getSize() << endl;
	//changeSize(booken);
	//cout << " After change :" << booken.getSize() << endl;

	//// task 17
	////cout << "********** TASK 17**********" << endl;
	//chiefLibrarian obbj;
	//obbj.speak(A);

	////task 26





	return 0;
}









//void InsertSort(int arr[], int n)//12.
//{
//	cout << "\n\n" << "After sort";
//	int key, i;
//	for (int k = 1; k < n; k++) {
//		key = arr[k];
//		i = k - 1;
//		while ((i >= 0) && (arr[i] > key)) {
//			arr[i + 1] = arr[i];
//			i = i - 1;
//		}
//		arr[i + 1] = key;
//	}
//}
//void output(int arr[], int n) {//12.
//	cout << "Array" << endl;
//	for (int i = 0; i < n; i++)
//	{
//
//		cout << arr[i] << " ";
//	}
//}



//int main() {
//
//	////6. У програмі побудувати 5 об'єктів, розміщених у статичній пам’яті, та 5 об’єктів - у динамічній пам'яті. 
//
//	Customer* customer1 = new Customer();//dynamic data
//	Customer* customer2 = new Customer();
//	Customer* customer3 = new Customer();
//	Customer* customer4 = new Customer();
//	Customer* customer5 = new Customer();
//
//
//	Books book1;// static data
//	Books book2;
//	Books book3;
//	Books book4;
//	Books book5;
//	///// end 6
//	// 
//	////7. В основній програмі визначити 2 масиви об'єктів. 
//	Books books[5] = { book1,book2,book3,book4,book5 }; //1 masive of obj
//	Customer* customerArr[5]; // 2 massive of obj
//	customerArr[0] = customer1;
//	customerArr[1] = customer2;
//	customerArr[2] = customer3;
//	customerArr[3] = customer4;
//	customerArr[4] = customer5;
//
//
//
//	///end 7
//	srand(time(NULL));
//
//	///////8. Продемонструвати роботу з об’єктами, розміщеними в даному масиві.
//	///////9. Продемонструвати роботу усіх методів, описаних в класах
//	string namesOfbook[5] = {// Books
//		"C++/The Complete Reference Fourth Edition",
//		"C++ Programming Language",
//		"Diagnostic Pathology: Neuropathology",
//		"Focus on exams B2 ",
//		"Name" };
//	string authors[5] = {
//		"Herbert Schildt",
//		"Bjarne Stroustrup",
//		"B.K. Kleinschmidt-DeMasters",
//		"Bartosz Michalowski",
//		"Author" };
//	string publisher[5] = {
//		"McGraw-Hill",
//		"Addison Wesley",
//		"Elsevier Inc",
//		"Pearson",
//		"Publisher" };
//	string genre[5] = { "Handbook","Handbook","Atlas, Handbook","Manual","Genre" };
//
//	int num1[5]; for (int i = 0; i < 5; i++) num1[i] = 2000 + rand() % 20;
//	int num2[5]; for (int i = 0; i < 5; i++) num2[i] = rand() % 1000;
//	int num3[5]; for (int i = 0; i < 5; i++) num3[i] = rand() % 1000 + 9000;
//	int num4[5]; for (int i = 0; i < 5; i++) num4[i] = rand() % 1000;
//
//	cout << "************Books***************" << "\n\n\n";
//	for (int i = 0; i < 5; i++) {
//		cout << "Book #" << i + 1 << endl;
//		books[i].setBook(namesOfbook[i], authors[i], publisher[i]);
//		books[i].setGenre(genre[i]);
//		books[i].setNumb(num1[i], num2[i], num3[i], num4[i]);
//		cout << "\n";
//		books[i].print();
//		cout << "\n";
//	}
//
//	books[4].saveToFile();
//	Books bk;
//	bk = Books::readFromFile();
//	cout << "FRom File Book number 5" << endl;
//	bk.print();
//	cout << "\n\n" << "From File book but with pointer" << "\n";
//
//
//	//////////////////11. Показати в програмі використання покажчика на екземпляр класу.
//	Books* ptr = &bk;
//	ptr->print();
//	///////////////////end 11
//	cout << endl;
//	cout << "\n\n\n" << "************Customer***************" << "\n\n\n";
//	string namesOfCustomers[5] = { "Oleg","John","Michael","Conor","Yaroslav" };
//	string surname[5] = { "Redko","Smith","Brown","Anthony","Tkachuck" };
//	string patronimic[5] = { "Mykolayovich","Johnson","Peterson","Gregorson","Oleksandrovich" };
//	string nationality[5] = { "UA","USA","UK","GER","UA" };
//
//	int year[5]; for (int i = 0; i < 5; i++) year[i] = rand() % 10;
//	int age[5]; for (int i = 0; i < 5; i++) age[i] = rand() % 90;
//	int phone[5]; for (int i = 0; i < 5; i++)phone[i] = 1 + rand() % 1000000 + 9000000;
//	int id[5]; for (int i = 0; i < 5; i++) id[i] = rand() % 10000;
//
//	for (int i = 0; i < 5; i++) {
//		customerArr[i]->setName(namesOfCustomers[i], surname[i], patronimic[i]);
//		customerArr[i]->setNation(nationality[i]);
//		customerArr[i]->setAge(age[i]);
//		customerArr[i]->setExp(year[i]);
//		customerArr[i]->setPhone(phone[i]);
//		customerArr[i]->setId(id[i]);
//		customerArr[i]->print();
//	}
//	customerArr[4]->saveToFile();
//	Customer cstmr;
//	cstmr = Customer::readFromFile();
//	cout << "From file Customer number 5" << endl;
//	cstmr.print();
//	cout << endl;
//	cout << "/********************/" << endl;
//	cout << endl;
//	////end 8
//	///end 9
//
//	//10. Продемонструвати сценарій взаємодії двох об’єктів (наприклад маємо два класи: студент і книга, тоді
//	//необхідно показати, як студент купує книгу)
//	cout << "Customer get book" << endl;
//	Books prog;
//	prog.setBook("My System", "Aron Nimzowitsch", "Franz Eher Nachfolger GmbH");
//	prog.setGenre("Documental");
//	prog.setNumb(2000, 15000, 1234567, 200);
//
//	Customer cust;
//	cust.setName("Oleg", "Redko", "Mykolayovich");
//	cust.setAge(18);
//	cust.setExp(2);
//	cust.setNation("Ukranian");
//	cust.setPhone(960251185);
//	cust.setId(rand() % 1000 + 9000);
//	cust.setBook(&prog);
//	cust.print();
//	cout << endl;
//
//	///////// end 10 
//
//	////12. Визначити додатковий метод в класі, який виділяє випадкову величину динамічної пам’яті. В пам’яті
//	//розмістити множину значень одного з цілочисельних полів та відсортувати їх
//	cout << "\n\n\n" << "Sort random array..................................." << endl;
//	int* mas = Customer::randMemory();
//	int n = 0;
//	while (mas[n] >= 0 && mas[n] <= 90)
//		n++;
//	cout << "\n";
//	output(mas, n);
//	InsertSort(mas, n);
//	cout << "\n";
//	output(mas, n);
//	return 0;//end 12
//
//
//}