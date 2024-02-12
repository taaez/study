#include "DoublyLinkedList.h"

// 노드 생성
Node* DLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node)); //Node의 크기만큼 Node*형으로 NewNode 구조체 변수 생성
	
	NewNode->Data = NewData; // 노드에 데이터 저장
	NewNode->PrevNode = NULL; // 이전 노드에 대한 포인터 NULL로 초기화, 
	NewNode->NextNode = NULL; // 다음 노드에 대한 포인터 NULL로 초기화
	
	return NewNode;
}

// 노드 소멸
void DLL_DestroyNode(Node* Node)
{
	free(Node);
}

// 노드 추가
void DLL_AppendNode(Node** Head, Node* NewNode)
{
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		Node* Tail = (*Head);
		while(Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail;
		// NewNode->NextNode=NULL; 노드 자체를 만들때 만들어놨으므로 안해도 됨
	}
}

// 노드 삽입, 삽입할 위치를 Current로 줬을때
void DLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = Current;
	
	if (Current->NextNode != NULL)
	{
		Current->NextNode->PrevNode = NewNode;
		Current->NextNode = NewNode;
	}
}

/*
// 새로운 헤드 추가
void SLL_InsertNewHead(Node** Head, Node* NewHead)
{
	if (Head == NULL)
	{
		(*Head) = NewHead;
	}
	else
	{
		NewHead->NextNode = (*Head);
		(*Head) = NewHead;
	}
}
*/

// 노드 제거, 제거할 노드만 알려줬을때
void DLL_RemoveNode(Node** Head, Node* Remove)
{
	if ( *Head == Remove)
	{
		*Head=Remove->NextNode;
		if (*Head == Remove)
			(*Head)->PrevNode = NULL;
		
		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
	else
	{
		Node* Temp = Remove;
		
		if (Remove->PrevNode != NULL)
			Remove->PrevNode->NextNode = Temp->NextNode;
		
		if (Remove->NextNode != NULL)
			Remove->NextNode->PrevNode = Temp->PrevNode;
		
		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
}


// 노드 탐색
Node* DLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;
	
	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}
	
	return Current;
}

// 노드 개수세기
int DLL_GetNodeCount(Node* Head)
{
	unsigned int Count = 0;
	Node* Current = Head;
	
	while (Current != NULL)
	{
		Current=Current->NextNode;
		Count++;
	}
	
	return Count;
}

void PrintNode(Node* _Node)
{
	if (_Node->PrevNode == NULL)
		printf("Prev: NULL");
	else
		printf("Prev: %d", _Node->PrevNode->Data);
	
		printf("Current: %d", _Node->Data);
	
	if (_Node->NextNode == NULL)
		printf("Next: NULL\n");
	else
		printf("Next: %d", _Node->NextNode->Data);
}