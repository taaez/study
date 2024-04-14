#include "DoublyLinkedList.h"

int main()
{
	int		i		= 0;
	int		Count	= 0;
	Node*	List	= NULL;
	Node*	Current = NULL;
	Node*	NewNode = NULL;
	
	//노드 5개 추가, 생성
	for (i=0; i<5; i++)
	{
		NewNode = DLL_CreateNode(i); // i를 데이터로 가지는 노드 생성
		DLL_AppendNode(&List, NewNode); // 위에서 만든 노드를 리스트로 연결
	}

	// 리스트 출력
	Count = DLL_GetNodeCount(List);
	for (i=0; i<Count; i++)
	{
		Current = DLL_GetNodeAt(List,  i);
		printf("List[%d] : %d\n", i, Current->Data);
	}
	
	// 리스트의 세 번째 칸 뒤에 3000값 노드 삽입
	printf("\nInserting 3000 After [2]... \n\n");
	
	Current = DLL_GetNodeAt(List, 2);
	NewNode = DLL_CreateNode(3000);
	DLL_InsertAfter(Current, NewNode);
	
	// 리스트 출력
	Count = DLL_GetNodeCount(List);
	for (i=0; i<Count; i++)
	{
		Current = DLL_GetNodeAt(List,  i);
		printf("List[%d] : %d\n", i, Current->Data);
	}
	
	// 모드 노드를 메모리에서 제거, 해제
	printf("\nDestroying List...\n");
	
	for (i=0; i<Count; i++)
	{
		Current = DLL_GetNodeAt(List, 0);
		
		if (Current != NULL)
		{
			DLL_RemoveNode(&List, Current);
			DLL_DestroyNode(Current);
		}
	}
	
	return 0;
}