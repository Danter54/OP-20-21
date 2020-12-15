#include <iostream>

int main(void) {
	setlocale(LC_ALL, "Ru");
	unsigned short t;
	unsigned short d;
	unsigned short n;
	unsigned short int UnitStateWord;

	printf("Введите тип сдвига(0...3): ");
	scanf_s("%hu", &t);
	printf("Введите направление сдвига(0...1): ");
	scanf_s("%hu", &d);
	printf("Введите количество разрядов сдвига(0...511):");
	scanf_s("%hu", &n);

	UnitStateWord = (t & 0x37) << 10;
	UnitStateWord |= (d & 1) << 9;
	UnitStateWord |= n & 0x1FF;
	printf("\nСлово состояния устройства = %04x\n",
		UnitStateWord);
	return 0;
}