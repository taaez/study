#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
} Node;

typedef struct tagArrayStack
{
	int Capacity; // 배열이기에, 용량 정해주기
	int Top; // 스택의 top
	Node* Nodes;
} ArrayStack;

void AS_CreateStack(ArrayStack** Stack, int Capacity); // 스택 생성
void AS_DestroyStack(ArrayStack* Stack); // 스택 해제 
void AS_Push(ArrayStack* Stack, ElementType Data); // 스택에 삽입
ElementType AS_Pop(ArrayStack* Stack); // 스택에서 top에 있는 데이터 삭제하면서 반환
ElementType AS_Top(ArrayStack* Stack); // 스택에서 top에 있는 데이터 삭제 x 반환
int AS_GetSize(ArrayStack* Stack); // 스택 크기 구하기, top의 위치로 반환
int AS_IsEmpty(ArrayStack* Stack);

#endif