#include "Node.h"
#include "Header_includer.h"
#include "Functions.h"

void Creat(Node** head, int* size) {
	int choice = 0;
	if (*head != NULL) {
		std::cout << "������ ������!!!\n";
		return;
	}

	do {
		Node* tmp = (Node*)malloc(sizeof(Node));
		(*size)++;
		tmp->next = NULL;
		std::cout << "������� ������� ������, ��������, ��� � ������ �����: ";
		std::cin >> tmp->book.surname >> tmp->book.title >> tmp->book.year >> tmp->book.group;
		if (*head == NULL) {
			*head = tmp;
		}
		else {
			tmp->next = (*head);
			(*head) = tmp;
		}
		std::cout << "������ ����������:\n";
		std::cout << "1-��\n2-���\n";
		std::cout << "��� �����: ";

		std::cin >> choice;

	} while (choice != 2);


}

void Show(Node* head) {
	if (head == NULL) {
		printf("������ ���!!!\n");
		return;
	}
	Node* tmp;
	tmp = head;
	std::cout << "---------------------------------------------------" << std::endl;
	std::cout << "|                 ������� ����������              |" << std::endl;
	std::cout << "|-------------------------------------------------|" << std::endl;
	std::cout << "| ����� ����� |  ��������  | ��� ������� | ������ |" << std::endl;
	std::cout << "|-------------------------------------------------|" << std::endl;
	while (tmp != NULL) {
		printf("|  %9s  | %10s |    %5d    |    %c   |\n", tmp->book.surname, tmp->book.title, tmp->book.year, tmp->book.group);
		tmp = tmp->next;
	}
	std::cout << "|-------------------------------------------------|" << std::endl;
	std::cout << "| ����������: � - �������������� ����������;      |" << std::endl;
	std::cout << "| � - ������� ����������; � - ���������� ������ - |" << std::endl;
	std::cout << "| ����                                            |" << std::endl;
	std::cout << "---------------------------------------------------" << std::endl;

}


void AddEl(Node* head, int* size) {
	Node* temp = NULL;

	unsigned int i = 0;
	if (head == NULL) {
		std::cout << "�������� ������!!!\n";
		return;
	}
	int n = 0;
	std::cout << "������� � ����� ����� �� ������ ��������(�� 0 �� ����������), "
		<< "� ��������� ������ ������� ��������� � �����: ";
	std::cin >> n;
	while (i < n - 1 && head->next)
	{
		head = head->next;
		i++;
	}
	temp = (Node*)malloc(sizeof(Node));
	std::cout << "������� ������� ������, ��������, ��� � ������ �����: ";
	std::cin >> temp->book.surname >> temp->book.title >> temp->book.year >> temp->book.group;
	if (head->next) {
		temp->next = head->next;
	}
	else {
		temp->next = NULL;
	}
	head->next = temp;
	(*size)++;

}

void Erase(Node* head, int* size) {
	int el = 0;
	if (head == NULL) {
		std::cout << "�������� ������!!!\n";
		return;
	}
	std::cout << "������� ������� ������� �� ������ �������: ";
	std::cin >> el;
	for (;;) {
		if (el > 0 || el <= (*size)) {
			break;
		}
		else {
			std::cout << "������� ������ ��������!!!\n";
			std::cout << "������� ������� ������� �� ������ �������: ";
			std::cin >> el;
		}
	}
	Node* temp_pos = head;

	if ((el) == 0) {
		head = head->next;
		(*size)--;
		free(temp_pos);
	}
	else {
		for (int i = 0; i < el - 1; i++)
			temp_pos = temp_pos->next;

		Node* Temp = temp_pos->next;
		if (temp_pos->next == NULL) {
			temp_pos->next = NULL;
		}
		else
			temp_pos->next = Temp->next;
		free(Temp);
	}

}

void Merg(Node* head, int* size) {
	if (head == NULL) {
		std::cout << "�������� ������!!!\n";
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

void Add_to_File(Node* head) {
	if (head == NULL) {
		std::cout << "�������� ������!!!\n";
		return;
	}
	FILE* Libr_f = NULL;
	fopen_s(&Libr_f, "Library.txt", "w");

	if (Libr_f == NULL) {
		printf("�� ������� ������� ����");
		return;
	}

	while (head != NULL) {
		fprintf_s(Libr_f, "%s %s %d %c\n", head->book.surname, head->book.title, head->book.year, head->book.group);
		head = head->next;
	}

	fclose(Libr_f);

}