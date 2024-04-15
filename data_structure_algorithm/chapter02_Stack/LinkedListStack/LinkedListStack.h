#ifndef LINKEDLIST_STACK_H
#define LINKEDLIST_STACK_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tagNode
{
	char* Data;
	struct tagNode* NextNode;
} Node;

typedef struct tagLinkedListStack
{
	Node* List;
	Node* Top;
} LinkedListStack;

void LLS_CreateStack(LinkedListStack** Stack); // 스택 생성
void LLS_DestroyStack(LinkedListStack* Stack); // 스택 해제
 
Node* LLS_CreateNode(char* Data); // 스택에 넣을 노드 생성
void LLS_DestroyNode(Node* _Node); // 노드 해제, 노드도 malloc으로 동적 할당 했다

void LLS_Push(LinkedListStack* Stack, Node* NewNode); // 스택에 삽입 push
Node* LLS_Pop(LinkedListStack* Stack); // 스택에서 삭제하면서 반환

Node* LLS_Top(LinkedListStack* Stack); // 스택의 Top 반환
int LLS_GetSize(LinkedListStack* Stack); // 스택 크기 구하기, 순차 탐색으로 리스트의 크기를 세서
int LLS_IsEmpty(LinkedListStack* Stack);

#endif
