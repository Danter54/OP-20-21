#include "Node.h"
#include "Header_includer.h"

void Creat_List(Node** head, Node** tail, int* size) {

	if (*head!=NULL) {
		std::cout << "Список создан!!!\n";
		return;
	}
	int choice = 0;
	do {

		Node* tmp = (Node*)malloc(sizeof(Node));
		printf("Введите автора, название, год и группу книги: ");
		(*size)++;
		if (*head == NULL) {
			tmp->prev = NULL;
			*head = *tail = tmp;
		}
		else {
			(*tail)->next = tmp;
			tmp->prev = *tail;
			*tail = tmp;
		}
		std::cin >> tmp->book.surname >> tmp->book.title >> tmp->book.year >> tmp->book.group;
		tmp->next = NULL;
		printf("Хотите продолжить?\n");
		printf("1 - Да\n");
		printf("2 - Нет\n");
		printf("Ваш выбор: ");
		scanf_s("%d", &choice);

	} while (choice != 2);
	

}

void Print_List_Begin(Node* head) {
	Node* tmp = head;

	if (tmp == NULL) {
		printf("Список не создан!!!\n");
		return;
	}
	while (tmp != NULL) {
		std::cout << "---------------------------------------------------" << std::endl;
		std::cout << "|                 Каталог библиотеки              |" << std::endl;
		std::cout << "|-------------------------------------------------|" << std::endl;
		std::cout << "| Автор книги |  Название  | Год выпуска | Группа |" << std::endl;
		std::cout << "|-------------------------------------------------|" << std::endl;
		while (tmp != NULL) {
			printf("|  %9s  | %10s |    %5d    |    %c   |\n", tmp->book.surname, tmp->book.title, tmp->book.year, tmp->book.group);
			tmp = tmp->next;
		}
		std::cout << "|-------------------------------------------------|" << std::endl;
		std::cout << "| Примечание: Х - художественная литература;      |" << std::endl;
		std::cout << "| У - учебная литература; С - справочная литера - |" << std::endl;
		std::cout << "| тура                                            |" << std::endl;
		std::cout << "---------------------------------------------------" << std::endl;
	}

}

void Print_List_End(Node* tail) {

	Node* tmp = tail;

	if (tmp ==NULL) {
		printf("Список не создан!!!\n");
		return;
	}

	while (tmp != NULL) {
		std::cout << "---------------------------------------------------" << std::endl;
		std::cout << "|                 Каталог библиотеки              |" << std::endl;
		std::cout << "|-------------------------------------------------|" << std::endl;
		std::cout << "| Автор книги |  Название  | Год выпуска | Группа |" << std::endl;
		std::cout << "|-------------------------------------------------|" << std::endl;
		while (tmp != NULL) {
			printf("|  %9s  | %10s |    %5d    |    %c   |\n", tmp->book.surname, tmp->book.title, tmp->book.year, tmp->book.group);
			tmp = tmp->prev;
		}
		std::cout << "|-------------------------------------------------|" << std::endl;
		std::cout << "| Примечание: Х - художественная литература;      |" << std::endl;
		std::cout << "| У - учебная литература; С - справочная литера - |" << std::endl;
		std::cout << "| тура                                            |" << std::endl;
		std::cout << "---------------------------------------------------" << std::endl;
	}

}

void Add_Elem(Node** head, Node** tail,int *size, int elem) {

	Node* tmp = (Node*)malloc(sizeof(Node));
	

	if ((elem-1)==0) {
		tmp->next = *head;
		(*head)->prev = tmp;
		tmp->prev = NULL;
		*head = tmp;
	}
	else {
		Node* tmp_pos = (*head);
		for (int i = 1; i < elem - 1; i++) {
			tmp_pos = tmp_pos->next;
		}
		if (tmp_pos->next==NULL) {
			(*tail)->next = tmp;
			(*tail)->prev = (*tail);
			(*tail) = tmp;
		}
		else {
			tmp->next = tmp_pos->next;
			tmp_pos->next = tmp;
			tmp->next->prev = tmp;
			tmp->prev = tmp_pos;
		}
	}
	(*size)++;
	printf("Введите автора, название, год и группу книги: ");
	std::cin >> tmp->book.surname >> tmp->book.title >> tmp->book.year >> tmp->book.group;

}

