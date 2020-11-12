#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	system("cls");
	system("chcp 1251");
	unsigned int k = 0 ;
	printf("Веедите количество грибов в корзине: ");
	scanf("%u", &k);
	if (k == 1 || (k % 10 == 1 && k!=11)) {
		printf("У тебя %u гриб в корзине.\n", k);
		system("pause");
		return main();
	}
	else if ((k>1 && k<5)) {
		printf("У тебя %u гриба в корзине.\n", k);
		system("pause");
		return main();
	}
	else if (k>20 && (k%10==2 || k%10==3 ||  k%10==4)) {
		printf("У тебя %u гриба в корзине.\n", k);
		system("pause");
		return main();
	}
	else if (k%10==0 || (k>=5 && k<20)||(k%10==5 || k%10==6 || k % 10 == 7 || k % 10 == 8 || k % 10 == 9)) {

		printf("У тебя %u грибов в корзине.\n", k);
		system("pause");
		return main();
	}
	else if (k==0) {
		printf("У тебя нет грибов в корзине.\n");
		system("pause");
		return main();
	}
}