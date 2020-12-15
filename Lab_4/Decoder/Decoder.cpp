#include <iostream>

int main(void)
{
	setlocale(LC_ALL, "Ru");
	unsigned short t;
	unsigned short d;
	unsigned short n;
	unsigned short int UnitStateWord;

	printf("Введите слово состояния устройства(0xFFFF): ");
	scanf_s("%hx", &UnitStateWord);
	t = (UnitStateWord >> 10) & 0x3B;
	d = (UnitStateWord >> 9) & 1;
	n = UnitStateWord & 0x1FF;
	printf("\nТип сдвига: %d\n",t);
	printf("Направление сдвига: %d\n",d);
	printf("Количество разрядов сдвига: %d",n);
}
