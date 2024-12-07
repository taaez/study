/*
    24.12.01.
    가장 긴 감소하는 부분 수열
    11722
*/
#include <iostream>
#include <algorithm> // max 함수 사용

using namespace std;

int main()
{
    int N;
    cin >> N;

    int* arr = new int[N]; // 수열 저장
    int* dp = new int[N];  // dp[i]: i까지의 LDS 길이 저장
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
            if (arr[i] < arr[j]) {
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

    cout << Length;

    // 동적 메모리 해제
    delete[] arr;
    delete[] dp;

    return 0;
}