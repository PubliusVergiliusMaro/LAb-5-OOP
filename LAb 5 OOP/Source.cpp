#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include "Header.h"

#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iterator>
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

bool operator== (Customer& c1, Customer& c2)
{
	return (c1.year_human == c2.year_human);
}

bool operator!= (Customer& c1,  Customer& c2)
{
	return (c1.age_human != c2.age_human);
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
	}
}

void showq(queue<Customer> gq)
{
	queue<Customer> g = gq;
	while (!g.empty()) {
		cout << "==================================================================================" << endl;
		g.front().print();
		cout << "==================================================================================" << endl;
		g.pop();
	}
	cout << '\n';
}

int main() {

	
	Human* human = new Librarian; 
	delete human;// task 3
	cout << "\n\n\n";

    Books *book = new Books;
	book->print();
	//Service(book);//

	Librarian librarian_one_ = Librarian("Maks","Surname1","Patr1","UA",18,3131,2,123);//task 4
	Customer customer_one_ = Customer();
	
	Human* p;

	p = &librarian_one_;

	p->myTask();
	
	p = &customer_one_;
	p->myTask();

	cout << "/////////////"<<endl;
	Customer customer_two_ = Customer();
	RegularCustomer customer_regular_ = RegularCustomer("Name4", "Surname1", "Patr1", "UA", 18, 3131, 2, 123);
	Librarian librarian_two_ = Librarian();
	

	Human* potr = &customer_two_;
	potr->myTask();

	potr = (Human*)&customer_regular_;
	potr->myTask();

	potr = (Human*)&librarian_two_;
	potr->myTask();

	cout << "//////////////////////"<<endl;
	cout << "/////////"<<endl;
	YoungCustomer young_customer_one("Yaroslav", "Surname2", "Patr2", "UA");
	young_customer_one.myTask();//раннє(статичне)
	cout << "/////////" << endl;
    YoungCustomer young_cust_("Fomenich", "Surname3", "Patr3", "UA");//пізнє (динамічне) скріплення
	Human* ptr = &young_cust_;
	ptr->myTask();
	
	cout << "//////////////////////" << endl;
	cout << "/////////" << endl;
	BigBook booke("name", "Anton", "Kolia", 12, 31, "genre", 331, 201);
	//MyClass <int> Object;
	//Object.changeData(1000, 2000, &booke);
	booke.showData();
	cout << "//////////////////////" << endl;
	cout << "/////////" << endl;
	Books bk;
	bk.setBook("Name", "Athor", "Publisher");
	bk.setGenre("LOve story");
	bk.setNumb(1, 2, 3, 4);

	Books b;
	b.setBook("Ad", "Mi", "Ber");
	b.setGenre("LO story");
	b.setNumb(1, 2, 3, 4);

	Librarian obj = Librarian("Oleg", "Redko", "Mykolayovich", "UA", 18, 960051185, 5, 5645);
	obj.print();

	Librarian ob = Librarian(obj);
	ob.setName("aa", "bb", "cc");
	ob.setBook(&bk);
	ob.print();
	Librarian o("Ol", "Re", "Mykoch", "UA", 18, 960051185, 5, 5645);
	o.print();
	Librarian a = Librarian();
	a.setBook(&bk);
	a.print();


	cout << "TAsk 10" << endl;
	cout << "Total objects: " << Librarian::objectCount << ".\n\n";

	Librarian jbo;
	cout << "TAsk 11" << endl;
	jbo.Age = 18;
	cout << jbo.Age << endl;
	Sum(jbo);

	Librarian* jb = new Librarian();
	cout << "TAsk 12" << endl;
	jb->Age = 18;
	cout << jb->Age << endl;
	Sum(*jb);

	Librarian li;
	cout << "tAsk 13" << endl;
	createLibrarian();

	cout << "Task 14" << endl;
	Librarian A("Oleg", "Redko1", "Mykolayovich1", "UA", 181, 9600511851, 9, 56451);// prosti
	Librarian B = Librarian("Oleg2", "Redko2", "Mykolayovich2", "UA", 182, 9600511852, 52, 56452);// Yavnuy
	Librarian C;// scorocheniy
	cout << "Short" << endl;
	A.print();
	cout << "Yavnuy" << endl;
	B.print();
	cout << "Scorocheniy" << endl;
	C.print();

	Customer* customer = new Customer("Maksim", "Fomenko", "Petrovich", " Ukr", 19, 1213138, 3, 4353);//("Maksim", "Fomenko", "Petrovich", 6662487247, 18, 3, "wqe", 453);

	Books bko;
	bko.setBook("Abook", "Bboko", "Centuria");
	bko.setGenre("LOve story");
	bko.setNumb(1, 2, 3, 4);
	cout << "*******************************************************************************" << endl << "Task 15" << "\n" << "*******************************************************************************" << endl;
	Librarian* libr = new Librarian("Oleg", "Redko", "Mykolayovich", "UA", 181, 9600511851, 51, 56451);
	Catalog catalog("Catal", &bko);//Agregation
	Library* library = new Library(libr, customer, &catalog);//Association
	library->giveBook();

	BookPackage package(" Worldwide Books");//Composition
	Librarian obk;
	obk.showBookPackage(&package);


	LibraryBooks oby;//task 8
	oby.setNumPrivate(1);
	oby.setNumProtected(2);
	oby.setNumPublic(3);
	oby.displayNum();




	//task 9
	BigBook bgbk = BigBook("name", "Anton", "Kolia", 12, 31, "genre", 331, 201);
	smallBook jfd;
	//jfd.setI(4);
	bgbk.showData();


	//task 10 
	RegularCustomer custumer = RegularCustomer("Name111", " Redko", " Patronymic", "Ukr", 18, 4224242, 3, 3421);
	custumer.display();


	//task 16
	Books booken = Books("Name3", "Author3", "Publisher3", 4, 20000, "Novel", 4232, 203);
	cout << "********** TASK 16**********" << endl;

	cout << " Before change :" << booken.getSize() << endl;
	changeSize(booken);
	cout << " After change :" << booken.getSize() << endl;

	// task 17
	//cout << "********** TASK 17**********" << endl;
	chiefLibrarian obbj;
	obbj.speak(A);

	cout << "/*******************************/";
	int num = 10;
	int sizeOfBook = booken.getSize();
	cout <<"We add "<<num<< " to "<<sizeOfBook<< " and we got = " << booken.getSum(sizeOfBook, num) << endl;

	


	cout << "\n\n/*******************************/"<<endl;
	Books book_nine;
	
	MyClass <int> myClass(1,2,3,4);
	myClass.changeData();

	MyClass <Books> info(book_nine);
	info.getSize();
	cout << "/*******************************/" << endl;

	cout << "\n\n/*******************************/" << endl;
	cout << "TASK 1 " << endl;
	Customer customer_ten_;
	cout << "Our Number :" << customer_ten_.getAge() << endl;
	
	++customer_ten_;
	
	cout << "Increment :" << customer_ten_.getAge() << endl;
	
	customer_ten_--;
	
	cout << "Decrement :" << customer_ten_.getAge() << endl;
	cout << "\n\n/*******************************/" << endl;
	++customer_ten_;
	cout << "TASK 2 " << endl;
	Customer custom,resSum,resSub;
	resSum = custom + customer_ten_;
	resSub = custom - customer_ten_;
	cout << "Sum : " << custom.getAge() << " + " << customer_ten_.getAge() << " = " <<resSum.getAge()<<endl;
	cout << "Subtraction : " << custom.getAge() << " - " << customer_ten_.getAge() << " = " << resSub.getAge()<<"; "
		<<custom.getExp() << " - " << customer_ten_.getExp() << " = " << resSub.getExp()<<endl;

	Customer customer_twenty_one;
	Customer customer_twenty_two;
	cout << "Numbers :" << customer_twenty_one.getExp() << ", " << customer_twenty_two.getExp() << endl;
	
	if (customer_twenty_one == customer_twenty_one)cout << "Numbers are the same" << endl;
	else cout << "Numbers are not the same" << endl;


	cout << "\n\n/*******************************/" << endl;
	Customer cusstomer;
	cusstomer.setName("Angelina","Tkachuck","Petrivna");
	
    //////Vector
	vector <Customer> arr_Customers_one;
	arr_Customers_one.push_back(custom);
	arr_Customers_one.push_back(customer_ten_);
	arr_Customers_one.push_back(customer_twenty_two);
	
	vector<Customer>::iterator iter_one;
	iter_one = arr_Customers_one.begin();
	arr_Customers_one.insert(iter_one, cusstomer);

	for (int i = 0; i < arr_Customers_one.size(); i++)
		arr_Customers_one.at(i).print();
	
	arr_Customers_one.clear();
	
	/////// List
	list <string> arr_Customers_two;
	arr_Customers_two.push_back("Oleg");
	arr_Customers_two.push_back("Anatoliy");
    arr_Customers_two.push_back("Yaroslav");
	list <string>::iterator iter_two;
	iter_two = arr_Customers_two.begin();
	arr_Customers_two.insert(iter_two, "Oksana");

	for (iter_two = arr_Customers_two.begin(); iter_two != arr_Customers_two.end(); iter_two++)
		cout << *iter_two << endl;

	arr_Customers_two.clear();
 

	////// Stack 
	stack<double> arrOfNum;
	arrOfNum.push(1.0);
	arrOfNum.push(2.0);
	arrOfNum.push(3.0);
	arrOfNum.push(4.0);
    arrOfNum.push(5.0);
	arrOfNum.emplace(6.0);

	
	while (!arrOfNum.empty()) {
		cout << arrOfNum.top() << " "<<endl;
		arrOfNum.pop();

	}
	cout << "\n\n\n\n";

	///// Queue
	queue<Customer> queueInLibrary;
	queueInLibrary.push(custom);
	queueInLibrary.push(customer_ten_);
	queueInLibrary.push(customer_twenty_two);
	
	cout << "==================================================================================" << endl;
	cout << "|| Today our Library get new books and there people that want to take such book:|| " << endl;
	cout << "==================================================================================" << endl;
	showq(queueInLibrary);



	cout << "Functors :" << endl;///////////////////////////
	vector<int> Arr_one_;
	Arr_one_.push_back(5);
	Arr_one_.push_back(4);
	Arr_one_.push_back(3);
	Arr_one_.push_back(2);
	Arr_one_.push_back(1);
	
	vector<int> Arr_two_ = {1,2,3,4,5};
	vector<int> Result;
	vector<int>::iterator Iterator;

    cout << "arr1" << endl;
	for (int k : Arr_one_) cout << k << " "; cout << endl;
	
	cout << "arr2" << endl;
	for (int k : Arr_two_) cout << k << " "; cout << endl;
	int answer_one_;

	cout << "Select what you want to do(enter following number): Plus/1 , Minus/2 , Times/3 , Divides/4 , Module/5 , Negate/6 : ";
	
	Result.resize(5);
	cin >> answer_one_;
	switch (answer_one_) {
	case 1:
		cout << "You select Plus" << endl;
		transform(Arr_one_.begin(), Arr_one_.begin() + 5, Arr_two_.begin(), Result.begin(), Func_Plus());
		for (int k : Result) cout << k << " "; cout << endl;
		break;
	case 2:
		cout << "You select Minus" << endl;
		transform(Arr_one_.begin(), Arr_one_.begin() + 5, Arr_two_.begin(), Result.begin(), Func_minus());
		for (int k : Result) cout << k << " "; cout << endl;
		break;
	case 3:
		cout << "You select Times" << endl;
		transform(Arr_one_.begin(), Arr_one_.begin() + 5, Arr_two_.begin(), Result.begin(), Func_multiplication());
		for (int k : Result)cout << k << " "; cout << endl;
		break;
	case 4:
		cout << "You select Divides" << endl;
		transform(Arr_two_.begin(), Arr_two_.begin() + 5, Arr_one_.begin(), Result.begin(), Func_divides());
		for (int k : Result)cout << k << " "; cout << endl;
		break;
	case 5:
		cout << "You select Modulus" << endl;
		transform(Arr_one_.begin(), Arr_one_.begin() + 5, Arr_two_.begin(), Result.begin(), Func_module());
		for (int k : Result) cout << k << " "; cout << endl;
		break;
	case 6:
		cout << "You select Negate" << endl;
		cout << "Arr 1: ";
		transform(Arr_one_.begin(), Arr_one_.begin() + 5, Result.begin(), Func_negative());
		for (int k : Result)cout << k << " ";
	}
	cout << endl;
	cout << endl;
	cout << endl;

	

	vector<int> Arr_one_one_;
	for (int i = 1; i <= 5; i++)
	Arr_one_one_.push_back(i);
	vector<int> Arr_two_two_ = { 1,1,4,5,3 };
	vector<int> Result_two;
	cout << "Int arr 1" << endl;
	for (int k : Arr_one_one_)cout << k << " ";cout << endl;
	cout << "Int arr 2" << endl;
	for (int k : Arr_two_two_)cout << k << " ";cout << endl;
	Result_two.resize(5);
	int answer_two_;
	
	cout << "Select what you want to do(enter following number): Equal to/1 , Not equal to/2 , Bigger/3 , Less/4 , Bigger equal/5 , Less equal/6 : ";
	cin >> answer_two_;
	switch (answer_two_) {
	case 1:
		cout << "You select Equal to" << endl;
		transform(Arr_one_one_.begin(), Arr_one_one_.begin() + 5, Arr_two_two_.begin(), Result_two.begin(), Func_equalTo());
		for (int k : Result_two)cout << k << " "; cout << endl;
		break;
	case 2:

		cout << "You select Not Equal to" << endl;
		transform(Arr_one_one_.begin(), Arr_one_one_.begin() + 5, Arr_two_two_.begin(), Result_two.begin(), Func_notEqualTo());
		for (int k : Result_two)cout << k << " "; cout << endl;
		break;
	case 3:

		cout << "You select Bigger" << endl;
		transform(Arr_one_one_.begin(), Arr_one_one_.begin() + 5, Arr_two_two_.begin(), Result_two.begin(), Func_bigger());
		for (int k : Result_two)cout << k << " "; cout << endl;
		break;
	case 4:

		cout << "You select Less" << endl;
		transform(Arr_one_one_.begin(), Arr_one_one_.begin() + 5, Arr_two_two_.begin(), Result_two.begin(), Func_less());
		for (int k : Result_two)cout << k << " "; cout << endl;
		break;
	case 5:

		cout << "You select Bigger Equal" << endl;
		transform(Arr_one_one_.begin(), Arr_one_one_.begin() + 5, Arr_two_two_.begin(), Result_two.begin(), Func_biggerEqual());
		for (int k : Result_two)cout << k << " "; cout << endl;
		break;
	case 6:

		cout << "You select Less Equal" << endl;
		transform(Arr_one_one_.begin(), Arr_one_one_.begin() + 5, Arr_two_two_.begin(), Result_two.begin(), Func_lessEqual());
		for (int k : Result_two)cout << k << " "; 
		break;
	}
		
	cout << endl;
	cout << endl;
	cout << endl;
	vector<bool> BoolArr;
	BoolArr.push_back(true);
	BoolArr.push_back(true);
	BoolArr.push_back(true);
	BoolArr.push_back(false);
	BoolArr.push_back(false);
	vector<bool> BoolArr_two = { false,false,true,false,true };
	vector<bool> result2;
	result2.resize(5);
	
		cout << "Bool arr 1" << endl;
		for (int k : BoolArr) cout << k << " "; cout << endl;
		
		cout << "Bool arr 2" << endl;
		for (int k : BoolArr_two) cout << k << " "; cout << endl;
	
		int answer_three_;
   
	cout << "Select what you want to do(enter following number): Logiacl AND/1 , Logical OR/2 , Logical NOT/3 :";
	cin >> answer_three_;
	
	switch (answer_three_) {
	case 1:
		cout << "You select Logical AND :";
		transform(BoolArr.begin(), BoolArr.begin() + 5, BoolArr_two.begin(), result2.begin(), Func_logicalAnd());
		for (int k : result2) cout << k << " "; cout << endl;
		break;
	case 2:
		cout << "You select Logical OR :";
		transform(BoolArr.begin(), BoolArr.begin() + 5, BoolArr_two.begin(), result2.begin(), Func_logicalOr());
		for (int k : result2) cout << k << " "; cout << endl;
		break;
	case 3:
		cout << "You select Logical NOT :";
		transform(BoolArr.begin(), BoolArr.begin() + 5, result2.begin(), Func_LogicalNot());
		for (int k : result2) cout << k << " "; cout << endl;
		break;
	}
	cout << endl;
	cout << endl;
	cout << endl;


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