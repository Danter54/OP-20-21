#include "Header_includer.h"
#include "Node.h"
#include"Functions.h"



int main() {
	setlocale(LC_ALL, "ru"); 
	system("chcp 1251");
	system("cls");
	std::cout << "===========   ������������ ������ �8   ===========\n";

	int size = 0;
	int choice;
	Node* head = NULL;

	do {
		std::cout << "1. �������� ������\n"
			<< "2. ������ ������\n"
			<< "3. ����� �� ��������\n"
			<< "4. ���������� ��������\n"
			<< "5. ��������  ������ ��������\n"
			<< "6. ����������\n"
			<< "7. ������ ������ ������ � ����\n"
			<< "8. ������ ������ ������ �� �����\n"
			<< "9. ����� �� ���������\n";
		std::cout << "��� �����: " ;
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
				printf("������ ��� ������!!!\n");
				break;
			}
			head = CreatList_File(&size);
			break;
		case 9:
			return 0;
			break;
		default: std::cout << "������� �������� ��������!!!";
		}
	} while (choice != 9);
	

	return 0;
}