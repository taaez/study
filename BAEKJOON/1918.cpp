/*
    24.09.29.
    후기표기식

    스택

    ** 피연산자는 중위표기식, 후위표기식 둘 다 순서가 같으므로 바로 출력 **
    ** 어떤 연산을 먼저 해야하는지 판단해야 하기에 연산자만 스택에 넣고 top과 현재 연산자를 비교해가며 pop 하는 타이밍을 조절함 **

    연산자에 우선순위를 부여하여 연산자를 팝할지 말지를 정하는 것이 관건
    괄호도 연산자 스택에 넣어서 작업 중인 구간이 괄호 안인지 밖인지 판단할 수 있도록  
    연산자 스택의 top에 있던 연산자의 우선순위와 현재 연산자의 우선순위를 비교해서 언제 pop해야 하는지 정하기
    *, /는 더 먼저 처리해야되니까 우선순위가 낮은 연산자가 스택에 있다면 먼저처리, 즉 pop안함
    먼저 할 필요가 없는 연산자가 왔을 때 pop을 한다
    피연산자는 어차피 후위표기식으로 바뀌어도 순서는 같음 그래서 그냥 바로 출력
    s.top() 을 사용할 때는 항상 !s.empty() 조건과 같이 사용
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack <char> s;
    string str;

    cin >> str;

    for (int i=0; i < str.length(); i++) // str의 길이를 구해주는 .length() 함수
    {
        if ('A' <= str[i] && str[i] <= 'Z')
        {
            cout << str[i]; // 피연산자는 바로 출력
        }
        else if (str[i] == '+' || str[i] == '-') 
        {
            while (1) // 반복문을 돌리는 이유는 스택에 pop할 조건을 만족하는 연산자가 여러개 있을 수 있기 때문
            {
                // 우선적으로 비어있는 않음을 체크, s.top()을 쓰기에
                // 먼저 할 필요가 없는 연산자들이기에 연산 순서가 바뀌는 것은 괄호가 나왔을 때밖에 없음 괄호 전까지는 다 pop
                if (!s.empty() && s.top() != '(')
                {
                    cout << s.top();
                    s.pop();
                }
                else break;
            }
            s.push(str[i]);
        }
        else if (str[i] == '*' || str[i] == '/')
        {
            while (1)
            {
                // 먼저 연산해야 하는 연산자들, 같은 *, / 는 pop하고 +, -는 일단 대기, *, /가 우선 연산되기 떄문
                // pop 한다 == 연산한다
                if (!s.empty() && (s.top() == '*' || s.top() == '/'))
                {
                    cout << s.top();
                    s.pop();
                }
                else break;
            }
            s.push(str[i]);
        }
        else if (str[i] == '(')
        {
            s.push('('); // 스택에 괄호도 넣음으로써 여기부터 괄호가 시작되어 연산 순위가 바뀌었음을 알 수 있다
        }
        else if (str[i] == ')')
        {
            // 사칙연산의 우선순위는 위의 조건문에서 이미 다 처리
            // 괄호가 끝났을 떄 열린 괄호 전까지 스택에 남아있던 연산자를 다 pop(연산) 함으로써 괄호를 먼저 연산함
            while (!s.empty() && s.top() != '(')
            {
                cout << s.top();
                s.pop();
            }
            s.pop(); // '(' 를 지우기 위한 pop
        }
    }

    // 스택에 남아있는 연산자들 스택이 빌 때까지 pop
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }

    return 0;
}