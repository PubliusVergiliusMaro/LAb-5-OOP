#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>


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


public:

	int random;
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
class smallBook : protected Books {// task 
protected:
	int i = 5;
public:
	int getI();
	smallBook();
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
