#include "Functions.h"

int Input(library book[N]) {
	DEBUG
		int count;
	cout << "Сколько книг вы хотите ввести: ";
	cin >> count;
		for (int i = 0; i < count;i++) {
			if (count > 10 || count < 0) break;
			cout << "Введите фамилию, название, год, группу "<<i+1<<" книги: ";
			cin >> book[i].athr >> book[i].name >> book[i].year >> book[i].group;
		}

	DEBUG
		return count;

}


int Rand_input (library book[N]) {
	DEBUG
		char surname[10][10] = { "Аранов","Сидоров","Сыч",
								"Великий","Гусев","Волков",
								"Смирнов","Новиков","Черных","Зайцев" };

		char name[10][10] = { "Наука","Системы","Вселенная",
						"Биология","Алгебра","Сказки",
						"Пьесы","Романсы","Драмы","Алегории" };
	
		char group[3] = { 'Х','У','С' };

		int count;

	cout << "Сколько книг вы хотите ввести: ";
	cin >> count;

	cout << "Происходит генерация рандомной библиотеки...\n";

	for (int i = 0; i < count; i++) {
		int x = rand() % 10;
		for (int j = 0; j < 10; j++) {
			book[i].athr[j] = surname[x][j];
		}
	}

	for (int i = 0; i < count; i++) {
		int x = rand() % 10;
		for (int j = 0; j < 10; j++) {
			book[i].name[j] = name[x][j];
		}
	}

	for (int i = 0; i < count; i++) {
		book[i].year = 1000 + rand() % 1000 + 20;
	}

	for (int i = 0; i < count; i++) {
		book[i].group = group[rand() % 3];
	}
	DEBUG
		return count;

}

void Output(library book[N], int count) {
	DEBUG
		cout << "---------------------------------------------------" << endl;
	cout << "|                 Каталог библиотеки              |" << endl;
	cout << "|-------------------------------------------------|" << endl;
	cout << "| Автор книги |  Название  | Год выпуска | Группа |" << endl;
	cout << "|-------------------------------------------------|" << endl;
	for (int i = 0; i < count; i++)
		printf("|  %9s  | %10s |    %5d    |    %c   |\n",
			book[i].athr, book[i].name, book[i].year, book[i].group);
	cout << "|-------------------------------------------------|" << endl;
	cout << "| Примечание: Х - художественная литература;      |" << endl;
	cout << "| У - учебная литература; С - справочная литера - |" << endl;
	cout << "| тура                                            |" << endl;
	cout << "---------------------------------------------------" << endl;
	DEBUG
}

void Sort(library book[N], int count) {
	DEBUG
		struct library x;
	int m;
	cout << "Сортировка...\n";
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			if (strcmp(book[i].athr, book[j].athr) < 0) {
				x = book[i];
				book[i] = book[j];
				book[j] = x;
			}
		}
	}
	DEBUG
}