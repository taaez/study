/*
커서 위치를 기준으로 왼쪽 스택, 오른쪽 스택으로 구별하면 쉬워짐
예를 들어 L 명령어가 나오면 왼쪽 스택의 top을 오른쪽 스택으로 push하고, 왼쪽 스택을 pop 하면 커서가 왼쪽으로 이동한 것
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main ()
{
    string str;
    cin >> str;

    stack <char> Left;
    stack <char> Right;

    for (int i=0; str[i]; i++) // \n (널문자) 는 아스키코드로 0이다. 따라서 종료조건으로 사용가능
    {
        Left.push(str[i]);
    }

    int T;
    cin >> T;

    while (T--)
    {
        char command;
        cin >> command;

        if (command == 'L' && !Left.empty()) // 문장의 맨 앞에 커서가 있으면 수행 x
        {
            // Right.push(Left.pop()); 스택의 push, pop은 작업만 수행할 뿐 반환값이 없다 따라서 이 코드는 불가능
            Right.push(Left.top());
            Left.pop();
        }
        else if (command == 'D' && !Right.empty()) // 문장 맨 끝에 커서가 있으면 수행 x
        {
            Left.push(Right.top());
            Right.pop();
        }
        else if (command == 'B'&& !Left.empty()) // 문장 맨 앞에 커서가 있으면 수행 x
        {
            Left.pop();
        }
        else if (command == 'P')
        {
            char letter;
            cin >> letter;
            Left.push(letter);
        }
    }

    while (!Left.empty())
    {
        Right.push(Left.top());
        Left.pop();
    } // 출력하기 전에 왼쪽 스택에 있는 값들 다 오른쪽으로 보내놓고

    while (!Right.empty())
    {
        cout << Right.top();
        Right.pop();
    } // 오른쪽 스택의 top을 하나씩 출력하면 결과가 출력됨
    cout << '\n';


    return 0;
}