/*
    24.12.07.
    오르막수
    11057
*/
#include <iostream>
#define MOD 10007

using namespace std;

int dp[1001][10]; // [자릿수][마지막 숫자] 인 수의 개수를 저장

int main()
{
    int N;
    cin >> N;

    for (int i=0; i < 10; i++)
        dp[1][i] = 1;

    for (int i=2; i <= N; i++) // 자릿수를 하나씩 늘려가며 dp 배열 구해놓기
    {
        for (int j=0; j <= 9; j++) // 마지막 숫자가 0~9 일때
        {
            for (int k=0; k <= j; k++) // 마지막 숫자가 j인 N자리 수 이면 0~j가 마지막 숫자인 N-1 자릿수인 수의 개수를 더하기
            {
                dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
            }
        }
    }
    
    long long Sum = 0;

    for (int i=0; i <= 9; i++)
    {
        Sum = (Sum + dp[N][i]) % MOD;
    }

    cout << Sum;

    return 0;
}