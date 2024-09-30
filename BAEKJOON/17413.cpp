/*
cin은 공백 이전까지만 입력을 받기 때문에 공백을 포함해서 입력을 받을 수 없다
따라서 문장전체를 받는 것과 같은 공백을 포함해서 입력을 받을 때
string의 getline 함수를 이용해서 문자열 입력을 받는다
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int tag = -1;

    string str;
    getline(cin, str); // cin >> str과 달리 공백을 포함한 전체문장을 str에 입력
    str += ' ';
    stack <char> s;

    for (char c : str) 
    //문자열이나 배열과 같은 컨테이너의 모든 요소를 사용할 떄 사용
    //char c를 통해 문자 변수 c 선언, s는 순회할 문자열이나 배열을 나타낸다
    //s에 있는 문자를 하나씩 꺼내서 c에 할당하면서 반복문 수행, 종료조건은 s에 있는 모든 문자를 순회했을 때
    {
        if (c == '<')
            tag = 1; // 태그 문자는 순서대로 출력하기 위한 태그 시작임일 알림

        if (tag == 1)
        {
            while (!s.empty()) // 태그 전에 있던 뒤집어야 하는 단어가 있다면 출력
            {
                cout << s.top();
                s.pop();
            }
            cout << c;
        }
        else if (c == ' ')
        {
            while (!s.empty())
            {
                cout << s.top();
                s.pop();
            }
            cout << c;
        }
        else
            s.push(c);

        if (c == '>')
            tag = 0; // 태그가 끝났음을 알리는 기준
    }

    return 0;
}