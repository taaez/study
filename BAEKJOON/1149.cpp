/*
    24.11.29.
    RGB거리
    1149
*/
#include <iostream>
#include <algorithm> // min 함수 사용

using namespace std;

int dp[1001][3] = {0, };
int rgb[1001][3];

int main()
{
    int N;
    cin >> N;

    // 각 집의 빨강, 초록, 파랑 색 칠하는 비용 저장
    for (int i=0; i < N; i++)
    {
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    }

    // N개의 집을 칠하는 최솟값, 빨강, 초록, 파랑을 칠할 때 각각
    for (int i=1; i <= N; i++)
    {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + rgb[i-1][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + rgb[i-1][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + rgb[i-1][2];
    }

    cout << min(min(dp[N][0], dp[N][1]), dp[N][2]) << '\n';

    return 0;
}