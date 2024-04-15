/*
'개방 주소법'
충돌이 일어나면 해시테이블 내의 새로운 주소를 '탐사'하여 충돌된 데이터를 입력하는 방식으로 동작한다.
이 '탐사' 에는 선형 탐사, 제곱 탐사 등이 있는데 선형탐사는 클러스터 현상이 많이 발생하고 제곱탐사도 2차 클러스터 현상이 발생할 가능성이 높다.
(선형탐사는 옆으로 한칸, 두칸, 세칸씩 이동 제곱탐사는 옆으로 한칸, 네칸, 아홉칸씩 이동)

따라서 '이중해싱'의 방법을 통해서 개방주소법을 사용하는 것이 좋다
'이중해싱'은 충돌이 발생했을때 기존 주소보다 '얼마나' 이동시켜서 데이터를 저장할지 정해야하는데 이 '얼마나'의 폭을 제 2의 해시함수에 넣고 해시값을 구해서 정하는 방식이다.
이렇게 하면 탐사 이동폭의 규칙성은 없애면서 같은 키에 대해서는 항상 같은 결과를 얻을 수 있다.

'재해싱'
해시테이블은 데이터가 들어가있지 않은 여유공간이 70% 미만 정도는 되어야 제 성능이 나온다. 따라서 데이터가 너무 많이 차면 해시테이블의 크기를 키워주는 재해싱을 통해서 해시테이블의 성능이 줄어들지 않게 해야한다.
*/
#ifndef OPEN_ADDRESSING_H
#define OPEN_ADDRESSING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* KeyType;
typedef char* ValueType;

enum ElementStatus
{
	EMPTY = 0,
	OCCUPIED = 1 // 해시테이블의 상태, 비어있으면 0, 비어있지 않으면 1, 이걸 통해서 개방주소법으로 충돌해결할지 말지 결정
};

typedef struct tagElementType
{
	KeyType Key;
	ValueType Value;
	
	enum ElementStatus Status;
} ElementType;

typedef struct tagHashTable
{
	int OccupiedCount; // 재해싱을 위해 
	int TableSize;
	
	ElementType* Table;
} HashTable;

HashTable* OAHT_CreateHashTable(int TableSize);
void OAHT_DestroyHashTable(HashTable* HT);
void OAHT_ClearElement(ElementType* Element);

void OAHT_Set(HashTable** HT, KeyType Key, ValueType Value);
ValueType OAHT_Get(HashTable* HT, KeyType Key);
int OAHT_Hash(KeyType Key, int KeyLength, int TableSize);
int OAHT_Hash2(KeyType Key, int KeyLength, int TableSize); // 충돌이 발생했을때 옆으로 이동할 폭을 정해주는 제 2의 해시함수

void OAHT_Rehash(HashTable** HT);

#endif