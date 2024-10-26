/*
    24.10.21.
    진법 변환2
    11005
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int Decimal, BaseNum, Temp; // 입력받을 10진수, 진법을 따를 수
    string Answer;
    cin >> Decimal >> BaseNum;

    while (Decimal != 0)
    {
        Temp = Decimal % BaseNum;
        Decimal /= BaseNum;
        
        if (Temp < 10)
            Answer = char(Temp + '0') + Answer; // 정수로 표현 가능할 때
        else if (10 <= Temp && Temp <= 35)
            Answer = char(Temp - 10 + 'A') + Answer; // 나머지가 10을 넘어서 알파벳 써야할 때
    }
    cout << Answer;
}