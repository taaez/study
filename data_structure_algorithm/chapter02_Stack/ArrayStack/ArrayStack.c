#include "ArrayStack.h"

void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
	// 스택 자유저장소에 생성
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	
	// 입력된 Capacity만큼의 노드를 자유저장소에 생성
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node)*Capacity);
	
	// Capacity 및 Top 초기화
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = -1;
}

void AS_DestroyStack(ArrayStack* Stack)
{
	// 노드를 자유저장소에서 해제
	free(Stack->Nodes);
	
	// 스택을 자유저장소에서 해제
	free(Stack);
}

void AS_Push(ArrayStack* Stack, ElementType Data)
{
	Stack->Top++;
	Stack->Nodes[Stack->Top].Data = Data;
}

ElementType AS_Pop(ArrayStack* Stack)
{
	int Position = Stack->Top--;
	return Stack->Nodes[Position].Data;
	// Top을 1 줄이면서 반환
}

ElementType AS_Top(ArrayStack* Stack)
{
	return Stack->Nodes[Stack->Top].Data;
	// Top에 변화는 x, Top에 있던 데이터 그대로 반환
}

int AS_GetSize(ArrayStack* Stack)
{
	return Stack->Top+1; // 배열이 0부터 시작하므로
}

int AS_IsEmpty(ArrayStack* Stack)
{
	return (Stack->Top == -1); // Top의 위치를 통해 Stack이 비어있는지 여부 확인
}
