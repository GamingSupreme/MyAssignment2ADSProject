#include "List.h"

void List::insertAtFront(int number)
{
	Node* newNode = new Node(number);

	newNode->next = Head;
	Head = newNode;
}

void List::insertAtEnd(int number)
{
	//Just incase theres nothing in the list yet
	if (Head == NULL)
	{
		insertAtFront(number);
		return;
	}

	Node* newNode = new Node(number);

	Node* iterator = Head;
	while (iterator->next != NULL)
	{
		iterator = iterator->next;
	}
	iterator->next = newNode;
}

void List::deleteAtFront()
{
	//cant delete anything if theres nothing to delete
	if (Head == NULL)
	{
		return;
	}

	Node* iterator = Head;
	Head = Head->next;
	delete iterator;

}

void List::deleteAtEnd()
{
	//cant delete something if theres nothing
	if (Head == NULL)
	{
		return;
	}

	Node* iterator = Head;
	Node* previous = Head;

	while (iterator->next != NULL)
	{
		previous = iterator;
		iterator = iterator->next;
	}
	previous->next = NULL;
	delete iterator;
}
