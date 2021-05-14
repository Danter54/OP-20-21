#include "Functions.h"
#include "Header_includer.h"

void Init_array(int* array, int size) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		*(array + i) = rand()%20-10;
	}
}

void Write_arr2(int* array1, int* array2, int size) {
	FILE* f1 = NULL;
	fopen_s(&f1, "file1.txt", "w");
	if (f1 == NULL) {
		printf("Не удалось открыть файл\n");
		return ;
	}

	for (int i = 0; i < size; i++) {
		fprintf(f1, "%d ", array1[i]);
	}
	fclose(f1);

	fopen_s(&f1, "file1.txt", "r");
	if (f1 == NULL) {
		printf("Не удалось открыть файл\n");
		return ;
	}

	for (int i = 0; i < size; i++) {
		fscanf_s(f1, "%d ", &array2[i]);
	}
}