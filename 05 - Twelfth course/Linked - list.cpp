#include <iostream>

using namespace std;


class Node
{
public:
	int Value;
	Node* Next;
};

void InsertAtBeginning(Node*& Head, int Value)
{
	Node* NewNode = new Node;

	NewNode->Value = Value;

	NewNode->Next = Head;

	Head = NewNode;
}

void PrintList(Node* Head)
{
	while (Head != NULL)
	{
		cout << Head->Value << "\n";
		Head = Head->Next;
	}
}

Node* Find(Node* Head, int ValueToFind)
{
	while (Head != NULL)
	{
		if (Head->Value == ValueToFind)
			return Head;

		Head = Head->Next;
	}

	return NULL;
}

Node* FindLastNode(Node* Head)
{
	while (Head->Next != NULL)
	{
		Head = Head->Next;

	}
	return Head;
}

void InsertAfter(Node* PreviousNode, int ValueToInsert)
{
	Node* NodeToInsert = new Node;

	NodeToInsert->Value = ValueToInsert;

	NodeToInsert->Next = PreviousNode->Next;

	PreviousNode->Next = NodeToInsert;
}

void InsertAtEnd(Node*& Head, int Value)
{
	Node* NewNode = new Node;
	NewNode->Next = NULL;
	NewNode->Value = Value;

	if (Head == NULL)
	{
		Head = NewNode;
		return;
	}

	Node* LastNode = FindLastNode(Head);
	LastNode->Next = NewNode;
}

void DeleteNode(Node*& Head, int Value)
{
	Node* Current = Head, * Prev = NULL;

	if (Head == NULL)
	{
		return;
	}
	else if (Head->Value == Value)
	{
		Head = Current->Next;
		delete Current;
		return;
	}


	while (Current != NULL && Current->Value != Value)
	{
		Prev = Current;
		Current = Current->Next;
	}

	if (Current == NULL)
		return;

	Prev->Next = Current->Next;
	delete Current;
}

void DeleteFirstNode(Node*& Head)
{
	if (Head != NULL)
	{
		Node* Current = Head;

		Head = Current->Next;

		delete Current;
	}
}

void DeleteLastNode(Node*& Head)
{
	Node* Current = Head, * Prev = NULL;

	if (Head == NULL)
	{
		return;
	}

	if (Head->Next == NULL)
	{
		Head = Current->Next;
		delete Current;
		return;
	}

	while (Current->Next != NULL)
	{
		Prev = Current;
		Current = Current->Next;
	}

	Prev->Next = NULL;
	delete Current;
}

int main()
{
	Node* Head = NULL;

	InsertAtEnd(Head, 1);
	InsertAtEnd(Head, 2);
	InsertAtEnd(Head, 3);
	InsertAtEnd(Head, 4);
	InsertAtEnd(Head, 5);
	InsertAtEnd(Head, 6);

	DeleteFirstNode(Head);
	DeleteLastNode(Head);

	PrintList(Head);


	return 0;
}