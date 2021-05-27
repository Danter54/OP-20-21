#include "Library.h"
#include <string>
#define _CRT_SECURE_NO_WARNINGS
void Library::set(char* auth, char* titl, int yr, char grp)
{
	Auther = new char[30];
	Title = new char[30];
	strcpy_s(Auther, 30, auth);
	strcpy_s(Title, 30, titl);
	this->year = yr;
	this->group = grp;
}

void Library::get(char* auth, char* titl, int yr, char grp) {
	

	strcpy_s(auth,30,Auther);
	strcpy_s(titl, 30, Title);

	yr = year;
	grp= group;
}

void Library::show() {
	printf("|  %9s  | %10s |    %5d    |    %c   |\n", Auther, Title, year, group);
}

Library::~Library() {
	delete[] Auther;
	delete[] Title;
}
