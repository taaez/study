/*
    24.10.22.
    진법 변환
    2745

    cmath 라이브러리의 제곱 함수 pow
*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string Num;
    int N;
    int BaseN;
    int Answer=0;
    int length;
    
    cin >> Num >> BaseN;
    length = Num.length();

    for (int i=0; i < length; i++)
    {
        if ('0' <= Num[i] && Num[i] <= '9') // 숫자 일 때
            N = Num[i] - '0';
        else if ('A' <= Num[i] && Num[i] <= 'Z') // 알파벳일 때
            N = Num[i] - 'A' + 10;
        Answer += N * pow(BaseN, length - i - 1);
    }
    cout << Answer << '\n'; 
    
    return 0;
}