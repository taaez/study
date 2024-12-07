/*
    24.11.28.
    1, 2, 3 더하기 3
    15988
*/
#include <iostream>
#define MAX 1'000'001
#define MOD 1'000'000'009

using namespace std;

long long dp[MAX];

int main()
{
    int T;
    cin >> T;

    dp[1]=1, dp[2]=2, dp[3]=4;

    for (int i=4; i < MAX; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD;
    }

    while (T--)
    {
        int N;
        cin >> N;

        cout << dp[N] << '\n';
    }

    return 0;
}