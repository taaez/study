/*
    24.12.01.
    가장 긴 바이토닉 부분 수열
    11054
*/
#include <iostream>
#include <algorithm> // max 함수 사용

using namespace std;

int main()
{
    int N;
    cin >> N;

    int* arr = new int[N]; // 수열 저장
    int* inc = new int[N]; // 증가하는 부분 저장
    int* dec = new int[N]; // 감소하는 부분 저장
    int MaxLength = 0;

    // 수열 입력
    for (int i=0; i < N; i++)
    {
        cin >> arr[i];
        inc[i] = 1; // 초기값은 1, 자기 자신만 포함하는 경우
        dec[i] = 1;
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++) 
        {
            if (arr[i] > arr[j]) 
            {
                inc[i] = max(inc[i], inc[j] + 1); // i번째를 시작으로 하는 가장 긴 수열 저장
            }
        }
    }

    // 뒤에서부터 오름차순인 부분 수열의 길이를 구한다고 생각
    for (int i = N-2; i >= 0; i--) // N-1이 마지막 인덱스, 따라서 그 전인 N-2부터 해야함
    {
        for (int j = N-1; j > i; j--)
        {
            if (arr[i] > arr[j]){
                dec[i] = max(dec[i], dec[j] + 1);
            }
        }
    }

    for (int i = 0; i < N; i++) 
    {
        MaxLength = max(MaxLength, inc[i] + dec[i] - 1); // 10 20 30, 30 20 10 이면 30이 중복, 즉 1을 빼줘야 원하는 길이
    }

    cout << MaxLength;

    // 동적 메모리 해제
    delete[] arr;
    delete[] inc;
    delete[] dec;

    return 0;
}