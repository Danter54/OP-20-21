#include "Functions.h"

int main()
{
	system("chcp 1251");
	int Size;
	printf("������� ������ �������: ");
	std::cin >> Size;

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore();
		std::cout << "������� �������� ������!!!" << std::endl;
		return 1;
	}
	if (Size<=0) {
		std::cout << "������� �������� ������!!!" << std::endl;
		return 1;
	}

	int* array = new int[Size];

	fill_array(array,Size);
	std::cout << "��� ������: ";
	for (int i = 0; i < Size; i++) {
		std::cout << std::setw(4)<<*(array+i);
	}

	std::cout << std::endl;

	array_s(array,Size);

	std::cout << "��� ����� ������: ";
	for (int i = 0; i < Size; i++) {
		std::cout << std::setw(4) << *(array + i);
	}

	delete[] array;
	array = nullptr;
	return 0;
}