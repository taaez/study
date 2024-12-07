/*
    24.11.16.
    쉬운 계단 수
    10844
*/
#include <iostream>
#define MOD 1000000000
// 1000000000으로 나눈 나머지를 출력해야 하기에 MOD 정의해놓고 계산할 때 사용

using namespace std;

int main()
{
    // dp[i][j]
    // i는 자릿수(1자리 ~ 100자리), j는 숫자(0 ~ 9)
    long long dp[102][11] = {0, };

    for (int j=1; j <= 9; j++)
        dp[1][j] = 1;

    int N;
    long long Result=0;
    cin >> N;

    for (int i=2; i <= N; i++)
    {
        for (int j=0; j <= 9; j++)
        {
            // 0은 1에서, 9는 8에서 밖에 못 만들어짐.
            // 0이나 9가 나오면 1과 8의 개수를 더해주면 됨
            if (j == 0)
                dp[i][j] = dp[i-1][1];
            else if (j == 9)
                dp[i][j] = dp[i-1][8];
            else
                dp[i][j] = ((dp[i-1][j+1] % MOD) + (dp[i-1][j-1] % MOD)) % MOD;
            // 이외의 경우에 대해서는 1 작은 수의 개수, 1 큰 수의 개수를 더해주면 됨
        }
    }

    // N 자리수의 0~9의 개수가 곧 계단 수의 개수가 된다
    for (int j=0; j < 10; j++)
    {
        Result += (dp[N][j] % MOD);
    }

    cout << Result % MOD;

    return 0;
}