#include "Function_Header.h"

int main()
{
	setlocale(LC_ALL,"RU");

	int count = 0;
	
	int arr[N], copy[N];
	int* a, * b;


	std::cout << "Введите количество елементов в массиве (Не больше 50): ";
	std::cin >> count;

	if (count < 0 || count > 50 || count == 0) {
		std::cout << "Введено неверное значение";
		return 0;
	}

	init(arr,count);	// initialization of array

	relative_address(arr, count);
	absolute_address(arr, count);
	without_indexing(arr, count);
	array_of_pointers(arr,count);
	pointer_to_pointer(arr, count);
	pointer_parameter(arr,count);


	return 0;
}
