#include "Function.h"

int main()
{
	setlocale(LC_ALL,"RU");
	system("chcp 1251");
	int size_str = 0;
	int space_count=SIZE;
	char* str = new char[SIZE+1];

	printf("������� ������ (�� ������ 80, � ��������� ������ ��� ���������):=>");
	fill_str(str,&size_str);
	if (size_str == 0) {
		printf("�� �� ����� ������!!!");
		return 0;
	}
	printf("������ ����� ������: %d\n", size_str);

	if (size_str ==0) {
		printf("�� �� ����� ������!!!");
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