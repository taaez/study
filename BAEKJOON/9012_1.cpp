#include <iostream>

using namespace std;

int main ()
{
    int T;
    
    cin >> T;

    while (T--)
    {
        string parenthesis;
        int count=0;

        cin >> parenthesis;

        for (char c : parenthesis) 
        // char로 크기 정해놓은 문자열로 하면 뒤에는 널 문자(\n)로 채워지기 때문에
        // 끝나야하는 반복문이 계속 수행될 수 있다. 따라서 string 이용
        {
            if (c != '(' && c != ')')
            {
                cout << "NO";
                break;
            }
            // 괄호가 아닌 문자가 오면 NO 출력
            else if (c == '(')
                count++;
            else if (c == ')')
                count--;
    
            if (count < 0)
            {
                cout << "NO";
                break;
            }
            // 열린 괄호가 오기 전 닫힌 괄호가 먼저 오는 경우 NO 출력
        }
        if (count == 0)
            cout << "YES"; // 괄호가 모두 완전한 괄호일 때
        else if (count > 0)
            cout << "NO"; // 열린괄호가 있지만 닫힌 괄호가 없을 때
        cout << '\n';
    }

	
    return 0;  
}