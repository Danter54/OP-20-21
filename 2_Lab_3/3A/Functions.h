#pragma once
#include <iostream>

#define SIZE (5)

void fill_array(int array[]);
void relative_address(int array[], int* count, int* sum);
void absolute_address(int array[], int* count, int* sum);
void without_index(int array[], int* count, int* sum);
void array_of_pointer(int array[], int* count, int* sum);
void pointer_to_pointer(int array[], int* count, int* sum);
void f_par(int* array, int* count, int* size);

