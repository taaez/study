/*
    24.10.01.
    ROT13

   아스키코드 값을 활용한 문자연산
*/
#include <iostream>

using namespace std;

int main()
{
    string str;

    getline(cin, str); // 공백이 포함된 문자열을 받을 때는 getline 으로

    for (int i=0; i < str.length(); i++)
    {
        if ('a' <= str[i] && str[i] <= 'z')
            str[i] = ((str[i] - 97 + 13) % 26) + 97; 
            // a의 아스키코드 97
            // 13개 밀었을 때 다시 a부터 시작하는 경우엔 나머지 연산을 통해 알맞은 알파벳의 아스키코드값이 되도록
        else if ('A' <= str[i] && str[i] <= 'Z')
            str[i] = ((str[i] - 65 + 13) % 26) + 65;
            // A의 아스키코드 65
    }

    cout << str;
}