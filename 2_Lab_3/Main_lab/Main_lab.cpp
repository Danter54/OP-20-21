#include "Functions.h"

int main()
	{
	setlocale(LC_ALL,"ru");

	int mas[N],mas2[N], count;
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
	Main_Function(mas, mas2, count);

	return 0;
}