#include <iostream>
using namespace std;

int main()
{
	int cash;
	
	while (1)
	{
		cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
		cin >> cash;
		if (cash == -1)
		{
			cout << "프로그램을 종료합니다." << endl;
			break;
		}
		else
		{
			cout << "이번 달 급여: "<<50 + cash * 0.12<<"만원" << endl;
			//cash = 0;
		}
	}
	return 0;
}