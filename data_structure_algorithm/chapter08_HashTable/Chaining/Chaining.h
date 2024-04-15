/*
해시테이블은 해시함수를 통해 값을 '해시' 해서 주소를 결정한다. 이때 알고리즘이 아무리 정교하게 설계되었다고 해도 모든 입력값에 대해 고유한 해시값을 만드는 것은 불가능하다.
따라서 다른 값임에도 해시값이 같은 경우가 발생하는데 이를 '충돌' 이라고 한다.
이러한 충돌은 해시테이블 바깥에 새로운 공간을 할당하여 문제를 수습하는 '개방해싱'과 처음에 주어진 해시테이블 안에서 문제를 해결하는 '폐쇄해싱' 방법으로 해결할 수 있다.
(충돌 이외에 일부 지역의 주소들을 집중적으로 반환해서 데이터가 모이는 것은 '클러스터링' 이라고 한다.)

'체이닝'은 개방해싱의 방법 중 하나로 체이닝 기반 해시테이블은 '데이터' 가 아닌 '링크드 리스트를 가리키는 포인터'를 관리한다.
이렇게 함으로써 충돌이 발생해도 해당 해시테이블의 링크드리스트에서 다른 데이터들을 한 칸 밀고 Head 앞에 데이터를 삽입하는 방식으로 충돌을 해결한다.
Tail이 아닌 Head에 데이터를 삽입하는 이유는 Tail을 찾기 위해 순차탐색을 하는 것보다 Head 앞에 데이터를 놓고 나머지를 미는 것이 성능면에서 좋기 때문이다.
이렇게 해서 탐색의 성능을 극대화하기 위해 만들어진 해시테이블에서 성능손해가 없도록 한다.
*/

#ifndef CHAINING_H
#define CHAINING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* KeyType;
typedef char* ValueType;

typedef struct tagNode
{
	KeyType Key;
	ValueType Value;
	
	struct tagNode* Next;
} Node;

typedef Node* List;

typedef struct tagHashTable
{
	int TableSize;
	List* Table;
} HashTable;

HashTable* CHT_CreateHashTable(int TableSize);
void CHT_DestroyHashTable(HashTable *HT);

Node* CHT_CreateNode(KeyType Key, ValueType Value);
void CHT_DestroyNode(Node* TheNode);

void CHT_Set(HashTable* HT, KeyType Key, ValueType Value);
ValueType CHT_Get(HashTable* HT, KeyType Key);
int CHT_Hash(KeyType Key, int KeyLength, int TableSize);

#endif