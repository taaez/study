/*
    24.09.30.
    단어 길이 재기
*/
#include <iostream>
#include <string>

using namespace std;

char arr[101];

int main()
{
    int count=0;
    string str;
    cin >> str;

    // cout << str.length(); string 헤더의 length 함수 사용

    for (int i=0; str[i]; i++)
        count++;
    
    cout << count;
    
    return 0;
}