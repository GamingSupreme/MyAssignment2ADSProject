#pragma once
#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

class List
{
public:
	Node* Head = NULL;

	void insertAtFront(int number);
	void insertAtEnd(int number);

	void deleteAtFront();
	void deleteAtEnd();
};

