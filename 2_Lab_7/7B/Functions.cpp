#include "Functions.h"
#include <iostream>
#include <time.h>
void Init_arr(int* array, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		*(array + i) = rand()%200-100;
	}
}

void Write_in_file(int* array , int size) {

	FILE* file;
	fopen_s(&file, "File.txt", "w");
	if (file==NULL) {
		printf("Файл не открыт!!!!\n");
		exit(1);
	}

	for (int i = 0; i < size; i++) {
		fprintf(file,"%d ",array[i]);
	}

	fclose(file);

}

void Write_array_from_file(int* array, int size)
{
	FILE* file;
	fopen_s(&file, "File.txt", "r");

	if (file==NULL) {
		printf("Файл не открыт!!!\n");
		exit(1);
	}
	for (int i = 0; i < size; i++) {
		fscanf_s(file, "%d ", &array[i]);
	}

	fclose(file);
}

int Sum_div2(int* array, int size)
{
	int sum = 0;

	for (int i = 0; i < size; i++) {
		if (*(array+i)%2==0) {
			sum += *(array + i);
		}
	}

	return sum;
}