void Remove_Elem(Node** head, Node** tail, int* size, int elem) {

	Node* temp_pos = (*head);
	if (elem-1==0) {
		(*head) = (*head)->next;
		(*head)->prev = NULL;
		free(temp_pos);
	}
	else {
		for (int i = 1; i < elem - 1;i++) {
			temp_pos = temp_pos->next;
		}
		Node* tmp = temp_pos->next;
		if (tmp->next==NULL) {
			Node* ptr = tmp;
			tmp = NULL;
			temp_pos->next = NULL;
			(*tail) = temp_pos;
			free( ptr);
		}
		else {
			temp_pos->next = tmp->next;
			tmp->next->prev = temp_pos;
			delete tmp;
		}


	}
	(*size)--;

}

void Found_with_Beg(Node* head) {

	if (head==NULL) {
		printf("Создайте список!!!\n");
		return;
	}

	int choice = 0;
	printf("Выберите критерий поиска:\n");
	printf("1-Фамилия автора:\n");
	printf("2-Название книги\n");
	printf("3-Год\n");
	printf("4-Группа\n");
	printf("Ваш выбор: ");
	scanf_s("%d", &choice);


	switch (choice) {
	case 1: {

		char cur_surname[30];
		int count = 0;
		printf("Введите фамилию: ");
		scanf_s("%s", cur_surname, 30);

		Node* tmp = head;

		while (!tmp == NULL) {
			if (strcmp(cur_surname, tmp->book.surname) == 0) {
				count++;
			}
			tmp = tmp->next;
		}

		if (count == 0) {
			printf("Ничего не найдено!!!\n");
		}
		else {
			tmp = head;
			std::cout << "---------------------------------------------------" << std::endl;
			std::cout << "|                 Каталог библиотеки              |" << std::endl;
			std::cout << "|-------------------------------------------------|" << std::endl;
			std::cout << "| Автор книги |  Название  | Год выпуска | Группа |" << std::endl;
			std::cout << "|-------------------------------------------------|" << std::endl;
			while (!tmp == NULL) {
				if (strcmp(cur_surname, tmp->book.surname) == 0) {
					printf("|  %9s  | %10s |    %5d    |    %c   |\n", tmp->book.surname, tmp->book.title, tmp->book.year, tmp->book.group);
				}
				tmp = tmp->next;
			}
			std::cout << "|-------------------------------------------------|" << std::endl;
			std::cout << "| Примечание: Х - художественная литература;      |" << std::endl;
			std::cout << "| У - учебная литература; С - справочная литера - |" << std::endl;
			std::cout << "| тура                                            |" << std::endl;
			std::cout << "---------------------------------------------------" << std::endl;
		}
	}

		  break;
	case 2:{
		char cur_title[30];
		int count = 0;
		printf("Введите название: ");
		scanf_s("%s", cur_title, 30);

		Node* tmp = head;

		while (!tmp == NULL) {
			if (strcmp(cur_title, tmp->book.title) == 0) {
				count++;
			}
			tmp = tmp->next;
		}

		if (count == 0) {
			printf("Ничего не найдено!!!\n");
		}
		else {
			tmp = head;
			std::cout << "---------------------------------------------------" << std::endl;
			std::cout << "|                 Каталог библиотеки              |" << std::endl;
			std::cout << "|-------------------------------------------------|" << std::endl;
			std::cout << "| Автор книги |  Название  | Год выпуска | Группа |" << std::endl;
			std::cout << "|-------------------------------------------------|" << std::endl;
			while (!tmp == NULL) {
				if (strcmp(cur_title, tmp->book.title) == 0) {
					printf("|  %9s  | %10s |    %5d    |    %c   |\n", tmp->book.surname, tmp->book.title, tmp->book.year, tmp->book.group);
				}
				tmp = tmp->next;
			}
			std::cout << "|-------------------------------------------------|" << std::endl;
			std::cout << "| Примечание: Х - художественная литература;      |" << std::endl;
			std::cout << "| У - учебная литература; С - справочная литера - |" << std::endl;
			std::cout << "| тура                                            |" << std::endl;
			std::cout << "---------------------------------------------------" << std::endl;
		}
	}
		break;
	case 3:
	{
		int cur_year = 0;
		int count = 0;
		printf("Введите год: ");
		scanf_s("%d", &cur_year);

		Node* tmp = head;
		while (tmp!=NULL) {
			if (cur_year==tmp->book.year) {
				count++;
			}
			tmp = tmp->next;
		}

		if (count == 0) {
			printf("Нет такой книги!!!\n");
		}
		else {
			tmp = head;
			std::cout << "---------------------------------------------------" << std::endl;
			std::cout << "|                 Каталог библиотеки              |" << std::endl;
			std::cout << "|-------------------------------------------------|" << std::endl;
			std::cout << "| Автор книги |  Название  | Год выпуска | Группа |" << std::endl;
			std::cout << "|-------------------------------------------------|" << std::endl;
			while (!tmp == NULL) {
				if (cur_year==tmp->book.year) {
					printf("|  %9s  | %10s |    %5d    |    %c   |\n", tmp->book.surname, tmp->book.title, tmp->book.year, tmp->book.group);
				}
				tmp = tmp->next;
			}
			std::cout << "|-------------------------------------------------|" << std::endl;
			std::cout << "| Примечание: Х - художественная литература;      |" << std::endl;
			std::cout << "| У - учебная литература; С - справочная литера - |" << std::endl;
			std::cout << "| тура                                            |" << std::endl;
			std::cout << "---------------------------------------------------" << std::endl;
		}

	}
		break;
	case 4:
	{
		char cur_group;
		int count = 0;
		printf("Введите группу: ");
		std::cin >> cur_group;
		Node* tmp = head;
		while (tmp != NULL) {
			if (cur_group == tmp->book.group) {
				count++;
			}
			tmp = tmp->next;
		}

		if (count == 0) {
			printf("Нет такой книги!!!\n");
		}
		else {
			tmp = head;
			std::cout << "---------------------------------------------------" << std::endl;
			std::cout << "|                 Каталог библиотеки              |" << std::endl;
			std::cout << "|-------------------------------------------------|" << std::endl;
			std::cout << "| Автор книги |  Название  | Год выпуска | Группа |" << std::endl;
			std::cout << "|-------------------------------------------------|" << std::endl;
			while (!tmp == NULL) {
				if (cur_group == tmp->book.group) {
					printf("|  %9s  | %10s |    %5d    |    %c   |\n", tmp->book.surname, tmp->book.title, tmp->book.year, tmp->book.group);
				}
				tmp = tmp->next;
			}
			std::cout << "|-------------------------------------------------|" << std::endl;
			std::cout << "| Примечание: Х - художественная литература;      |" << std::endl;
			std::cout << "| У - учебная литература; С - справочная литера - |" << std::endl;
			std::cout << "| тура                                            |" << std::endl;
			std::cout << "---------------------------------------------------" << std::endl;
		}

	}
		break;

	}

}

