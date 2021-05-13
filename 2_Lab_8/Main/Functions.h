#pragma once
#include "Node.h"

void Creat(Node** head, int* size);
void Show(Node* head);
void AddEl(Node* head, int* size);
void Erase(Node* head, int* size);
void Merg(Node* head, int* size);
void Add_to_File(Node* head);
Node* CreatList_File(int* size);
void Check(Node* head, int* size);