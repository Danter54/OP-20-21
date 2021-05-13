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

void Check(Node*head, int *size) {

	if (head==NULL) {
		printf("������ �� �����������!!!\n");
		return;
	}
	int choice = 0;
	

	printf("�������� �������� ������: \n");
	printf("1-�� ������\n");
	printf("2-�� ��������\n");
	printf("3-�� ����\n");
	printf("4-�� ������\n");
	printf("��� �����: ");
	scanf_s("%d", &choice);

	bool b_temp = false;
	Node* temp = head;
	switch (choice) {
	case 1:{
		char t_surname[30];
		printf("������� �������: ");
		scanf_s("%s", t_surname, 30);
		while (temp != NULL) {
			if (strcmp(temp->book.surname, t_surname) == 0) {
				b_temp = true;
			}
			temp = temp->next;
		}
		if (b_temp == true) {
			std::cout << "---------------------------------------------------" << std::endl;
			std::cout << "|                 ������� ����������              |" << std::endl;
			std::cout << "|-------------------------------------------------|" << std::endl;
			std::cout << "| ����� ����� |  ��������  | ��� ������� | ������ |" << std::endl;
			std::cout << "|-------------------------------------------------|" << std::endl;
			for (int i = 0; i < (*size); i++) {
				if (strcmp(head->book.surname, t_surname) == 0) {
					printf("|  %9s  | %10s |    %5d    |    %c   |\n", head->book.surname, head->book.title, head->book.year, head->book.group);
				}
				head = head->next;
			}
			std::cout << "|-------------------------------------------------|" << std::endl;
			std::cout << "| ����������: � - �������������� ����������;      |" << std::endl;
			std::cout << "| � - ������� ����������; � - ���������� ������ - |" << std::endl;
			std::cout << "| ����                                            |" << std::endl;
			std::cout << "---------------------------------------------------" << std::endl;
		}
		else printf("��� ������ ������!!!\n");
		break;
	}
	case 2:{
		char t_title[30];
		printf("������� ��������: ");
		scanf_s("%s", t_title, 30);
		while (temp != NULL) {
			if (strcmp(temp->book.title, t_title) == 0) {
				b_temp = true;
			}
			temp = temp->next;
		}
		if (b_temp == true) {
			std::cout << "---------------------------------------------------" << std::endl;
			std::cout << "|                 ������� ����������              |" << std::endl;
			std::cout << "|-------------------------------------------------|" << std::endl;
			std::cout << "| ����� ����� |  ��������  | ��� ������� | ������ |" << std::endl;
			std::cout << "|-------------------------------------------------|" << std::endl;
			for (int i = 0; i < (*size); i++) {
				if (strcmp(head->book.title, t_title) == 0) {
					printf("|  %9s  | %10s |    %5d    |    %c   |\n", head->book.surname, head->book.title, head->book.year, head->book.group);
				}
				head = head->next;
			}
			std::cout << "|-------------------------------------------------|" << std::endl;
			std::cout << "| ����������: � - �������������� ����������;      |" << std::endl;
			std::cout << "| � - ������� ����������; � - ���������� ������ - |" << std::endl;
			std::cout << "| ����                                            |" << std::endl;
			std::cout << "---------------------------------------------------" << std::endl;
		}
		else printf("��� ����� �����!!!\n");
		break;
	}
	case 3: {
		int t_year = 0;
		printf("������� ���: ");
		scanf_s("%d", &t_year);
		while (temp != NULL) {
			if (temp->book.year == t_year) {
				b_temp = true;
			}
			temp = temp->next;
		}

		if (b_temp == true) {
			std::cout << "---------------------------------------------------" << std::endl;
			std::cout << "|                 ������� ����������              |" << std::endl;
			std::cout << "|-------------------------------------------------|" << std::endl;
			std::cout << "| ����� ����� |  ��������  | ��� ������� | ������ |" << std::endl;
			std::cout << "|-------------------------------------------------|" << std::endl;
			for (int i = 0; i < (*size); i++) {
				if (head->book.year == t_year) {
					printf("|  %9s  | %10s |    %5d    |    %c   |\n", head->book.surname, head->book.title, head->book.year, head->book.group);
				}
				head = head->next;
			}
			std::cout << "|-------------------------------------------------|" << std::endl;
			std::cout << "| ����������: � - �������������� ����������;      |" << std::endl;
			std::cout << "| � - ������� ����������; � - ���������� ������ - |" << std::endl;
			std::cout << "| ����                                            |" << std::endl;
			std::cout << "---------------------------------------------------" << std::endl;
		}
		else printf("��� ����� �����!!!\n");
		break; }
	case 4:
	{
		char t_group;
		printf("������� ������: ");
		std::cin >> t_group;

		while (temp != NULL) {
			if (t_group==temp->book.group) {
				b_temp = true;
			}
			temp = temp->next;
		}

		if (b_temp == true) {
			std::cout << "---------------------------------------------------" << std::endl;
			std::cout << "|                 ������� ����������              |" << std::endl;
			std::cout << "|-------------------------------------------------|" << std::endl;
			std::cout << "| ����� ����� |  ��������  | ��� ������� | ������ |" << std::endl;
			std::cout << "|-------------------------------------------------|" << std::endl;
			for (int i = 0; i < (*size); i++) {
				if (head->book.group == t_group) {
					printf("|  %9s  | %10s |    %5d    |    %c   |\n", head->book.surname, head->book.title, head->book.year, head->book.group);
				}
				head = head->next;
			}
			std::cout << "|-------------------------------------------------|" << std::endl;
			std::cout << "| ����������: � - �������������� ����������;      |" << std::endl;
			std::cout << "| � - ������� ����������; � - ���������� ������ - |" << std::endl;
			std::cout << "| ����                                            |" << std::endl;
			std::cout << "---------------------------------------------------" << std::endl;
		}
		else printf("��� ����� �����!!!\n");
	}
		break;
	default:printf("������� ������ ��������!!!\n");
		break;
	}

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

Node *CreatList_File(int *size) {

	FILE* Lib_f;

	fopen_s(&Lib_f,"Library.txt", "rt");

	if (Lib_f==NULL) {
		printf("���� �� ������� �������!!!\n");
		return NULL;
	}

	Node* tmp = NULL, *begin, *head;
	head= begin = tmp = (Node*)malloc(sizeof(Node));

	
	while (!feof(Lib_f))
	{
		(*size)++;
		fscanf_s(Lib_f, "%s", tmp->book.surname, 30);
		fscanf_s(Lib_f, "%s", tmp->book.title, 30);
		fscanf_s(Lib_f, "%d ", &tmp->book.year);
		fscanf_s(Lib_f, "%c\n", &tmp->book.group);
		begin->next = tmp;
		begin = tmp;

		tmp = (Node*)malloc(sizeof(Node));
	}
	begin->next = NULL;
	fclose(Lib_f);
	return head;
}