void Found_with_End(Node* tail) {
	if (tail == NULL) {
		printf("Создайте список!!!\n");
		return;
	}

	int choice = 0;
	printf("Выберите критерий поиска:\n");
	printf("1-Фамилия автора:\n");
	printf("2-Название книги\n");
	printf("3-Год\n");
	printf("4-Группа\n");
	printf("Ваш выбор: ");
	scanf_s("%d", &choice);


	switch (choice) {
	case 1: {
		char cur_surname[30];
		int count = 0;
		printf("Введите фамилию: ");
		scanf_s("%s", cur_surname, 30);

		Node* tmp = tail;

		while (!tmp == NULL) {
			if (strcmp(cur_surname, tmp->book.surname) == 0) {
				count++;
			}
			tmp = tmp->prev;
		}

		if (count == 0) {
			printf("Ничего не найдено!!!\n");
		}
		else {
			tmp = tail;
			std::cout << "---------------------------------------------------" << std::endl;
			std::cout << "|                 Каталог библиотеки              |" << std::endl;
			std::cout << "|-------------------------------------------------|" << std::endl;
			std::cout << "| Автор книги |  Название  | Год выпуска | Группа |" << std::endl;
			std::cout << "|-------------------------------------------------|" << std::endl;
			while (!tmp == NULL) {
				if (strcmp(cur_surname, tmp->book.surname) == 0) {
					printf("|  %9s  | %10s |    %5d    |    %c   |\n", tmp->book.surname, tmp->book.title, tmp->book.year, tmp->book.group);
				}
				tmp = tmp->prev;
			}
			std::cout << "|-------------------------------------------------|" << std::endl;
			std::cout << "| Примечание: Х - художественная литература;      |" << std::endl;
			std::cout << "| У - учебная литература; С - справочная литера - |" << std::endl;
			std::cout << "| тура                                            |" << std::endl;
			std::cout << "---------------------------------------------------" << std::endl;
		}
	}
		break;
	case 2: {
		char cur_title[30];
		int count = 0;
		printf("Введите название: ");
		scanf_s("%s", cur_title, 30);

		Node* tmp = tail;

		while (!tmp == NULL) {
			if (strcmp(cur_title, tmp->book.title) == 0) {
				count++;
			}
			tmp = tmp->prev;
		}

		if (count == 0) {
			printf("Ничего не найдено!!!\n");
		}
		else {
			tmp = tail;
			std::cout << "---------------------------------------------------" << std::endl;
			std::cout << "|                 Каталог библиотеки              |" << std::endl;
			std::cout << "|-------------------------------------------------|" << std::endl;
			std::cout << "| Автор книги |  Название  | Год выпуска | Группа |" << std::endl;
			std::cout << "|-------------------------------------------------|" << std::endl;
			while (!tmp == NULL) {
				if (strcmp(cur_title, tmp->book.title) == 0) {
					printf("|  %9s  | %10s |    %5d    |    %c   |\n", tmp->book.surname, tmp->book.title, tmp->book.year, tmp->book.group);
				}
				tmp = tmp->prev;
			}
			std::cout << "|-------------------------------------------------|" << std::endl;
			std::cout << "| Примечание: Х - художественная литература;      |" << std::endl;
			std::cout << "| У - учебная литература; С - справочная литера - |" << std::endl;
			std::cout << "| тура                                            |" << std::endl;
			std::cout << "---------------------------------------------------" << std::endl;
		}
	}
		  break;
	case 3: {
		int cur_year = 0;
		int count = 0;
		printf("Введите год: ");
		scanf_s("%d", &cur_year);

		Node* tmp = tail;
		while (tmp != NULL) {
			if (cur_year == tmp->book.year) {
				count++;
			}
			tmp = tmp->prev;
		}

		if (count == 0) {
			printf("Нет такой книги!!!\n");
		}
		else {
			tmp = tail;
			std::cout << "---------------------------------------------------" << std::endl;
			std::cout << "|                 Каталог библиотеки              |" << std::endl;
			std::cout << "|-------------------------------------------------|" << std::endl;
			std::cout << "| Автор книги |  Название  | Год выпуска | Группа |" << std::endl;
			std::cout << "|-------------------------------------------------|" << std::endl;
			while (!tmp == NULL) {
				if (cur_year == tmp->book.year) {
					printf("|  %9s  | %10s |    %5d    |    %c   |\n", tmp->book.surname, tmp->book.title, tmp->book.year, tmp->book.group);
				}
				tmp = tmp->prev;
			}
			std::cout << "|-------------------------------------------------|" << std::endl;
			std::cout << "| Примечание: Х - художественная литература;      |" << std::endl;
			std::cout << "| У - учебная литература; С - справочная литера - |" << std::endl;
			std::cout << "| тура                                            |" << std::endl;
			std::cout << "---------------------------------------------------" << std::endl;
		}
	}
		  break;
	case 4: {
		char cur_group;
		int count = 0;
		printf("Введите группу: ");
		std::cin >> cur_group;
		Node* tmp = tail;
		while (tmp != NULL) {
			if (cur_group == tmp->book.group) {
				count++;
			}
			tmp = tmp->prev;
		}

		if (count == 0) {
			printf("Нет такой книги!!!\n");
		}
		else {
			tmp = tail;
			std::cout << "---------------------------------------------------" << std::endl;
			std::cout << "|                 Каталог библиотеки              |" << std::endl;
			std::cout << "|-------------------------------------------------|" << std::endl;
			std::cout << "| Автор книги |  Название  | Год выпуска | Группа |" << std::endl;
			std::cout << "|-------------------------------------------------|" << std::endl;
			while (!tmp == NULL) {
				if (cur_group == tmp->book.group) {
					printf("|  %9s  | %10s |    %5d    |    %c   |\n", tmp->book.surname, tmp->book.title, tmp->book.year, tmp->book.group);
				}
				tmp = tmp->prev;
			}
			std::cout << "|-------------------------------------------------|" << std::endl;
			std::cout << "| Примечание: Х - художественная литература;      |" << std::endl;
			std::cout << "| У - учебная литература; С - справочная литера - |" << std::endl;
			std::cout << "| тура                                            |" << std::endl;
			std::cout << "---------------------------------------------------" << std::endl;
		}
	}
		  break;
	}
}

