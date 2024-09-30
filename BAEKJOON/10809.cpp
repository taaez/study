/*
    24.09.29.
    알파벳 찾기
*/
#include <iostream>
#include <string>

using namespace std;

int answer[27];

int main()
{
    string str;

    cin >> str;

    for (int i=0; i < 27; i++) answer[i] = -1; // 모든 배열 -1로 초기화

    for (int i=0; i < str.length(); i++)
    {
        if (answer[str[i] - 97] == -1) // 처음 등장한 알파벳일 조건
            answer[str[i] - 97] = i; // 처음위치를 0, 두번째를 1이라고 하라고 문제에서 제시
    }

    for (int i=0; i < 26; i++) // 알파벳의 개수만큼 반복
    {
        cout << answer[i] << ' ';
    }

    return 0;
}