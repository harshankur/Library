#include "stdafx.h"
#include "shelf.h"


shelf::shelf(string str)
{
	name = str;
	counter = 0;
}

shelf::~shelf()
{
}

void shelf::setName(string str)
{
	name = str;
}

string shelf::getName()
{
	return name;
}

void shelf::addBook(book b)
{
	books[counter] = new book(b);
	counter++;		

	cout << "\nThe following book has been added to the '" << getName() << "' shelf.... " << endl << endl;
	books[counter - 1]->showBook(1);
}

void shelf::showShelf()
{
	cout << "\nThe books in shelf '" << getName() << "' are as follows\n\n";
	for (int i = 0; i < counter; i++)
	{
		cout << i << ". ";
		books[i]->showBook(0);
	}
}

bool shelf::isThere(int num)
{
	for (int i = 0; books[i]; i++)
	{
		if (books[i]->getNo() == num)
		{
			return true;
		}
	}
	return false;
}

book* shelf::getBook(int num)
{
	for (int i = 0; books[i]; i++)
	{
		if (books[i]->getNo() == num)
		{
			return books[i];
		}
	}
}

int shelf::getCounter()
{
	return counter;
}
