#include "Header_includer.h"
#include "Functions.h"
#include "Node.h"

int main()
{
	setlocale(LC_ALL, "ru");
	system("chcp 1251");
	system("cls");
	std::cout << "===========   Лабораторная работа №9   ===========\n";

	int size = 0;
	int choice;
	Node* head = NULL;
	Node* tail = NULL;

	do {
		std::cout << "1. Создание списка\n"
			<< "2. Печать списка с начала\n"
			<< "3. Печать списка с конца\n"
			<< "4. Поиск по критерию с начала списка\n"
			<< "5. Поиск по критерию с конца списка\n"
			<< "6. Добавление элемента\n"
			<< "7. Удаление  любого элемента\n"
			<< "8. Сортировка\n"
			<< "9. Запись нового списка в файл\n"
			<< "10. Печать нового списка из файла\n"
			<< "11. Выход из программы\n";


		std::cout << "Ваш выбор: ";
		std::cin >> choice;

		switch (choice) {
		case 1: {
			Creat_List(&head,&tail,&size);
		}
			break;
		case 2: {
			Print_List_Begin(head);
		}
			break;
		case 3: {
			Print_List_End(tail);
		}
			break;
		case 4:
			Found_with_Beg(head);
			break;
		case 5:
			Found_with_End(tail);
			break;
		case 6: {
			int elem=0;
			if (head==NULL) {
				printf("Создайте список!!!\n");
				break;
			}

			printf("Введите каким элементом хотите добавить: ");
			scanf_s("%d", &elem);
			Add_Elem(&head, &tail,&size, elem);
		}
			break;
		case 7: {
			int elem = 0;
			if (head == NULL) {
				printf("Создайте список!!!\n");
				break;
			}
			printf("Введите каким элементом хотите удалить: ");
			scanf_s("%d", &elem);
			
			Remove_Elem(&head, &tail, &size, elem);

		}
			break;
		case 8:
			Merg(head,&size);
			break;
		case 9: {
			Add_to_File(head);
		}
			break;
		case 10: {
			if (head != NULL) {
				printf("Список уже создан!!!\n");
				break;
			}
			CreatList_File(&size,&tail,&head);
		}
			break;
		case 11:
			exit(0);
			break;
		default: std::cout << "Введено неверное значение!!!";
		}
	} while (choice != 11);

}