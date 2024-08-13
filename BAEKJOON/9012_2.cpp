#include <iostream>
#include <string>
#include <stack>
/*
stack 함수 사용법
s,pop() top에 있는 원소 제거
s.push() top에 원소 삽입
s.top() top에 있는 원소 탐색
s.size() top에 들어가있는 원소의 개수, 크기
s.empty() 스택이 비어있는지 확인, 비어있으면 1 아니면 0
*/

using namespace std;


int main ()
{
    int T;
    
    cin >> T;

    while (T--)
    {
        string parenthesis;
        bool check=true;

        cin >> parenthesis;
        stack <char> s;

        for (char c : parenthesis)
        {
            if (c == '(')
                s.push(c);
            else if (s.empty())
            {
                check=false;
                break;
            }
            else if (c == ')')
                s.pop();
        }
        if (s.empty() && check == true)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    return 0;  
}