void Merg(Node* head, int* size) {
	if (head == NULL) {
		std::cout << "Создайте список!!!\n";
		return;
	}
	Node* temp, * ptr, * p, * trash;
	temp = (Node*)malloc(sizeof(Node));

	for (int i = 0; i < (*size) - 1; i++) {
		ptr = head;

		while (ptr->next != NULL) {

			p = ptr->next;
			if (strcmp(ptr->book.surname, p->book.surname) > 0) {

				trash = p->next;
				*temp = *ptr;
				*ptr = *p;
				free(p);
				ptr->next = (Node*)malloc(sizeof(Node));
				*ptr->next = *temp;
				ptr->next->next = trash;
			}

			ptr = ptr->next;
		}
	}
	free(temp);
}

void Add_to_File(Node *head) {
	if (head == NULL) {
		std::cout << "Создайте список!!!\n";
		return;
	}
	FILE* Libr_f = NULL;
	fopen_s(&Libr_f, "Library.txt", "w");

	if (Libr_f == NULL) {
		printf("Не удалось открыть файл");
		return;
	}

	while (head != NULL) {
		fprintf_s(Libr_f, "%s %s %d %c\n", head->book.surname, head->book.title, head->book.year, head->book.group);
		head = head->next;
	}

	fclose(Libr_f);
}

void CreatList_File(int* size, Node **tail, Node **head) {
	FILE* Lib_f;

	fopen_s(&Lib_f, "Library.txt", "rt");

	if (Lib_f == NULL) {
		printf("Файл не удалось открыть!!!\n");
		return ;
	}

	Node* tmp = NULL;
	tmp = (Node*)malloc(sizeof(Node));

	while (!feof(Lib_f))
	{
		(*size)++;
		fscanf_s(Lib_f, "%s", tmp->book.surname, 30);
		fscanf_s(Lib_f, "%s", tmp->book.title, 30);
		fscanf_s(Lib_f, "%d ", &tmp->book.year);
		fscanf_s(Lib_f, "%c\n", &tmp->book.group);
		if (*head == NULL) {
			tmp->prev = NULL;
			*head = *tail = tmp;
		}
		else {
			(*tail)->next = tmp;
			tmp->prev = *tail;
			*tail = tmp;
		}
		tmp->next = NULL;

		tmp = (Node*)malloc(sizeof(Node));
	}

	fclose(Lib_f);
}