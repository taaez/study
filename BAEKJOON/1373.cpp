/*
    24.10.20.
    2진수 8진수
    1373

    2진수를 3개씩 묶어서 각각 2^2, 2^1, 2^0을 더해서 나타내면 8진수다
    ex) 110101 -> 4 * 1 + 2 * 1 + 1 * 0 = 6, 4 * 1 + 2 * 0 + 1 * 1 = 5 
        8진수로 65
    문자를 정수로 변화시키는 방법
    : 문자 - 문자 = 아스키코드 값 차에 의해 정수
*/
#include <iostream> 

using namespace std;

int main()
{
    string Binary;
    cin >> Binary;
    int Octal;

    // 3의 배수의 길이로 2진수 입력이 들어오지 않았을 때 길이 3의 배수로 맞춰주기
    while (Binary.length() % 3 != 0)
    {
        Binary = '0' + Binary; // 이렇게 하면 문자열 앞부분에 문자 추가 가능
    }

    for (int i=0; i < Binary.length(); i+=3)
    {
        // "문자 - 문자 = 정수" 를 이용
        Octal = (Binary[i] - '0')*4 + (Binary[i+1] - '0')*2 + (Binary[i+2] - '0')*1;
        cout << Octal;
    }

    return 0;
}