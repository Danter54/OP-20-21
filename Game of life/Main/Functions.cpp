#include "Functions.h"

void InitMap(int** map)
{
	srand(time(NULL));
	for (int i = 0; i < SIZE_X; i++) {
		for (int j = 0; j < SIZE_Y; j++) {
			*(*(map + i) + j) = rand() % 2;
		}
	}

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < SIZE_Y; j++) {	//заполнение нулями верхнего контура
			*(*(map + i) + j) = 0;
		}
	}

	for (int i = 0; i < SIZE_Y; i++) {

		map[SIZE_X - 1][i] = 0;				//заполнение нулями нижнего контура
	}

	for (int i = 0; i < SIZE_X - 1; i++) {
		map[i][0] = 0;						//заполнение нулями левого контура
	}

	for (int i = 0; i < SIZE_X - 1; i++) {
		map[i][SIZE_Y - 1] = 0;
	}
}

void CheckRules(int** MAP, int** New_Map)
{
	for (int i = 1; i < SIZE_X - 1; i++) {
		for (int j = 1; j < SIZE_Y - 1; j++) {
			int counter = 0;
			if (MAP[i - 1][j - 1] == 1) {
				counter++;
			}
			if (MAP[i - 1][j] == 1) {
				counter++;
			}
			if (MAP[i - 1][j + 1] == 1) {
				counter++;
			}
			if (MAP[i][j - 1] == 1) {
				counter++;
			}
			if (MAP[i][j + 1] == 1) {
				counter++;

			}
			if (MAP[i + 1][j - 1] == 1) {
				counter++;

			}
			if (MAP[i + 1][j] == 1) {
				counter++;
			}
			if (MAP[i + 1][j + 1] == 1) {
				counter++;
			}


			if ((MAP[i][j] == 1) && (counter < 2 || counter>3)) {
				New_Map[i][j] = 0;
			}
			else if ((MAP[i][j] == 1) && (counter == 2 || counter == 3)) {
				New_Map[i][j] = 1;

			}
			else if ((MAP[i][j] == 0) && counter == 3) {
				New_Map[i][j] = 1;
			}
			else New_Map[i][j] = MAP[i][j];

		}
	}


	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < SIZE_Y; j++) {	//заполнение нулями верхнего контура
			*(*(New_Map + i) + j) = 0;
		}
	}

	for (int i = 0; i < SIZE_Y; i++) {

		New_Map[SIZE_X - 1][i] = 0;				//заполнение нулями нижнего контура
	}

	for (int i = 0; i < SIZE_X - 1; i++) {
		New_Map[i][0] = 0;						//заполнение нулями левого контура
	}

	for (int i = 0; i < SIZE_X - 1; i++) {
		New_Map[i][SIZE_Y - 1] = 0;
	}


	for (int i = 0; i < SIZE_X; i++) {
		for (int j = 0; j < SIZE_Y; j++) {
			*(*(MAP + i) + j) = New_Map[i][j];
		}
	}
}
