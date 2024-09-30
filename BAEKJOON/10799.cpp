#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int Stick = 0;
    int Laser = 0;
    int TotalNum = 0;
    string str;
    stack <char> s;

    cin >> str;
    // 이전 괄호와 지금 괄호를 비교해서 막대기가 추가되는지 레이저가 추가되는지 막대기가 줄어드는지 파악
    // 막대기가 추가될 때마다 총 개수 1 증가, 레이저가 추가될 때 마다 현재 막대기의 개수만큼 총 개수 증가
    // 레이저가 없는 막대기는 막대기가 추가될 때 카운트, 막대기가 없는 레이저는 현재 막대기가 없기에 총 개수 증가 x
    for (char c : str)
    {   
        if (s.empty())
        {
            s.push(c);
            continue;
        }
        else if (c == '(')
        {
            if (s.top() == '(')
            {
                Stick++;
                TotalNum++; // 총 개수 1 증가
            }
            /*
            else if (s.top() == ')')
            {
                // 이떄 아무것도 안해도 됨 레이저가 추가될지 막대기가 추가될지 다음 괄호를 봐야 알 수 있음
            }
            */
            s.push(c);
        }
        else if (c == ')')
        {
            if (s.top() == '(')
            {
                Laser++;
                TotalNum += Stick; // 총 개수 막대기 수만큼 증가
            }
            else if (s.top() == ')')
            {
                Stick--;
            }
            s.push(c);
        }
    }
    cout << TotalNum << '\n';

    return 0;    
}