#include "stdafx.h"
#include "book.h"


book::book(int num, string str, subject sub)
{
	no = num;
	name = str;
	type = sub;
	borrowed = 0;
	donator = "Library";
	bookCount = 1;

	SubjectNames.push_back("English");
	SubjectNames.push_back("Hindi");
	SubjectNames.push_back("History");
	SubjectNames.push_back("Geography");
	SubjectNames.push_back("Math");
}

book::book(int num, string str, subject sub, int count)
{
	no = num;
	name = str;
	type = sub;
	borrowed = 0;
	donator = "Library";
	bookCount = count;

	SubjectNames.push_back("English");
	SubjectNames.push_back("Hindi");
	SubjectNames.push_back("History");
	SubjectNames.push_back("Geography");
	SubjectNames.push_back("Math");
}

book::book(int num, string str, subject sub, int count, string person)
{
	no = num;
	name = str;
	type = sub;
	borrowed = 0;
	donator = person;
	bookCount = count;


	SubjectNames.push_back("English");
	SubjectNames.push_back("Hindi");
	SubjectNames.push_back("History");
	SubjectNames.push_back("Geography");
	SubjectNames.push_back("Math");
}


book::~book()
{
}

void book::setNo(int num)
{
	no = num;
}

void book::setName(string str)
{
	name = str;
}

void book::setSubject(subject sub)
{
	type = sub;
}

void book::setDonator(string str)
{
	donator = str;
}

void book::setBorrower(string str)
{
	borrower = str;
	borrowed++;
}

void book::returned()
{
	borrowed--;
}

void book::setBookCount(int count)
{
	bookCount = count;
}

int book::getNo()
{
	return no;
}

string book::getName()
{
	return name;
}

string book::getSubject()
{
	return SubjectNames[subject(type)];
}

string book::getDonator()
{
	return donator;
}

string book::getBorrower()
{
	return borrower;
}

int book::getBookCount()
{
	return bookCount;
}

int book::getBorrowedCount()
{
	return borrowed;
}

void book::showBook(int op)
{
	cout << getNo() << "    " << getName() << "    " << getSubject() << endl;
	if (op != 0)
	{
		cout << "Donated by :" << getDonator();
		if (borrowed != 0)
		{
			cout << "    Currently borrowed by :" << getBorrower();
		}
		else
		{
			cout << "    Currently in stock.. ";
		}
		cout << endl;
	}
}

