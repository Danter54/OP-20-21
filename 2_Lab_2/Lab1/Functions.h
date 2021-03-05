#ifndef HEADER_INCLUDER
#define HEADER_INCLUDER

#include <iostream>
using namespace std;
#define N 10
struct library {
	char athr[10];
	char name[10];
	int year;
	char group;
};

int Input(library book[N]); 
int Rand_input(library book[N]);
void Output(library book[N], int count);
void Sort(library book[N],int count);


#ifndef DEBUG
#define DEBUG cout<<"\n=========================\n";\
			  cout<<"Date: "<<__DATE__<<" ; "\
			  <<"Time: "<<__TIME__<<endl;\
			  cout<<"File: "<<__FILE__<<" ; "\
			  <<"Function: "<<__FUNCTION__<<endl;\
			  cout << "=========================\n";
#endif


#ifndef PRINT_TYPE1
	#define PRINT_TYPE1 Input(book)
#endif  

#ifndef PRINT_TYPE2
#define PRINT_TYPE2 Rand_input(book)
#endif  

#endif