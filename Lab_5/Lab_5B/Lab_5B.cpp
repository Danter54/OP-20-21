#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	system("cls");
	system("chcp 1251");
	unsigned int k = 0 ;
	printf("Веедите количество грибов в корзине: ");
	scanf("%u", &k);
	if (k%10==0 || k%10>4 || k%100==11 ||(k>10 &&k<20)) {
		printf("У тебя %u грибов в корзине\n", k);
		system("pause");
		return main();
	}
	if (k%10==1) {
		printf("У тебя %u гриб в корзине\n", k);
		system("pause");
		return main();
	}
	if (k%10>1 && k%10<5) {
		printf("У тебя %u гриба в корзине\n", k);
		system("pause");
		return main();
	}
}