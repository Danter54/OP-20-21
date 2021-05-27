#include "Functions.h"
#include<iostream>

void Write(Library* books, int counter)
{
	char surname[30];
	char title[30];
	int year;
	char group;

	for (int i = 0; i < counter; i++) {
		printf("¬ведите автора, название, год, группу %d книги: ", i+1);
		scanf_s("%s %s %d %c", surname,30,title,30,&year, &group);
		books[i].set(surname,title,year,group);
	}
}

void Print(Library* books, int counter)
{
	for (int i = 0; i < counter; i++) {
		books[i].show();
	}
}

void Print_and_Get(Library* books, int counter) {
	char* surname=new char [30];
	char *name=new char[30];
	int yr = 0;
	char grp = ' ';

	for (int i = 0; i < counter; i++) {
		books[i].get(surname,name,yr,grp);
		books[i].show();
	}
}
