#include "SimpleHashTable.h"

int main()
{
	HashTable* HT = SHT_CreateHashTable(193);
	
	SHT_Set(HT, 418, 32114); // 해시테이블 포인터, Key값(이걸 해시해서 데이터 넣을 주소를 만듦), Value값(넣을 데이터) 순이다.
	SHT_Set(HT, 9, 514);
	SHT_Set(HT, 27, 8917);
	SHT_Set(HT, 1031, 286);
	
	printf("Key: %d, Value: %d\n", 418, SHT_Get(HT, 418));
	printf("Key: %d, Value: %d\n", 9, SHT_Get(HT, 9));
	printf("Key: %d, Value: %d\n", 27, SHT_Get(HT, 27));
	printf("Key: %d, Value: %d\n", 1031, SHT_Get(HT, 1031));
	
	SHT_DestroyHashTable(HT);
	
	return 0;
}