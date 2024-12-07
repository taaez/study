/*
    24.11.21.
    가장 긴 증가하는 부분 수열 4
    14002

    두 가지 중에 최소, 최대를 계속 판단해서 저장해놓는 기법 익숙해지기
    dp[i]에 저장된 값을 이용해서 가장 긴 증가하는 부분수열 출력하는 부분 추가하기
*/
#include <iostream>
#include <algorithm> // max 함수 사용
#include <stack>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int* arr = new int[N]; // 수열 저장
    int* dp = new int[N];  // dp[i]: i까지의 LIS 길이 저장
    int Length = 0;

    // 수열 입력
    for (int i=0; i < N; i++)
    {
        cin >> arr[i];
        dp[i] = 1; // 초기값은 1, 자기 자신만 포함하는 경우
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++) 
        {
            if (arr[i] > arr[j]) 
            {
                dp[i] = max(dp[i], dp[j] + 1); // i번째를 시작으로 하는 가장 긴 수열 저장
            }
        }
    }

    // dp 배열에서 최댓값을 찾자
    for (int i = 0; i < N; i++) 
    {
        if (dp[i] > Length)
            Length = dp[i];
    }

    cout << Length << '\n';

    // 위에까지 11053이랑 동일, dp[i]를 이용해서 가장 긴 증가하는 부분 수열 출력하는 부분
    int* ans = new int[Length]; // Length 크기만큼 ans에 동적할당
    
    int LastIdx = Length;
    for (int i=N-1; i >= 0; i--) 
    {
        if (dp[i] == Length)
        {
            ans[Length-1] = arr[i];
            Length--;
        }
    }
    
    for (int i=0; i < LastIdx; i++)
        cout << ans[i] << ' ';

    // 동적 메모리 해제
    delete[] arr;
    delete[] dp;
    delete[] ans;

    return 0;
}