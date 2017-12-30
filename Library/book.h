#pragma once
#include<iostream>
#include<string>
#include"subject.h"

using namespace std;

class book
{
private:
	int no;
	int borrowed;
	int bookCount;
	string name;
	subject type;
	string donator;
	string borrower;

public:
	vector<string>SubjectNames;

	book(int num, string str, subject sub);
	book(int num, string str, subject sub, int count);
	book(int num, string str, subject sub, int count, string person);
	~book();

	void setNo(int num);
	void setBookCount(int count);
	void setName(string str);
	void setSubject(subject sub);
	void setDonator(string str);
	void setBorrower(string str);
	void returned();

	int getNo();
	int getBookCount();
	int getBorrowedCount();
	string getName();
	string getSubject();
	string getDonator();
	string getBorrower();

	void showBook(int op);
};

