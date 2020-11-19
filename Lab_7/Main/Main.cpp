#include <iostream>
#include <stdio.h>
#include <math.h>


int main()
{
	setlocale(LC_ALL, "ru");

	short n = 0;
	double x = 0, y = 0, h=0;
	printf("|     X      |      Y     |\n");
	printf("|------------|------------|\n");
	for (n; n < 5;n++) {
		
		x = 0;

		for (x; x < 4;x+=0.25) {

			if (x<1) {
				y = sqrt(1-(x-1)*(x-1));
			}

			else y = (4-x) / 3;

			printf("| %10.2lf | %10.7lf |", x+n*4, y);

			h = y*10+1;

			for (; h > 0; h-=0.8) printf(" ");
			printf("*\n");
		}
		printf("Нажмите клавишу Enter...");
		getchar();
	}

	return 0;
}