#include "Header_includer.h"
#include "Node.h"
#include"Functions.h"



int main() {
	setlocale(LC_ALL, "ru"); 
	system("chcp 1251");
	system("cls");
	std::cout << "===========   Лабораторная работа №8   ===========\n";

	int size = 0;
	int choice;
	Node* head = NULL;

	do {
		std::cout << "1. Создание списка\n"
			<< "2. Печать списка\n"
			<< "3. Поиск по критерию\n"
			<< "4. Добавление элемента\n"
			<< "5. Удаление  любого элемента\n"
			<< "6. Сортировка\n"
			<< "7. Запись нового списка в файл\n"
			<< "8. Печать нового списка из файла\n"
			<< "9. Выход из программы\n";
		std::cout << "Ваш выбор: " ;
		std::cin >> choice;
		
		switch (choice) {
		case 1: Creat(&head, &size);
			break;
		case 2:
				Show(head);
				break;
		case 3:
			Check(head,&size);
				break;
		case 4:	
				AddEl(head,&size);
				break;
		case 5:
				Erase(head,&size);
				break;
		case 6:
				Merg(head, &size);
				break;
		case 7:
				Add_to_File(head);
				break;
		case 8:
			if (head!=NULL) {
				printf("Список уже создан!!!\n");
				break;
			}
			head = CreatList_File(&size);
			break;
		case 9:
			return 0;
			break;
		default: std::cout << "Введено неверное значение!!!";
		}
	} while (choice != 9);
	

	return 0;
}