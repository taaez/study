#ifndef DOUBLY_LINKED_H
#define DOUBLY_LINKED_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* PrevNode; // 싱글링크드리스트와의 차이점 이전 노드와의 포인터 연결도 있다.
	struct tagNode* NextNode;
} Node;

// 함수 원형 선언
Node*	DLL_CreateNode(ElementType NewData);
void	DLL_DestroyNode(Node* Node);
void	DLL_AppendNode(Node** Head, Node* NewNode);
void	DLL_InsertAfter(Node* Current, Node* NewNode);
void	DLL_RemoveNode(Node** Head, Node* Remove);
Node*	DLL_GetNodeAt(Node* Head, int Location);
int		DLL_GetNodeCount(Node* Head);

#endif