#include "Functions.h"

int main()
{
	system("chcp 1251");
	int array[SIZE];
	int choice, count = 0, sum = 0;

	fill_array(array);

	std::cout << "��� ������: ";
	for (int i = 0; i < SIZE; i++) {
		std::cout << array[i] << ' ';
	}
	std::cout << std::endl;
	std::cout << "�������� ����� ���������: \n";
	std::cout << "0-����� �� ���������;\n";

	std::cout << "1-������������� �����;\n";
	std::cout << "2-����� ���������� �����;\n";
	std::cout << "3-�� ������������ ����������;\n";
	std::cout << "4-����� ������ ����������;\n";
	std::cout << "5-����� ��������� �� ���������;\n";
	std::cout << "6-����� �������� ��������� �������;\n";

	std::cout << "��� �����: ";
	std::cin >> choice;

		switch (choice) {

			case 0: { std::cout << "����� �� ���������!!!";
			return 0;
			}

			case 1: { relative_address(array, &count, &sum);
				printf("����������: %d\n", count);
				std::cout << "�����:" << sum;
				return 0;};

			case 2: { absolute_address(array, &count, &sum);
			printf("����������: %d\n", count);
			std::cout << "�����:" << sum;
			return 0;};

			case 3: {without_index(array, &count, &sum);
			printf("����������: %d\n", count);
			std::cout << "�����:" << sum;
			return 0;};

			case 4: {array_of_pointer(array, &count, &sum);
			printf("����������: %d\n", count);
			std::cout << "�����:" << sum;
			return 0;};

			case 5: {pointer_to_pointer(array, & count, & sum);
				printf("����������: %d\n", count);
				std::cout << "�����:" << sum;
				return 0; };

			case 6:f_par(array,&count, &sum);
				printf("����������: %d\n", count);
				std::cout << "�����:" << sum;
				break;
			default: {
				printf("������� ������� ��������!!!");
				return 1; }
		}

}
