#include "Function_Header.h"


void init(int *a, int count) {
	for (int i = 0; i < count; i++) {	// initialization of array
		*(a+i) = rand()%200-100;
	}

}


void relative_address(int *a, int count) {
	
	int k = 0, sum=0;
	std::cout << "===== Относительный адрес =====\n";

	std::cout << "Массив: ";
	for (int i = 0; i < count; i++) {
		std::cout << *(a+i)<<' ';
	}
	std::cout << std::endl;

	for (int i = 0; i < count; i++) {
		if (*(a+i)<0) {
			sum += *(a+i);
			k++;
		}
	}
	
	std::cout << "Сумма: "<<sum<<std::endl;
	std::cout << "Количество: " << k << std::endl;
	std::cout << "===============================\n";
}

void absolute_address(int *a, int count) {

	int k = 0, sum = 0;

	std::cout << "===== Абсолютный адрес =====\n";

	std::cout << "Массив: ";
	for (int i = 0; i < count; i++, a++) {		// Output array
		std::cout << *a << ' ';
	}
	std::cout << std::endl;

	for (int i = 0; i < count; i++,a++) {
		if (*a < 0) {
			sum += *a;
			k++;
		}
	}

	std::cout << "Сумма: " << sum << std::endl;
	std::cout << "Количество: " << k << std::endl;
	std::cout << "===============================\n";

}

void without_indexing(int arr[N], int count) {

	int k = 0, sum = 0;
	int* a;
	std::cout << "===== Без использования индексации =====\n";

	std::cout << "Массив: ";
	for (a=arr; a < arr+count; a++) {		// Output array
		std::cout << *a << ' ';
	}
	std::cout << std::endl;

	for (a = arr; a < arr + count; a++) {
		if (*a<0) {
			sum += *a;
			k++;
		}
	}

	std::cout << "Сумма: " << sum << std::endl;
	std::cout << "Количество: " << k << std::endl;
	std::cout << "===============================\n";
}

void array_of_pointers(int arr[N], int count) {

	int* p[N];

	for (int i = 0; i < count; i++) {
		p[i] = &arr[i];					// Init array_of_pointers
	}

	int k = 0, sum = 0;
	std::cout << "===== Через массив указателей =====\n";

	std::cout << "Массив: ";
	for (int i = 0; i < count; i++) {
		std::cout << *p[i]<< ' ';
	}
	std::cout << std::endl;

	for (int i = 0; i < count; i++) {
		if (*p[i] < 0) {
			sum += *p[i];
			k++;
		}
	}

	std::cout << "Сумма: " << sum << std::endl;
	std::cout << "Количество: " << k << std::endl;
	std::cout << "===============================\n";
}

void pointer_to_pointer (int* arr, int count) {

	int * a;
	a = arr;

	int k = 0, sum = 0;
	std::cout << "===== Указатель на указатель =====\n";

	std::cout << "Массив: ";
	for (int i = 0; i < count; i++) {
		std::cout << *(a+i) << ' ';
	}
	std::cout << std::endl;

	for (int i = 0; i < count; i++) {
		if (*(a+i)<0) {
			sum += *(a+i);
			k++;
		}
	}

	std::cout << "Сумма: " << sum << std::endl;
	std::cout << "Количество: " << k << std::endl;
	std::cout << "===============================\n";
}


void pointer_parameter (int * arr, int count) {

	int sum = 0, k = 0;

	std::cout << "===== Функция с параметром указателем =====\n";
	std::cout << "Массив: ";

	for (int i = 0; i < count; i++) {
		std::cout << *(arr+i) << ' ';
	}
	std::cout << std::endl;

	for (int i = 0; i < count; i++)
	{
		if (*(arr+i)<0) {
			sum += *(arr+i);
			k++;
		}
	}

	std::cout << "Сумма: " << sum << std::endl;
	std::cout << "Количество: " << k << std::endl;
	std::cout << "===============================\n";
}