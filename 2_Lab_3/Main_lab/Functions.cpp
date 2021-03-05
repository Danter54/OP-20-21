#include "Functions.h"

void Rand_Num_Gen(int *a, int count) {

	srand(time(NULL));

	for (int i = 0; i < count; i++) {
		*(a+i) = rand()%2-2;
	}
}


void Main_Function(int *a, int* b, int count) {
	std::cout << "========== Main function ==========\n";
	std::cout << "Our array: ";
	for (int i = 0; i < count; i++) {
		std::cout << *(a+i) << ' ';
	}
	std::cout << std::endl;


	double average = 0;
	int j = 0;
	for (int i = 0; i < count; i++) average += *(a+i);
	average = average / count;
	std::cout << "Our average: " << average <<" ;"<< std::endl;

	for (int i = 0; i < count; i++) {
		if (*(a+i) < average) {
			*(b+j) = *(a+i);
			j++;
		}
	}
	
	std::cout << "Our new array: ";
	for (int i = 0; i < j; i++) {
		std::cout << *(b+i) << ' ';
	}
	std::cout<<std::endl;
}