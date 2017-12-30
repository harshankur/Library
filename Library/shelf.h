#pragma once

#include"book.h"
class shelf
{
private:
	static const int MAX = 100;
	int counter;
	book* books[MAX];
	string name;
public:
	shelf(string str);
	~shelf();

	void setName(string str);
	void addBook(book b);

	string getName();
	void showShelf();
	bool isThere(int num);
	book* getBook(int num);
	int getCounter();
};

