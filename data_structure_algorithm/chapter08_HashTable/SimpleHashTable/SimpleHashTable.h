/*
'해시테이블'
'해시'란 어떤 데이터를 입력받았을 때 '해시함수'를 통해 값을 변형해서 해시값을 얻는 것을 말한다.
해시함수가 해시하는 방식에는 나눗셈법, 자릿수 접기 등이 있다.

해시 테이블은 특히 금융 분야에서 많이 사용한다.
**해시테이블은 데이터가 입력되지 않은 여유공간이 많아야 제 성능을 유지할 수 있다. 대체로 70~80%가 임계점이다.
*공간을 팔아 시간(성능)을 얻어냄*
*/

#ifndef SIMPLE_HASHTABLE_H
#define SIMPLE_HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef int ValueType;

typedef struct tagNode
{
	KeyType Key;
	ValueType Value;
} Node;

typedef struct tagHashTable
{
	int TableSize;
	Node* Table;
} HashTable;

HashTable* SHT_CreateHashTable(int TableSize);
void SHT_Set(HashTable* HT, KeyType Key, ValueType Value);
ValueType SHT_Get(HashTable* HT, KeyType key);
void SHT_DestroyHashTable(HashTable* HT);
int SHT_Hash(KeyType Key, int TableSize); // Key를 Table 사이즈로 나눈 나머지를 해시값으로 쓴다

#endif