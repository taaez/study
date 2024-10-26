/*
    24.10.22.
    Base Conversion
    11576

    A진법 수를 B진법 수로 바꾸기
    10진법을 거쳤다가 바꿔야함
*/
#include <iostream>

using namespace std;

int main()
{
    int BaseA, BaseB; // A진법, B진법을 따를 수
    int BaseTen=0; // 중간에 거쳐갈 10진수
    int j=1;
    int idx=0;
    int N;
    int NumBaseA[25], NumBaseB[25];

    cin >> BaseA >> BaseB;
    cin >> N;
    for (int i=0; i < N; i++) cin >> NumBaseA[i];

    // A진법 수를 10진수로 변환
    for (int i=N-1; i >= 0; i--)
    {
        BaseTen += NumBaseA[i] * j;
        j *= BaseA;
    }
    
    // 10진법 수를 B진법으로 바꿔서 저장
    while (BaseTen != 0)
    {
        NumBaseB[idx++] = BaseTen % BaseB;
        BaseTen /= BaseB;
    }

    for (int i=idx-1; i >= 0; i--)
    {
        cout << NumBaseB[i] << ' ';
    }

    return 0;
}