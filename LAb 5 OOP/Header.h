#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <vector>

using namespace std;



class Library;
class Librarian;
class Books;
class Customer;
class BookPackage;
class BookFromPackage;
class chiefLibrarian;
class Catalog;
class YoungCustomer;
class OldCustomer;
class RegularCustomer;
class SmallBook;
class BigBook;

//////////Huma
class Human {
protected:
	string nationality_human;
	int year_human;
	int age_human;
	int phone_human;
	int id_human;

public:
	string name_human;
	string surname_human;
	string patronymic_human;

	void setNation(string nation);

	

	string  getName();
	string getSurname();
	string gePatronymic();
	int getAge();
	int getPhone();
	int getId();
	string getNation();
	int getExp();

	Human();
	virtual ~Human();

	virtual void myTask()=0;
};
class LibraryBooks {
private:
	int num1;
protected:

	string  nameBook_b;
	string  author_b;
	string  publisher_b;
	string  Genre_b;
	int year_b;
	int circulation_b;

	int serialNum_b;
	int size_b;

	int num2;
public:
	int num3;

	void setNumPrivate(int num);
	void setNumProtected(int num);
	void setNumPublic(int num);
	void displayNum();
	LibraryBooks();
	virtual ~LibraryBooks();
};

class Books :public LibraryBooks {

public:
	friend void changeSize(Books& value);
    
	
	template <typename T> T getSum(T data,T addNumber) {
		return data+addNumber;
	}




	void setBook(string nameBook);
	void setBook(string nameBook, string author);
	void setBook(string nameBook, string author, string publisher);
	void setGenre(string genre);
	void setNumb(int year, int circulation, int serialNum, int size);


	string getBookName();
	int getSize();
	Books();
	Books(string name, string author, string publisher, int year, int circulation, string genre, int serialnum, int size);
	~Books()override;
	void print();

	void saveToFile();
	
	void readFromFile() {
		ifstream file_out;
		file_out.exceptions(ifstream::badbit | ifstream::failbit);
		string path = "boks.txt";
		try {
			cout << "\nTry to open File" << endl;
			file_out.open(path);
			cout << "File succesfuly open!\n" << endl;	
		
		file_out >> nameBook_b;
		file_out >> author_b;
		file_out >> publisher_b;
		file_out >> year_b;
		file_out >> circulation_b;
		file_out >> Genre_b;
		file_out >> serialNum_b;
		file_out >> size_b;

		}
		catch(const std::exception&ex){
			cout << ex.what() << endl;
			cout << "Error with openning file! " << endl;
		}
	
		file_out.close();
	}


};


class BookFromPackage :public LibraryBooks {
private:
	BookPackage* arrbook;


public:
	BookFromPackage();
	static void createBook(BookFromPackage* (&book), BookPackage* bookes, string name) {
		book = new BookFromPackage(bookes, name);
	}
	BookFromPackage(BookPackage* bookes, string Bookname);
	void display();
	static void BookMass(BookFromPackage* (&booksList)[5]) { booksList[5] = new BookFromPackage; }


	~BookFromPackage()override;
};
class BookPackage {
private:
	BookFromPackage* bookList[5];

	string Genre;
	string publisher;
	string Name;
public:
	
	BookPackage(string name);
	void display();
	~BookPackage();
};



class Customer : public virtual Human {

private:

	Customer* arr;
public:

	Customer& operator++() {
		++age_human;
		return *this;
	};
	Customer operator--(int) {
		Customer temp = *this;
		--age_human;
		return temp;
	};
	Customer operator + (Customer &B) {
		Customer A;
		A.age_human = age_human + B.age_human;
		return (A);
	}
	
	Customer operator - (Customer &B) {
		Customer A;
		A.age_human = age_human - B.age_human;

		A.year_human = year_human - B.year_human;
		return (A);
	}
	Customer& operator += (Customer c2)
	{
		age_human += c2.age_human;
		return *this;
	}
	Customer& operator[](const int index) {
		return arr[index];
	}


	friend bool operator== ( Customer& c1,  Customer& c2);
	friend bool operator!= ( Customer& c1,  Customer& c2);
	



	void setName(string name);
	void setName(string name, string surname);
	void setName(string name, string surname, string patronymic);
	void setNation(string nation);
	void setAge(int age);
	void setPhone(int phone);
	void setExp(int year);
	void setId(int id);

	string getCustomerName();
	
	void myTask()override;

	void print();
	Customer();
	Customer(string name, string surname, string patro, string nation, int age, int phone, int year, int id);
	~Customer()override;
	void saveToFile();
	
	void readFromFile() {
		ifstream file_out;
		file_out.exceptions(ifstream::badbit | ifstream::failbit);
		string path = "customer.txt";
		try {
			cout << "\nTry to open File" << endl;
			file_out.open(path);
			cout << "File succesfuly open!\n" << endl;
			file_out >> name_human;
			file_out >> surname_human;
			file_out >> patronymic_human;
			file_out >> age_human;
			file_out >> nationality_human;
			file_out >> year_human;
			file_out >> id_human;


		}

	
	catch (const std::exception& ex) {
		cout << ex.what() << endl;
		cout << "Error with openning file! " << endl;
	}

	file_out.close();
	}

	static int* randMemory() {
		int m = 5 + rand() % 20;
		int* ptr = new int[m];
		for (int i = 0; i < m; i++)
			ptr[i] = rand() % 90;
		return ptr;

	}
};



class Librarian : public virtual Human {

private:
	friend chiefLibrarian;
	string nationality_human;
	int year_l;
	int id_l;
	Books* book;
	BookPackage* package;
	Books bo;
	Customer* custom;
public:

