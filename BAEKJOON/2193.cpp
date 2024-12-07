/*
    24.11.17.
    이친수
    2193
    
    0으로 시작하면 안되고 1이 연속으로 나오면 안됨
    N이 3이상으로 가면 10으로만 시작하고 규칙을 계속 찾다보면 피보나치 수열을 따름
*/
#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    // 피보나치 수열은 숫자가 커지기에 자료형에 주의해야 한다.
    long long dp[91];
    dp[1] = 1, dp[2] = 1;

    for (int i=3; i <= N; i++)
    {
        // 피보나치 수열 점화식
        dp[i] = dp[i-2] + dp[i-1];
    }

    cout << dp[N];

    return 0;
}