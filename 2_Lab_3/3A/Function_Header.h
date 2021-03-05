#pragma once

#include <iostream>
#include <time.h>

#define N 100

void init(int* a, int count);
void relative_address(int* a, int count);
void absolute_address(int*a, int count);
void without_indexing(int arr[N], int count);
void array_of_pointers(int arr[N], int count);
void pointer_to_pointer(int* arr, int count);
void pointer_parameter(int* arr, int count);