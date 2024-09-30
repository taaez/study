/*
    24.09.23.
    후위표기식2
    
    배열로 표현한 스택
    원하는 소수점 자리수까지 출력
*/
#include <iostream>

using namespace std;

double series[27]; // A, B, C, ... 각각이 뭔지 저장할 수열
double stackarr[27]; // stack으로 넣다뻈다 하며 후위표기식 계산
// float보단 double을 사용해라 백준에서는 

int main()
{
    int Top = -1;
    int N;
    string str;

    cin >> N;
    cin >> str;

    for (int i=0; i<N; i++) cin >> series[i]; // A, B, C, ... 각각이 어떤 값인지 저장

    for (char c : str) // str가 끝날 때까지 앞에서부터 문자 하나씩 c로 보며 반복
    {
        if ('A' <= c && c <= 'Z')
        {
            stackarr[++Top] = series[c - 'A']; // c - 'A'를 통해 각 알파벳에 맞는 수가 입력되게
        }
        else if (c == '+')
        {
            /*
            num = stackarr[Top--];
            stackarr[Top] += num;
            */
            // 배열로 스택을 표현했으므로 Top에서 가감하며 인덱스처럼 조정하면 됨, 다른 메모리 쓸 필요 x
            stackarr[Top-1] += stackarr[Top];
            Top--;
        }
        else if (c == '-')
        {
            stackarr[Top-1] -= stackarr[Top];
            Top--;
        }
        else if (c == '*')
        {
            stackarr[Top-1] *= stackarr[Top];
            Top--;
        }
        else if (c == '/')
        {
            stackarr[Top-1] /= stackarr[Top];
            Top--;
        }
    }

    cout << fixed; 
    cout.precision(2);
    // 소수점을 원하는 자리까지 출력할 수 있게 해줌 cout.precision(N) 에서 N자리 수까지 출력 
    cout << stackarr[Top] << '\n';

    return 0;
}