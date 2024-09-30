/*
    24.09.29
    알파벳 개수

    문자를 정수로 바꾸는 법
*/
#include <iostream>

using namespace std;

int answer[27] = {0, }; // 알파벳은 26개, 모든 배열 0으로 초기화

int main()
{
    string str;

    cin >> str;

    for (int i=0; i < str.length(); i++)
    {
        answer[str[i] - 97]++; // a의 아스키코드는 97이다, 문자에 연산을 해서 정수로 바꾸기
    }

    for (int i=0; i < 26; i++) // 알파벳의 개수만큼 반복
    {
        cout << answer[i] << ' ';
    }
    
    return 0;
}