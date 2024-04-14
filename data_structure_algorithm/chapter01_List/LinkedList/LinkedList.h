#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int  ElementType;

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* NextNode;
} Node;

//함수 원형 선언
Node* SLL_CreateNode(ElementType Data); // 노드 생성, 동적할당
void  SLL_DestroyNode(Node* Node); // 노드 소멸, 해제
void  SLL_AppendNode(Node** Head, Node* NewNode); // 노드 추가
void  SLL_InsertAfter(Node* current, Node* NewNode); // 노드 삽입
void  SLL_InsertNewHead(Node** HEad, Node* NewHead); // 새로운 헤드노드 
void  SLL_RemoveNode(Node** Head, Node* Remove); // 노드 삭제
Node* SLL_GetNodeAt(Node* Head, int Location); // 노드 반환, 탐색
int   SLL_GetNodeCount(Node* Head); // 노드 개수세기

#endif
