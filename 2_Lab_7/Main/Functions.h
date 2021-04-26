#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

struct Library
{
	char surname[30];
	char title[30];
	int year;
	char group;
};

void add_book(int *count);
void rand_add_book(int* counter);
void beg_add(int* count);
void end_add(int* count);
int print_one(int* counter);
int printf_all(int* counter);