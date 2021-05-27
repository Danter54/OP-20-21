#pragma once
#define N (5)

class Library
{
private:
	char* Auther;
	char* Title;
	int year;
	char group;
public:
	
	~Library();
	void get(char* auth, char* titl, int yr, char grp);
	void set(char* auth, char* titl, int yr, char grp);
	void show();
};

