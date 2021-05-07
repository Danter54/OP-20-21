#include "Functions.h"

using namespace std;
void add_book(int *counter) {
	FILE* libr_f = NULL;
	int count = 0;
	Library book;

	libr_f = fopen("Library.txt", "w");
	if (libr_f==NULL) {
		printf("Не удалось открыть файл");
	}
	*counter = 0;
	printf("Сколько вы хотите добавить книг: ");
	scanf_s("%d", &count);
	while (true) {
		if (count <= 0) {
			cout << "Введите коректоне число!!!\n";
			cout << "Новое число: ";
			scanf_s("%d", &count);

		}
		else {
			for (int i = 0; i < count; i++) {
				cout << "Введите автора, название, год, и группу " << i+1 << " книги: ";
				cin >> book.surname >> book.title >> book.year >> book.group;
				fprintf_s(libr_f, "%s %s %d %c\n", book.surname, book.title, book.year, book.group);
			}
			break;
		}
	};
	*counter += count;
	fclose(libr_f);
}

void rand_add_book(int* counter) {
	srand(time(NULL));


	char author [10][10]  { "Аранов","Сидоров","Сыч",
							"Великий","Гусев","Волков",
							"Смирнов","Новиков","Черных","Зайцев" };

	char name [10][10] { "Наука","Системы","Вселенная",
						"Биология","Алгебра","Сказки",
						"Пьесы","Романсы","Драмы","Алегории" };

	char group [3] = { 'Х','У','С' };
	
	FILE* libr_f = NULL;
	int count = 0;
	*counter = 0;
	Library book;

	libr_f = fopen("Library.txt", "w");
	if (libr_f == NULL) {
		printf("Не удалось открыть файл");
	}

	printf("Сколько вы хотите добавить книг: ");
	scanf_s("%d", &count);

	while (true) {
		if (count <= 0) {
			cout << "Введите коректоне число!!!\n";
			cout << "Новое число: ";
			scanf_s("%d", &count);
		}
		else {
			*counter = count;
			cout << "Генерация библиотеки...\n";

			for (int i = 0; i < count; i++ ) {
				int x = rand() % 10;
				for (int j = 0; j < 10; j++) {
					book.surname[j] = author[x][j];
					book.title[j] = name[x][j];
				}
					book.year = 1000 + rand() % 1000 + 20;
					book.group = group[rand() % 3];

					fprintf_s(libr_f, "%s %s %d %c\n", book.surname, book.title, book.year, book.group);
			}
			break;
		}
	};
	fclose(libr_f);
}

void beg_add(int* counter) {

	FILE* libr_f = NULL, *tmp = NULL;
	Library book;
	libr_f = fopen("Library.txt", "r");
	if (libr_f == NULL) {
		printf("Не удалось открыть файл");
		tmp = fopen("Library.txt", "w");
	}

	tmp = fopen("temp.txt", "w");


	cout << "Введите автора, название, год, и группу книги: ";
	cin >> book.surname >> book.title >> book.year >> book.group;
	fprintf_s(tmp, "%s %s %d %c\n", book.surname, book.title, book.year, book.group);

	if (*counter>0) {
		for (int i = 0; i < *counter; i++) {
			fscanf(libr_f, "%s %s %d %c\n", book.surname, book.title, &book.year, &book.group);
			fprintf_s(tmp, "%s %s %d %c\n", book.surname, book.title, book.year, book.group);
		}
	}


	fclose(libr_f);
	fclose(tmp);

	if (*counter != 0) {
		remove("Library.txt");
	}

	rename("temp.txt","Library.txt");

	

	


	(*counter)++;
	
}

void end_add(int* counter) {
	*counter = *counter + 1;

	FILE* libr_f = NULL;
	Library book;

	libr_f = fopen("Library.txt", "at");
	if (libr_f == NULL) {
		printf("Не удалось открыть файл");
	}

	cout << "Введите автора, название, год, и группу книги: ";
	cin >> book.surname >> book.title >> book.year >> book.group;
	fprintf_s(libr_f, "%s %s %d %c\n", book.surname, book.title, book.year, book.group);
	fclose(libr_f);
}

int print_one(int* counter) {
	FILE* libr_f = NULL;
	Library book;
	libr_f = fopen("Library.txt", "r");
	int count = 0;

	if (libr_f == NULL) {
		printf("Не удалось открыть файл");
		return 1;
	}

	if (*counter == 0) {
		printf("Нет записей в библиотеке!!!\n");
		return 0;
	}

	while (true) {
		cout << "Введите номер книги: ";
		cin >> count;
		if (count > 0 && count <= (*counter)) {
			break;
		}
		else cout << "Неверно введёный номер!!!\n";
	}

	

	cout << "---------------------------------------------------" << endl;
	cout << "|                 Каталог библиотеки              |" << endl;
	cout << "|-------------------------------------------------|" << endl;
	cout << "| Автор книги |  Название  | Год выпуска | Группа |" << endl;
	cout << "|-------------------------------------------------|" << endl;
	for (int i = 0; i < *counter; i++) {
		fscanf(libr_f, "%s %s %d %c\n", book.surname, book.title, &book.year, &book.group);
		if (count==i+1) {


			printf("|  %9s  | %10s |    %5d    |    %c   |\n",
				book.surname, book.title, book.year, book.group);
		}
	}
	cout << "|-------------------------------------------------|" << endl;
	cout << "| Примечание: Х - художественная литература;      |" << endl;
	cout << "| У - учебная литература; С - справочная литера - |" << endl;
	cout << "| тура                                            |" << endl;
	cout << "---------------------------------------------------" << endl;
	fclose(libr_f);

}

int printf_all(int* counter) {

	FILE* libr_f=NULL;
	Library book;
	libr_f = fopen("Library.txt", "r");
	if (libr_f == NULL) {
		printf("Не удалось открыть файл");
		return 1;
	}

	if (*counter==0) {
		printf("Нет записей в библиотеке!!!\n");
		return 0;
	}

	cout << "---------------------------------------------------" << endl;
	cout << "|                 Каталог библиотеки              |" << endl;
	cout << "|-------------------------------------------------|" << endl;
	cout << "| Автор книги |  Название  | Год выпуска | Группа |" << endl;
	cout << "|-------------------------------------------------|" << endl;

	for (int i = 0; i < *counter; i++) {
		fscanf(libr_f, "%s %s %d %c\n", book.surname, book.title, &book.year, &book.group);
		printf("|  %9s  | %10s |    %5d    |    %c   |\n",
			book.surname, book.title, book.year, book.group);
	}
	cout << "|-------------------------------------------------|" << endl;
	cout << "| Примечание: Х - художественная литература;      |" << endl;
	cout << "| У - учебная литература; С - справочная литера - |" << endl;
	cout << "| тура                                            |" << endl;
	cout << "---------------------------------------------------" << endl;
	fclose(libr_f);
}