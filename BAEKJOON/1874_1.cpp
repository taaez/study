#include <iostream>
#include <string>
#include <stack>

using namespace std;

char operation[200001]; // 숫자 하나당 push, pop 한번씩 즉 +, - 한번씩 해서 T의 2배 크기
int str[100001];

int main ()
{
    int T; 
    int num=1; // 스택에 넣을 숫자
    int idx=0;

    cin >> T;

    stack <int> s;
    for (int i=0; i<T; i++)
    {
        cin >> str[i];
    }
    // 만들어야 하는 수열 입력받기

    for (int i=0; i<str[0]; i++)
    {
        s.push(num++);
        operation[idx++]='+';
    }
    s.pop();
    operation[idx++]='-';
    // 수열의 첫 항은 무조건 그 숫자까지 스택으로 push하고 pop 해야함
 
    for (int i=0; i<T-1; i++)
    {
        if (!s.empty() && str[i+1] == s.top()) 
        // s.top() 함수 오류 방지를 위한 !s.empty() 조건, 원하는 수열이 스택의 Top인 경우
        {
            s.pop();
            operation[idx++]='-';
        }
        else if (str[i+1] >= num) // s.top()과 비교시 empty일 때 문제 생김, num이랑 비교해서 오류 x
        {
            while (str[i+1]-num+1)
            {
                s.push(num++);
                operation[idx++]='+';
            }
            s.pop();
            operation[idx++]='-';
        }
        else // 원하는 수열이 스택의 Top보다 작은 경우, 무조건 Top에서 부터 pop해야해서 불가능
        {
            cout << "NO" << '\n';
            // ** 시간초과 만들었던 부분
            // endl은 개행문자 출력 + 출력버퍼 지우기 작업이다
            // '\n'은 개행문자 출력 '만' 한다
            // 개행문자가 많이 출력되는 이 문제에서 endl을 사용해 출력버퍼 지우는 작업 때문에 시간초과 발생
            return 0;
            // NO 출력하고 동작종료 
        }        
    }

    for (int i=0; i < 2*T; i++)
    {
        cout << operation[i] << '\n'; 
        // ** 시간초과 만들었던 부분
        // endl은 개행문자 출력 + 출력버퍼 지우기 작업이다
        // '\n'은 개행문자 출력 '만' 한다
        // 개행문자가 많이 출력되는 이 문제에서 endl을 사용해 출력버퍼 지우는 작업 때문에 시간초과 발생
    }    
    // 만들어질 수 있는 수열일 때 push, pop에 따른 부호 저장해놨던 문자열 출력

    return 0;
}