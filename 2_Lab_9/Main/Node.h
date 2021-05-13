#pragma once

typedef struct Library {
	char surname [30];
	char title [30];
	int year;
	char group;
};



typedef struct Node {
	Library book;
    Node* next;
	Node* prev;
};
