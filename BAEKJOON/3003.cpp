#include <iostream>

using namespace std;

int main()
{
	int chess[6]; // 정수형 배열이므로 null 없어도 됨
	
	cin >> chess[0] >> chess[1] >> chess[2] >> chess[3] >> chess[4] >> chess[5];
	cout << 1 - chess[0] <<' '<< 1-chess[1] <<' '<< 2-chess[2] <<' '<< 2-chess[3] <<' '<< 2-chess[4] <<' '<< 8-chess[5] << endl;
	
	return 0;
}