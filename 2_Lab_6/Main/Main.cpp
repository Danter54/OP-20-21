#include "Function.h"

int main()
{
	setlocale(LC_ALL,"RU");
	system("chcp 1251");
	int size_str = 0;
	int space_count=SIZE;
	char* str = new char[SIZE+1];

	printf("Введите строку (не больше 80, в противном случае она обрежется):=>");
	fill_str(str,&size_str);
	if (size_str == 0) {
		printf("Вы не ввели сторку!!!");
		return 0;
	}
	printf("Размер вашей строки: %d\n", size_str);

	if (size_str ==0) {
		printf("Вы не ввели сторку!!!");
		return 0;
	}

	space_count = space_count - size_str;
	printf("|");
	for (int i = 0,j=0; i < SIZE;i++) {
		if (i<space_count) {
			printf(" ");
		}
	}
	printf("%s", str);
	printf("|");




	delete[] str;
	return 0;
}