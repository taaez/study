/*
    24.10.19.
    GCD 합
    9613
*/ 
#include <iostream>

using namespace std;

// 유클리드 호제법을 이용한 최대공약수 구하기
long long Gcd(int a, int b)
{
    int c = a%b;

    while (c != 0) // 0으로 나눠떨어질때까지
    {
        a = b; // 작은 수를
        b = c; // 나머지로 나누기
        c = a%b;
    }

    return b; // 0으로 나눠떨어졌을 떄 나누는 수 반환
}

int main()
{
    int T;
    cin >> T;

    for (int i=0; i < T; i++)
    {
        long long Answer=0; // 숫자의 입력범위 <= 1,000,000인데 범위 넘어갈 수도
        int N;
        cin >> N;
        int* Num = new int[N]; // 필요한 만큼 동적할당

        for (int i=0; i < N; i++)
            cin >> Num[i];
        
        for (int i=0; i < N; i++)
        {
            for (int j=i+1; j < N; j++)
            {
                Answer+=Gcd(Num[i], Num[j]);
            }
        }
        cout << Answer << '\n';

        delete[] Num; // 동적할당 했으면 꼭 해제도
    }

    return 0;
}