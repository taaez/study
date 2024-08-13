#include <iostream>

using namespace std;

char operation[200001]; // 숫자 하나당 push, pop 한번씩 즉 +, - 한번씩 해서 T의 2배 크기
int str[100001];
int stack[100001]; // 스택을 int배열로 설정하고 Top을 인덱스로 쓰는 형식으로

int main ()
{
    int T;
    int num=1; // 스택에 넣을 숫자
    int Top=-1; // Top 초기값 -1로 해서 -1이면 empty인 걸로
    int idx=0;

    cin >> T;

    for (int i=0; i<T; i++)
    {
        cin >> str[i];
    }

    for (int i=0; i<str[0]; i++)
    {
        stack[++Top]=num++; // push
        operation[idx++]='+';
    }
    --Top; // pop
    operation[idx++]='-';

    for (int i=0; i<T-1; i++)
    {
        if (str[i+1] < stack[Top])
        {
            cout << "NO" << '\n';
            // ** 시간초과 만들었던 부분
            // endl은 개행문자 출력 + 출력버퍼 지우기 작업이다
            // '\n'은 개행문자 출력 '만' 한다
            // 개행문자가 많이 출력되는 이 문제에서 endl을 사용해 출력버퍼 지우는 작업 때문에 시간초과 발생
            return 0;
        }
        else if (str[i+1] >= num) // 스택이 empty 일 때 여기서 처리
        {
            while (str[i+1]-stack[Top])
            {
                stack[++Top]=num++;
                operation[idx++]='+';
            }
            --Top;
            operation[idx++]='-';
        }
        else if (str[i+1] == stack[Top])
        {
            --Top;
            operation[idx++]='-';
        }
    }
        
    for (int i=0; i < 2*T; i++)
    {
        cout << operation[i] << '\n';
    }

    return 0;
}