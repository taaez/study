/*
    24.11.26.
    합분해
    2225
*/
#include <iostream>
#define mod 1000'000'000

using namespace std;

int dp[201][201] = {0, };

int main()
{
    int N, K;
    cin >> N >> K;
    
    //dp[0][0] == 0

    // 1개의 숫자로 N이라는 숫자를 만드는 경우의 수 1가지
    for (int i=1; i <= N; i++)
        dp[i][1] = 1;
    
    // 1이라는 숫자를 j개의 숫자로 만드는 경우의 수 j가지 (0 or 1 사용)
    for (int j=1; j <= K; j++)
        dp[1][j] = j;    
    
    for (int i=2; i <= N; i++)
    {
        for (int j=2; j <= K; j++)
        {
           dp[i][j] = (dp[i][j-1]+ dp[i-1][j]) % mod;
        }
    }
    cout << dp[N][K];

    return 0;
}