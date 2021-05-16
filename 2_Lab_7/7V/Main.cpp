#include <iostream>
#include "Functions.h"

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "RU");
	int sum = 0;
	printf("×טסכא ג פאיכו: ");
	Initfile();
	printf("\n");
	sum = chek_sum();
	printf("Sum = %d",sum);
	Find_Min();
	printf("\nNew file: ");
	Read_File();
	return 0;
}