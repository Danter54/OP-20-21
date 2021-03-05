#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#define N (10)
using namespace std;

struct libr {
	char athr[10];
	char nm[10];
	int yr;
	char gr;
}book[N];

int input(int count) {
	cout << "Введите количество книг которые вы хотите записать:";
	cin >> count;
	for (int i = 0; i < count; i++) {
		cout << i + 1 << ". " << "Введите фамилию автора, название книги, её год и группу: ";
		cin >> book[i].athr>>book[i].nm>>book[i].yr>>book[i].gr;
	}
	return count;
}

int r_input(int count) {
	char surname[10][10] = {"Аранов","Сидоров","Сыч","Великий","Гусев","Волков","Смирнов","Новиков","Черных","Зайцев"};
	char name[10][10] = {"Наука","Системы","Вселенная","Биология","Алгебра","Сказки","Пьесы","Романсы","Драмы","Алегории"};
	char group[3] = {'Х','У','С'};
	cout << "Сколько книг вы хотите добавить? (Не больше 10): ";
	cin >> count;

	for (int i = 0; i < count;i++) {
		int x = rand() % 10;
		for (int j = 0; j < 10;j++) {
			book[i].athr[j] = surname[x][j];
		}
	}

	for (int i = 0; i < count; i++) {
		int x = rand() % 10;
		for (int j = 0; j < 10; j++) {
			book[i].nm[j] = name[x][j];
		}
	}

	for (int i = 0; i < count;i++) {
		book[i].yr =1000+ rand()%1000+20;
	}

	for (int i = 0; i < count;i++) {
		book[i].gr = group[rand()%3];
	}

	return count;
}

void sort(int count) {
	struct libr x;
	cout << "Происходит сортировка..."<<endl;
	for (int i = 0; i < count ; i++) {
		for (int j = 0; j < count; j++) {
			if (strcmp(book[i].athr,book[j].athr)<0) {
				x = book[i];
				book[i] = book[j];
				book[j] = x;
			}
		}
	}
}

void output(int count) {
	cout << "---------------------------------------------------"<<endl;
	cout << "|                 Каталог библиотеки              |"<<endl;
	cout << "|-------------------------------------------------|"<<endl;
	cout << "| Автор книги |  Название  | Год выпуска | Группа |"<<endl;
	cout << "|-------------------------------------------------|"<<endl;
	for (int i = 0; i < count; i++)
		printf("|  %9s  | %10s |    %5d    |    %c   |\n",
			book[i].athr, book[i].nm, book[i].yr, book[i].gr);
	cout << "|-------------------------------------------------|"<<endl;
	cout << "| Примечание: Х - художественная литература;      |"<<endl;
	cout << "| У - учебная литература; С - справочная литера - |"<<endl;
	cout << "| тура                                            |"<<endl;
	cout << "---------------------------------------------------" << endl;
}


int switcher(int num,int count) {
	switch (num) {
	case 1: count=input(count); break;
	case 2: count=r_input(count); break;
	case 3: cout<<"Нет чего ещё сортирвоать!\n"; break;
	case 4:cout<<"Структура ещё не заполненна!\n"; break;
	case 0:; break;
	default: cout << "Введенно неверное значение!\n";
	}
	return count;
}

int switcher2(int num, int count) {
	switch (num) {
	case 3:sort(count); break;
	case 4:output(count); break;
	case 0:; break;
	default: cout << "Введенно неверное значение!\n";
	}
	return count;
}


int main() {
	srand(time(0));
	system("chcp 1251");
	int num,count=0;
	do {
		
		cout << "Меню:\n";
		cout << "Ввод с клавиатуры -> 1\n";
		cout << "Рандомнный ввод -> 2\n";
		cout << "Сортировка структуры -> 3\n";
		cout << "Печать структуры -> 4\n";
		cout << "Выход из программы -> 0\n";
		cout << "Выберите действие: ";
		cin >> num;
		count =switcher(num,count);
	} while (num!=0 && count==0);

	do {
		cout << "Меню:\n";
		cout << "Сортировка структуры -> 3\n";
		cout << "Печать структуры -> 4\n";
		cout << "Выход из программы -> 0\n";
		cout << "Выберите действие: ";
		cin >> num;
		count = switcher2(num, count);
	} while (num != 0);

	cout << "Выход из программы!!!\n";

	return 0;
}