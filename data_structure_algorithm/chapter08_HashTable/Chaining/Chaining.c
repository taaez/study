#include "Chaining.h"

// 해시테이블을 만드는 함수, 
HashTable* CHT_CreateHashTable(int TableSize)
{
	HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
	HT->Table = (List*)malloc(sizeof(Node) * TableSize);
	
	memset(HT->Table, 0, sizeof(List) * TableSize); // 해시테이블의 모든 값을 0으로 세팅
	
	HT->TableSize = TableSize;
	
	return HT;
}

// 링크드 리스트에 쓰일 노드 생성, Key값과 Value값을 가지고 있다.
Node* CHT_CreateNode(KeyType Key, ValueType Value)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	
	NewNode->Key = (char*)malloc(sizeof(char) * (strlen(Key)+1));
	strcpy(NewNode->Key, Key);
	
	NewNode->Value = (char*)malloc(sizeof(char) + (strlen(Value)+1));
	strcpy(NewNode->Value, Value);
	NewNode->Next = NULL;
	
	return NewNode;
}

// 노드 해제 함수 Key, Value 해제후 노드 자체 해제
void CHT_DestroyNode(Node* TheNode)
{
	free(TheNode->Key);
	free(TheNode->Value);
	free(TheNode);
}

// 해시테이블에 정보 입력, Key는 주소로 사용할 데이터, Value는 그 주소에 저장할 데이터
void CHT_Set(HashTable* HT, KeyType Key, ValueType Value)
{
	int Address = CHT_Hash(Key, strlen(Key), HT->TableSize);
	Node* NewNode = CHT_CreateNode(Key, Value);
	
	// 해당 주소가 비어 있는 겨우
	if (HT->Table[Address] == NULL)
	{
		HT->Table[Address] = NewNode;
	}
	// 해당 주소가 비어있지 않은 경우**
	else
	{
		List L = HT->Table[Address];
		NewNode->Next = L;
		HT->Table[Address] = NewNode; // 새로운 노드를 헤드 앞에 삽입하고 이전에 있던 링크드 리스트는 전체적으로 한칸 뒤로 옮기기, 순차탐색을 하지 않아서 성능유지에 도움을 준다. 
		
		printf("Collision occured : Key(%s), Address(%d)\n", Key, Address); // 충돌이 발생했음을 알리는 문구
	}
}

// Key를 입력하면 해시테이블에서 Key를 해시한 후 그 주소에 있는 Value 데이터를 반환
ValueType CHT_Get(HashTable* HT, KeyType Key)
{
	// 1. 원하는 값이 있는 해시테이블의 주소 찾기
	int Address = CHT_Hash(Key, strlen(Key), HT->TableSize);
	
	// 해싱한 주소에 있는 링크드 리스트 가져오기
	List TheList = HT->Table[Address];
	List Target = NULL;
	
	if (TheList == NULL)
		return NULL;
	
	// 2. 그 해시테이블에 있는 링크드 리스트에서 원하는 값을 찾을 때까지 순차탐색
	while(1)
	{
		if (strcmp(TheList->Key, Key) == 0) // 찾는 값이 나오면 strcmp가 0을 반환하고 반복문 종료
		{
			Target = TheList;
			break;
		}
		
		if (TheList->Next == NULL)
			break; // 리스트의 끝까지 했는데도 못 찾으면 반복문 종료
		else
			TheList = TheList->Next;
	}
	
	return Target->Value;
}

// 링크드 리스트 해제, 해시테이블 해제할 떄 같이 쓰임
void CHT_DestroyList(List L)
{
	if (L == NULL)
		return;
	
	if (L->Next != NULL)
		CHT_DestroyList(L->Next);
	
	CHT_DestroyNode(L);
}

// 해시테이블 동적할당 해제
void CHT_DestroyHashTable(HashTable* HT)
{
	// 각 링크드 리스트를 자유저장소에서 해제
	int i = 0;
	for (i=0; i<HT->TableSize; i++)
	{
		List L = HT->Table[i];
		CHT_DestroyList(L);
	}
	
	// 해시 테이블 자유저장소에서 해제
	free(HT->Table);
	free(HT);
	
	// 순서대로 해야함 안그러면 링크드 리스트를 해제하지 못할수도?
}

// Key를 해시 하는 함수 해시해서 그걸 주소로 쓴다
int CHT_Hash(KeyType Key, int KeyLength, int TableSize)
{
	int i = 0;
	int HashValue = 0;
	
	for (i=0; i<KeyLength; i++)
	{
		HashValue = (HashValue << 3) + Key[i]; // 자릿수 접기를 통해 해시하기, 문자열이기에 아스키코드 값 (0~127)이 더해진다.
	}
	/*
	'자릿수 접기'
	183929이 있을때 한 자리씩 더하거나 두 자리씩 더해서 얻은 값을 해시값으로 사용
	ex) 1+8+3+9+2+9 = 32 or 18+39+29 = 86
	문자열을 자릿수접기 하면 문자는 아스키코드로 인식하기 때문에 아스키코드 값(0~127)이 한 문자당 하나씩 더해진다.
	*/
	
	HashValue = HashValue % TableSize; // 테이블의 크기를 넘을 경우 해시값을 테이블의 크기로 나눈 나머지를 사용
	
	return HashValue;
}