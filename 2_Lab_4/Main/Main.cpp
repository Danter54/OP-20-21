#include"Function.h"


int main()
{
	setlocale(LC_ALL, "RU");

	int size;
	std::cout << "¬ведите размер массива: ";
	std::cin >> size;

	int* arr = new int[size];

	Filling_array(arr, size);
	Main_function(arr, size);

	std::cout << std::endl;
	delete[] arr;
	
	return 0;
}