	string Name;
	string Surname;
	string Patron;
	int Age;
	int Phone;
	static int objectCount;


	void setName(string name);
	void setName(string name, string surname);
	void setName(string name, string surname, string patronymic);
	void setNation(string nation);
	void setAge(int age);
	void setPhone(int phone);
	void setExp(int year);
	void setId(int id);
	string getName();
	void setNumericData(int age, int phone, int year, int id);
	void print();
	void print(int val);
	void setBook(Books* b);
	void myTask()override;
	Librarian();
	Librarian(string name, string surname, string patronymic, string nation, int age, int phone, int year, int id);
	Librarian(string name, string surname, string patronymic, string nation, int age, int phone, int year, int id, Books* b, Customer* c);
	Librarian(string name, string surname, string patronymic, string nation, int age, int phone, int year, int id, const Books& boo);
	Librarian(const Librarian& p1);



	void giveBook(Books* book);
	void showBookPackage(BookPackage* package);
	void printCustomer();
	void printBook();

	~Librarian()override;
};

class Catalog {// Agregation
private:
	Books* book;
	
	string name_catalog;
public:

	Catalog(string n, Books* b);
	string getBookName();
	~Catalog();
};



class Library {// Association
private:
	Librarian* librarian; Customer* customer; Catalog* catalog;
public:

	Library(Librarian* l, Customer* cus, Catalog* cat);
	void giveBook();
	~Library();
};//Association



template <class T> class MyClass
{
public:
	
	MyClass(T value, T value2 , T value3,T value4) {
		value_one = value;
		value_two = value2;
		value_three = value3;
		value_four = value4;
	}
	void changeData() {
		cout << " Entered numbers =" << value_one << "," 
			<< value_two << "," << value_three << "," << value_four  << ".  After manipulations we get = " <<
			value_one + value_four + value_three + value_two << endl;
		
	}
	
	MyClass(T obj) {
		object = obj;
	}
	void getSize() {
		cout << "Size of object is :" << sizeof(object)<< " bytes" << endl;
	}
private:
	T object;
	T value_one;
	T value_two;
	T value_three;
	T value_four;
};


class smallBook : protected Books {// task 
protected:
	int i = 5;

public:
	
	int getI();
	smallBook();
	~smallBook();
};

class BigBook : protected smallBook {// task 9


public:
	
	void setData(string name, string author, string publisher, int year, int circulation, string genre, int serialnum, int size);
	BigBook();
	BigBook(string name, string author, string publisher, int year, int circulation, string genre, int serialnum, int size);
	void showData();
	~BigBook();
};



class YoungCustomer :public Customer {///task 10-11
public:
	YoungCustomer(string name, string surname, string patron, string nation);
	YoungCustomer();
	string getName();
	void myTask();
	~YoungCustomer();
};
class OldCustomer :public Customer {
public:
	OldCustomer(int age, int phone, int year, int id);
	~OldCustomer();
};

class RegularCustomer :public YoungCustomer, public OldCustomer {
public:

	RegularCustomer(string name, string surname, string patronymic, string nation, int age, int phone, int year, int id);
	
	void display();
	void myTask();
	~RegularCustomer();
};//end  task 10-11





class chiefLibrarian : public virtual Human {//task 17
public:
	void speak(Librarian& l); void myTask()override;
};


///    /// 
///4.1 /// додавання (plus), віднімання (addition), множення (times),
///    ///  ділення(divides), взяття залишку (modulus) та зміна знаку (negate).
class Func_Plus
{

public:
	int operator () (int x, int y){
		return x + y;
	}
};
class Func_minus
{

public:
	int operator () (int x, int y) {
		return x - y;
	}
};
class Func_multiplication
{

public:
	int operator () (int x, int y) {
		return x * y;
	}
};
class Func_divides
{

public:
	int operator () (int x, int y)  {
		return x / y;
	}
};
class Func_module
{

public:
	int operator () (int x, int y)  {
		return x % y;
	}
};
class Func_negative
{

public:
	int operator () (int x)  {
		return -x;
	}
};
///    /// 
///    /// функціональні об'єкти для обчислення рівності (equal_to), нерівності (not_equal_to), 
///4.2 /// операції "більше" (greater), операції "менше" (less), операції "більше або дорівнює" 
///    /// (greater_equal), операції "менше або дорівнює" (less_equal) . 
///    /// 
class Func_equalTo
{

public:
	bool operator () (int x, int y){
		return x == y;
	}
};
class Func_notEqualTo
{

public:
	bool operator () (int x, int y){
		return x != y;
	}
};
class Func_bigger
{

public:
	bool operator () (int x, int y){
		return x > y;
	}
};
class Func_less
{

public:
	bool operator () (int x, int y){
		return x < y;
	}
};
class Func_biggerEqual
{

public:
	bool operator () (int x, int y){
		return x >= y;
	}
};
class Func_lessEqual
{

public:
	bool operator () (int x, int y){
		return x <= y;
	}
};
///    ///
/// 4.3/// функціональні об'єкти: логічне "і" (logical_and), логічне "або" (logical_or)
///    ///  і логічне "не" (logical_not)
///    ///
class Func_logicalAnd
{

public:
	bool operator () (bool x, bool y){
		return x && y;
	}
};
class Func_logicalOr
{

public:
	bool operator () (bool x, bool y){
		return x || y;
	}
};
class Func_LogicalNot
{

public:
	bool operator () (bool x){
		return !x;
	}
};