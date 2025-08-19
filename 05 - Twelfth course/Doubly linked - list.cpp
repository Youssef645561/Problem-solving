#include <iostream>

using namespace std;


class Node
{
public:
	int Value;
	Node* Next;
	Node* Prev;
};

void PrintList(Node* Head)
{
	cout << "Null <--> ";

	while (Head != NULL)
	{
		cout << Head->Value << " <--> ";
		Head = Head->Next;
	}

	cout << "Null";
}

Node* Find(Node* Head, int ValueToFind)
{
	while (Head != NULL)
	{
		if (Head->Value == ValueToFind)
		{
			return Head;
		}

		Head = Head->Next;

	}

	return NULL;
}

void InsertAtBeginning(Node*& Head, int Value)
{
	Node* NewNode = new Node;

	NewNode->Value = Value;
	NewNode->Next = Head;
	NewNode->Prev = NULL;

	if (Head != NULL)
	{
		Head->Prev = NewNode;
	}

	Head = NewNode;
}

void InsertAfter(Node* PrevNode, int ValueToInsert)
{
	Node* NewNode = new Node;

	NewNode->Value = ValueToInsert;
	NewNode->Next = PrevNode->Next;
	NewNode->Prev = PrevNode;

	if (PrevNode->Next != NULL)
		PrevNode->Next->Prev = NewNode;

	PrevNode->Next = NewNode;
}

void InsertAtEnd(Node*& Head, int Value)
{
	Node* NewNode = new Node;

	NewNode->Value = Value;
	NewNode->Next = NULL;

	if (Head == NULL)
	{
		NewNode->Prev = NULL;
		Head = NewNode;
	}
	else
	{
		Node* Current = Head;
		while (Current->Next != NULL)
		{
			Current = Current->Next;
		}
		Current->Next = NewNode;
		NewNode->Prev = Current;
	}
}

void DeleteNode(Node*& Head, int Value)
{
	Node* Current = Find(Head, Value);

	if (Current == NULL || Head == NULL)
	{
		return;
	}
	else if (Head == Current)
	{
		Head = Current->Next;

		if (Head != NULL)
			Head->Prev = NULL;
	}
	else
	{
		if (Current->Next != NULL)
			Current->Next->Prev = Current->Prev;

		Current->Prev->Next = Current->Next;

	}
	delete Current;
}

void DeleteFirstNode(Node*& Head)
{
	if (Head == NULL)
		return;

	Node* Current = Head;

	if (Current->Next == NULL)
	{
		Head = NULL;
		delete Current;
		return;
	}

	Head = Current->Next;

	Head->Prev = NULL;

	delete Current;
}

void DeleteLastNode(Node*& Head)
{
	if (Head == NULL)
		return;

	Node* Current = Head;

	if (Current->Next == NULL)
	{
		Head = NULL;
		delete Current;
		return;
	}

	while (Current->Next != NULL)
	{
		Current = Current->Next;
	}

	Current->Prev->Next = NULL;
	delete Current;
}

int main()
{
	Node* Head = NULL;

	InsertAtEnd(Head, 1);
	InsertAtEnd(Head, 2);
	InsertAtEnd(Head, 3);
	InsertAtEnd(Head, 4);

	Node* NodeToFind = Find(Head, 3);

	InsertAfter(NodeToFind, 66);

	DeleteLastNode(Head);
	DeleteFirstNode(Head);
	DeleteFirstNode(Head);
	DeleteLastNode(Head);
	DeleteFirstNode(Head);
	DeleteFirstNode(Head);


	PrintList(Head);


	return 0;
}
