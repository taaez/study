/*
    24.10.21.
    -2진수
    2089

    10진수를 2진수로 바꾸는 방법은 10진수를 2로 나누면서 2진수의 2^0 비트부터
    나머지를 채우는 방법이다. 이때 몫이 0이될 때까지 나눈다
    ex) 13을 2진수로 변환하자 2로 나누면 나머지 1, 몫은 6 : 현재 1
        6을 2로 나누면 나머지 0, 몫은 3 : 현재 01
        3을 2로 나누면 나머지 1, 몫은 1 : 현재 101
        1을 2로 나누면 나머지 1, 몫은 0 : 결과적으로 1101
        13을 2진수로 변환하면 1101이다
    
    10진수를 -2진수로 바꾸는 과정도 동일하다 단, -2로 나누기에 나머지가 음수가 될 수 있다
    이를 보정해주는 과정이 필요하다
*/
#include <iostream>

using namespace std;

// 10진수를 -2진수로 변환하는 함수
string Negative_Base_2(int n) 
{
    if (n == 0) return "0";

    string result;
    
    while (n != 0) // 몫이 0이 될 때까지 반복
    {
        int Remainder = n % -2;
        n /= -2;
        
        // 나머지가 -1로 음수인 경우 2를 더해서 1로 보정, 몫도 하나 더해주기
        if (Remainder < 0) 
        {
            Remainder += 2;
            n += 1;
        }

        result = char(Remainder + '0') + result;
    }

    return result;
}

int main() {
    int Decimal;
    cin >> Decimal;

    string NegBase2 = Negative_Base_2(Decimal);
    cout << NegBase2;

    return 0;
}