#include "Functions.h"

int main()
	{
	setlocale(LC_ALL,"ru");

	int mas[N], mas2[N], count, size_b=0;
	double average = 0;
	std::cout << "������� ���������� ��������� � ������� (�� ������ 100): ";
	std::cin >> count;

	if (count>100 || count<0) {
		std::cout << "�� ����� �������� ��������!!!";
		return 0;
	}
	else if (count == 0) {
		std::cout << "�� �� ������ ��������� ������!";
		return 0;
	}

	Rand_Num_Gen(mas,count);

	std::cout << "��� ������ �: ";
	for (int i = 0; i < count; i++) {
		std::cout << mas[i]<< ' ';
	}

	Main_Function(mas,mas2,count,&average,&size_b);

	std::cout << "\n������� ��������: " << average;
	std::cout << "\n����� ����� �: ";

	for (int i = 0; i < size_b; i++) {
		std::cout << mas2[i]<<' ';
	}

	return 0;
}