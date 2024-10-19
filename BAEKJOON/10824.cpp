/*
    24.10.04
    네 수

    cmath 헤더 사용
    상용로그를 사용하면 특정 수의 자릿수를 구할 수 있다
    pow 함수를 이용해서 제곱을 표현할 수 있다
*/ 
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long A, B, C, D; // 입력의 범위가 < 1,000,000이고 두 수를 더하기에 int로 부족
    long NumDigit1, NumDigit2;

    cin >> A >> B >> C >> D;

    NumDigit1 = log10(B);
    NumDigit2 = log10(D);
    // log(X) 는 밑이 자연상수 e인 로그, log10(X)는 밑이 10인 로그
    // 밑이 2, 3과 같은 로그는 log(X) / log(2), log(X) / log(3) 와 같이 로그법칙을 이용해서 나타낸다

    B += A * pow(10, NumDigit1+1);
    D += C * pow(10, NumDigit2+1);

    cout << B + D;

    return 0;
}