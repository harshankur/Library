// Library.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "shelf.h"


//Creating shelf objects for different subjects
const int shelvesCount(5);
shelf shelves[shelvesCount] = { "English", "Hindi", "History", "Geography", "Math" };

//Library Functions. Declared here. Described at the end
void showLibrary();
bool isThere(int num);
shelf* getShelf(int num);
book* searchBook();

int main()
{
	char strTemp[100];

	//Stacking up shelfs
	for (int i = 0; i < 5; i++)
	{
		sprintf_s(strTemp, 100, "English Grammer Vol.%d", i + 1);
		shelves[0].addBook(book(101 + i, strTemp, english));
		system("cls");

		sprintf_s(strTemp, 100, "Hindi Grammer Vol.%d", i + 1);
		shelves[1].addBook(book(201 + i, strTemp, hindi));
		system("cls");

		sprintf_s(strTemp, 100, "Ancient History Vol.%d", i + 1);
		shelves[2].addBook(book(301 + i, strTemp, history));
		system("cls");

		sprintf_s(strTemp, 100, "World Geography Vol.%d", i + 1);
		shelves[3].addBook(book(401 + i, strTemp, geography));
		system("cls");

		sprintf_s(strTemp, 100, "Fundamentals of Arithmetic Vol.%d", i + 1);
		shelves[4].addBook(book(501 + i, strTemp, math));
		system("cls");
	}

	system("cls");
	cout << "Welcome to Library!\n";

	int userOption = -1;
	//some arbitrary number assignment for the while block below

	//This loop should function till userOption is made zero by the user
	while (userOption != 0)
	{
		cout << "\nWhat do you intend to do?\n";
		cout << "1. Browse Collection\n2. Borrow books\n3. Return Books\n4. Donate books\n0. Exit\n";
		do 
		{
			cout << "\nKindly indicate with a valid option number: ";
			cin >> userOption;
		} while (!(userOption == 1 || userOption == 2 || userOption == 3 || userOption == 4 || userOption == 0));
		//This loop makes sure that the user selected userOption is a valid one

		book* tempBook;

		//For userOption == 1     ---->     Browse Collection
		if (userOption == 1)
		{
			showLibrary();

			int browseOption = -1;

			while (browseOption)
			{
				cout << "\nWhat would you like to do?\n1. Search Book\n0. Exit\n\nPlease indicate with the correct option number: ";
				cin >> browseOption;

				while (!(browseOption == 1 || browseOption == 0))
				{
					cout << "\n\nInvalid entry, Please try again. \n1. Search Book\n0. Exit\n\nPlease indicate with the correct option number: ";
					cin >> browseOption;
				}

				if (browseOption == 1)
				{
					tempBook = searchBook();
				}
			}

		}
		//For userOption == 1     ---->     Borrow Books
		else if (userOption == 2)
		{
			int browseOption = -1;

			while (browseOption)
			{
				cout << "\nWhat would you like to do?\n1. Search Book\n0. Exit\n\nPlease indicate with the correct option number: ";
				cin >> browseOption;

				while (!(browseOption == 1 || browseOption == 0))
				{
					cout << "\n\nInvalid entry, Please try again. \n1. Search Book\n0. Exit\n\nPlease indicate with the correct option number: ";
					cin >> browseOption;
				}

				if (browseOption == 1)
				{
					tempBook = searchBook();

					int borrowOption = -1;
					string borrower;

					if (tempBook->getBorrowedCount() < tempBook->getBookCount())
					{
						cout << "\nWhat would you like to do?\n1. Borrow\n0. Exit\n\nPlease indicate with the correct option number: ";
						cin >> borrowOption;

						while (!(borrowOption == 1 || borrowOption == 0))
						{
							cout << "\n\nInvalid entry, Please try again. \n1.Borrow\n0. Exit\n\nPlease indicate with the correct option number: ";
							cin >> borrowOption;
						}

						if (borrowOption == 1)
						{
							cout << "\nPlease enter your name: ";
							cin.ignore();				//added because getline function below was taking the newline character and ignoring user input
							getline(cin, borrower);
							tempBook->setBorrower(borrower);

							cout << "\nYou have borrowed the following book\n";
							tempBook->showBook(1);
						}
					}
					else
					{
						cout << "\nSorry, the book you are searching for is out of stock! " << endl;
					}
				}
			}
		}

		else if (userOption == 3)
		{
			int returnOption = -1;

			while (returnOption)
			{
				cout << "What do you want to do? \n1. Return a book? 0. Exit\n\nPlease indicate with the correct option number: ";
				cin >> returnOption;
				

				if (returnOption == 1)
				{
					tempBook = searchBook();
					tempBook->returned();
					cout << "\nYour book has been returned. Thank you!\n";
				}
					
			}
		}

		else if (userOption == 4)
		{
			int donateOption = -1;

			while (donateOption)
			{
				cout << "What do you want to do? \n1. Donate a book 0. Exit\n\nPlease indicate with the correct option number: ";
				cin >> donateOption;

				if (donateOption == 1)
				{
					string name;
					subject type;
					int subNum;
					int no;
					int bookCount;
					string donator;

					cout << "\nWhich subject does your book belong to?\n\nWe currently accept:- \n1. English \n2. Hindi \n3. History \n4. Geography \n5. Math.\n\nPlease indicate with the correct number for your subject: ";
					cin >> subNum;

					switch (subNum)
					{
					case 1:
						type = english;
						no = 101;
						break;
					case 2:
						type = hindi;
						no = 201;
						break;
					case 3:
						type = history;
						no = 301;
						break;
					case 4:
						type = geography;
						no = 401;
						break;
					case 5:
						type = math;
						no = 501;
						break;
					}

					cout << "\nPlease enter the book name: ";
					cin.ignore();				//added because getline function below was taking the newline character and ignoring user input
					getline(cin, name);

					cout << "\nPlease enter the number of books you are donating: ";
					cin >> bookCount;

					cout << "\nPlease enter your name: ";
					cin.ignore();
					getline(cin, donator);

					shelves[(no / 100) - 1].addBook(book(no + shelves[(no / 100) - 1].getCounter(), name, type, bookCount, donator));

				}
			}
		}
	}

	cout << "\nThank You for using Library... " << endl;

    return 0;
}

void showLibrary()
{
	for (int i = 0; i < shelvesCount; i++)
	{
		shelves[i].showShelf();
	}
}

bool isThere(int num)
{
	for (int i = 0; i < shelvesCount; i++)
	{
		if (shelves[i].isThere(num))
		{
			return true;
		}
	}
	return false;
}

shelf * getShelf(int num)
{
	for (int i = 0; i < shelvesCount; i++)
	{
		if (shelves[i].isThere(num))
		{
			return &shelves[i];
		}
	}
}

book * searchBook()
{
	int bookNo;
	book * tempTempBook;

	cout << "\nEnter the book number you wish to search for: ";
	cin >> bookNo;

	while (!isThere(bookNo))
	{
		cout << "No book exists by that number! Please try again\nEnter the book number you wish to search for: ";
		cin >> bookNo;
	}

	tempTempBook = getShelf(bookNo)->getBook(bookNo);

	cout << "\nHere are the details for the book you were looking for.. \n";
	tempTempBook->showBook(1);

	return tempTempBook;
}
