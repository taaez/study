/*
    24.11.21.
    연속합
    1912

    첫째줄에 n, 둘째줄에 n개의 정수(양수, 음수 다)로 이뤄진 수열이 주어짐
    임의로 연속된 몇 개의 수를 골라서 합을 구했을 때 나올 수 있는 최댓값을 구해라
    1 <= n <= 100,000 
    -1000 < 주어지는 수 < 1000
*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
int dp[100001];

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    dp[0] = arr[0]; // 첫 번째 값 초기화
    int Max = dp[0];

    for (int i = 1; i < N; i++) 
    {
        dp[i] = max(arr[i], dp[i - 1] + arr[i]); // 점화식
        // 현재값, 이전까지의 최댓값 + 현재값을 비교해서 더 큰 것을 택함
        // 이렇게 함으로써 연속해서 더했을 때 값을 작게 만드는 것을 제외하면서 연속합을 구할 수 있음
        // 만약 이전까지의 최댓값 + 현재값이 그냥 현재값 하나보다 작다면 연속을 끊고 거기부터 다시 더하기 시작
        // dp[i-1] + arr[i]의 값이 음수가 되는 순간 더할 가치가 없으므로 현재것을 택하게 됨
        Max = max(Max, dp[i]); // 최댓값 갱신
    }

    cout << Max;

    return 0;
}

/*
    시간초과 코드, for문 2개라 시간초과

    for (int i=0; i < N-1; i++) 
    {
        for (int j=i+1; j < N; j++) 
        {
            arr[i] += arr[j];
            dp[i] = max(dp[i], arr[i]);
        }
    }

    int Max = dp[0];
    for (int i=1; i < N; i++)
    {
        if (dp[i] > Max)
            Max = dp[i];
    }
*/