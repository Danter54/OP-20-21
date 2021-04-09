#include "Function.h"

void fill_str (char *str, int *size) {
	for (int i = 0; ; i++)
	{
		char temp = getchar();

		if (temp != '\n' && i < SIZE) {
			*(str + i) = temp;
			(*size)++;
		}
		else if ((temp == '\n' && i <= SIZE)) {
			*(str + i) = '\0';
			break;
		}
		else if (temp!='\n' && i==SIZE) {
			*(str + i) = '\0';
		}
		else if (temp=='\n' && i==SIZE) {
			*(str + i) = '\0';
		}
		else if (temp != '\n' && i>SIZE) {
			continue;
		}
		else break;

	}
}

