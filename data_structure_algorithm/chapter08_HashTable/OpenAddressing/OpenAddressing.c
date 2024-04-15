#include "OpenAddressing.h"

// 해시테이블을 만드는 함수, 
HashTable* OAHT_CreateHashTable(int TableSize)
{
	HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
	HT->Table = (ElementType*)malloc(sizeof(ElementType) * TableSize);
	
	memset(HT->Table, 0, sizeof(ElementType) * TableSize); // 해시테이블의 모든 값을 0으로 세팅
	
	HT->TableSize = TableSize;
	HT->OccupiedCount = 0;
	
	return HT;
}

// 해시테이블에 정보 입력, Key는 주소로 사용할 데이터, Value는 그 주소에 저장할 데이터
void OAHT_Set(HashTable** HT, KeyType Key, ValueType Value)
{
	int KeyLen, Address, StepSize; // Key의 길이, 주소, 이동폭
	double Usage; // 해시테이블 크기에 대한 현재 사용 공간, %로 표시
	
	Usage = (double)(*HT)->OccupiedCount / (*HT)->TableSize;
	
	if (Usage > 0.5) // 임계치를 50%로 설정, 50% 넘어가면 재해싱
	{
		OAHT_Rehash(HT);
	}
	
	KeyLen = strlen(Key);
	Address = OAHT_Hash(Key, KeyLen, (*HT)->TableSize);
	StepSize = OAHT_Hash2(Key, KeyLen, (*HT)->TableSize); // 충돌이 발생했을 때 제 2의 해시함수를 이용해서 이동폭 결정
	
	while ((*HT)->Table[Address].Status != EMPTY && strcmp((*HT)->Table[Address].Key, Key) != 0) // ** 해시테이블에 비어있지 않고, Key값이 맞지 않으면 충돌이므로 위치 바꾸기
		//충돌이 안 일어날때까지 반복문 돌리기 위한 조건
	{
		printf("Collision occured! : Key(%s), Address(%d), StepSize(%d)\n", Key, Address, StepSize);
		
		Address = (Address + StepSize) % (*HT)->TableSize;
	}
	
	(*HT)->Table[Address].Key = (char*)malloc(sizeof(char) * (KeyLen)+1);
	strcpy((*HT)->Table[Address].Key, Key);
	
	(*HT)->Table[Address].Value = (char*)malloc(sizeof(char) * (strlen(Value))+1);
	strcpy((*HT)->Table[Address].Value, Value);
	
	(*HT)->Table[Address].Status = OCCUPIED;
	
	(*HT)->OccupiedCount++; // 사용공간 +1
	
	printf("key(%s) entered at address(%d)\n", Key, Address); // 데이터간 들어간 위치 표시
}

// Key를 입력하면 해시테이블에서 Key를 해시한 후 그 주소에 있는 Value 데이터를 반환
ValueType OAHT_Get(HashTable* HT, KeyType Key)
{
	int KeyLen = strlen(Key);
	
	int Address = OAHT_Hash(Key, KeyLen, HT->TableSize);
	int StepSize = OAHT_Hash2(Key, KeyLen, HT->TableSize);
	
	while(HT->Table[Address].Status != EMPTY && strcmp(HT->Table[Address].Key, Key) != 0)
	{
		Address = (Address + StepSize) % HT->TableSize;
	}
	
	return HT->Table[Address].Value;
}

// 해시테이블의 요소 해제 Key, Value
void OAHT_ClearElement(ElementType* Element)
{
	if (Element->Status == EMPTY)
		return;
	
	free(Element->Key);
	free(Element->Value);
}

// 해시테이블 동적할당 해제
void OAHT_DestroyHashTable(HashTable* HT)
{
	// 각 링크드 리스트를 자유저장소에서 해제
	int i = 0;
	for (i=0; i<HT->TableSize; i++)
	{
		OAHT_ClearElement(&(HT->Table[i]));
	}
	
	// 해시 테이블 자유저장소에서 해제
	free(HT->Table);
	free(HT);
	
	// 순서대로 해야함 안그러면 링크드 리스트를 해제하지 못할수도?
}

// Key를 해시 하는 함수 해시해서 그걸 주소로 쓴다
int OAHT_Hash(KeyType Key, int KeyLength, int TableSize)
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

// 충돌이 일어났을 때 이동폭을 정해주는 제 2의 해시함수
int OAHT_Hash2(KeyType Key, int KeyLength, int TableSize)
{
	int i = 0;
	int HashValue = 0;
	
	for (i=0; i<KeyLength; i++)
	{
		HashValue = (HashValue << 2) + Key[i];
	}
	
	HashValue = HashValue % (TableSize - 3);
	
	return HashValue + 1;
}

// 사용공간이 50퍼가 넘어가면 재해싱 하는 함수
void OAHT_Rehash(HashTable** HT)
{
	int i = 0;
	ElementType* OldTable = (*HT)->Table;
	
	// 새 해시 테이블 만들기, 크기는 이전의 2배
	HashTable* NewHT = OAHT_CreateHashTable((*HT)->TableSize * 2);
	
	printf("\nRehashed. New table size is : %d\n\n", NewHT->TableSize);
	
	// 이전의 해시 테이블에 있던 데이터를 새 해시 테이블로 옮기기
	for (i=0; i<(*HT)->TableSize; i++)
	{
		if (OldTable[i].Status == OCCUPIED) // 이전 테이블에 있었던 데이터는
		{
			OAHT_Set(&NewHT, OldTable[i].Key, OldTable[i].Value); // 해시테이블에 넣기
		}
	}
	
	// 이전의 해시 테이블은 소멸시킨다.
	OAHT_DestroyHashTable((*HT));
	
	// HT 포인터에는 새로운 해시 테이블의 주소를 대입한다.
	(*HT) = NewHT;
}
