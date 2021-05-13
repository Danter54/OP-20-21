#include "Header_includer.h"
#include "Functions.h"
#include "Node.h"

int main()
{
	setlocale(LC_ALL, "ru");
	system("chcp 1251");
	system("cls");
	std::cout << "===========   ������������ ������ �9   ===========\n";

	int size = 0;
	int choice;
	Node* head = NULL;
	Node* tail = NULL;

	do {
		std::cout << "1. �������� ������\n"
			<< "2. ������ ������ � ������\n"
			<< "3. ������ ������ � �����\n"
			<< "4. ����� �� �������� � ������ ������\n"
			<< "5. ����� �� �������� � ����� ������\n"
			<< "6. ���������� ��������\n"
			<< "7. ��������  ������ ��������\n"
			<< "8. ����������\n"
			<< "9. ������ ������ ������ � ����\n"
			<< "10. ������ ������ ������ �� �����\n"
			<< "11. ����� �� ���������\n";


		std::cout << "��� �����: ";
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
				printf("�������� ������!!!\n");
				break;
			}

			printf("������� ����� ��������� ������ ��������: ");
			scanf_s("%d", &elem);
			Add_Elem(&head, &tail,&size, elem);
		}
			break;
		case 7: {
			int elem = 0;
			if (head == NULL) {
				printf("�������� ������!!!\n");
				break;
			}
			printf("������� ����� ��������� ������ �������: ");
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
				printf("������ ��� ������!!!\n");
				break;
			}
			CreatList_File(&size,&tail,&head);
		}
			break;
		case 11:
			exit(0);
			break;
		default: std::cout << "������� �������� ��������!!!";
		}
	} while (choice != 11);

}