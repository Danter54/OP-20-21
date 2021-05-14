#include "Functions.h"
#include "Header_includer.h"

int main()
{
	system("chcp 1251");
	int size = 0;
	printf("¬ведите размер массива: ");
	scanf_s("%d", &size);

	int* array1 = new int[size];
	int* array2 = new int[size];
	Init_array(array1, size);
	Write_arr2(array1, array2, size);

	for (int i = 0; i < size; i++) {
		std::cout << array2[i] << ' ';
	} 



}