#pragma once
#include "Node.h"

void Creat_List(Node** head, Node** tail, int* size);

void Print_List_Begin(Node* head);

void Print_List_End(Node* tail);

void Add_Elem(Node** head, Node** tail, int* size, int elem);

void Remove_Elem(Node** head, Node** tail, int* size, int elem);

void Found_with_Beg(Node* head);

void Found_with_End(Node* tail);

void Merg(Node* head, int* size);

void Add_to_File(Node* head);

void CreatList_File(int* size, Node** tail, Node** head);
