#include "SimpleHashTable.h"

// 해시 테이블 생성
HashTable* SHT_CreateHashTable(int TableSize)
{
	HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
	HT->Table = (Node*)malloc(sizeof(Node)*TableSize);
	HT->TableSize = TableSize;
	
	return HT;
}

// 해시테이블에 정보 입력, Key는 주소로 사용할 데이터, Value는 그 주소에 저장할 데이터
void SHT_Set(HashTable* HT, KeyType Key, ValueType Value)
{
	int Address = SHT_Hash(Key, HT->TableSize);
	
	HT->Table[Address].Key = Key;
	HT->Table[Address].Value = Value;
}

// Key를 입력하면 해시테이블에서 Key를 해시한 후 그 주소에 있는 Value 데이터를 반환
ValueType SHT_Get(HashTable* HT, KeyType Key)
{
	int Address = SHT_Hash(Key, HT->TableSize);
	
	return HT->Table[Address].Value;
}

// 해시테이블 동적할당 해제
void SHT_DestroyHashTable(HashTable* HT)
{
	free(HT->Table);
	free(HT);
}

// Key를 해시 하는 함수 해시해서 그걸 주소로 쓴다
int SHT_Hash(KeyType Key, int TableSize)
{
	return Key % TableSize; // 나눗셈법으로 해시하기
}