#pragma once
#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	int number;

	Node* next;

	Node();
	Node(int number);
};

