#define _CRT_SECURE_NO_WARNINGS
#include "Functions.h"
#include <iostream>

#include<time.h>
#define SIZE 10

void Initfile() {

	srand(time(NULL));
	FILE* file;
	int temp=0;

	fopen_s(&file, "File.bin", "wb");

	if (file==NULL) {
		printf("\nÔאיכא םוע!!!\n");
		exit(1);
	}

	for (int i = 0; i < SIZE; i++) {
		temp = rand() % 100;
		printf("%d ",temp);
		fwrite(&temp, sizeof(int), 1, file);

	}

	fclose(file);
}

int chek_sum()
{
	int sum = 0;
	int temp = 0;
	FILE* file;
	fopen_s(&file, "File.bin", "rb");

	if (file == NULL) {
		printf("\nÔאיכא םוע!!!\n");
		exit(1);
	}

	fseek(file,sizeof(int),SEEK_SET);
	fread(&temp,sizeof(int),1,file);
	sum += temp;

	fseek(file, 4*sizeof(int), SEEK_SET);
	fread(&temp, sizeof(int), 1, file);
	sum += temp;

	fseek(file, 8 * sizeof(int), SEEK_SET);
	fread(&temp, sizeof(int), 1, file);
	sum += temp;
	fclose(file);

	return sum;
}



void Find_Min() {
	FILE* file;
	fopen_s(&file, "File.bin", "r+b");

	if (file == NULL) {
		printf("\nÔאיכא םוע!!!\n");
		exit(1);
	}

	int min, temp = 0, pos=0;

	fseek(file,0,SEEK_SET);
	fread(&min,sizeof(int),1,file);
	for (int i = 1; i < SIZE; i++) {
		fread(&temp, sizeof(int), 1, file);
		if (temp<min) {
			min = temp;
			pos = i;
		}
	}
	
	if (pos==0) {
		temp = 999;
		fseek(file, 0, SEEK_SET);
		fwrite(&temp, sizeof(int), 1, file);
	}
	else
		temp = 999;
	fseek(file, pos*sizeof(int), SEEK_SET);
	fwrite(&temp, sizeof(int), 1, file);


	fclose(file);
}
void Read_File()
{
	FILE* file;
	fopen_s(&file, "File.bin", "rb");

	if (file == NULL) {
		printf("\nÔאיכא םוע!!!\n");
		exit(1);
	}

	int temp=0;
	for (int i = 0; i < SIZE; i++) {
		fread(&temp, sizeof(int), 1, file);
		printf("%d ",temp);
	}
	fclose(file);
}