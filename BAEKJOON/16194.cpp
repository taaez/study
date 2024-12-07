/*
    24.11.12.
    카드 구매하기 2
    16194
*/
#include <iostream>

using namespace std;

int main()
{
    int N;
    int CardPrice[10001] = {0};
    int DP[10001]; // DP[i]는 카드 i개를 구매하는데 드는 최소 비용

    cin >> N;
    
    // 1개 살 때 비교를 위해 DP[0]만 0으로 초기화, 나머지는 최댓값으로 초기화
    DP[0]=0;
    for (int i=1; i < 10001; i++)
        DP[i] = 10001;
    
    // i개 들어있는 카드팩의 가격 입력
    for (int i=1; i <= N; i++)
    {
        cin >> CardPrice[i];
    }

    for (int i = 1; i <= N; i++)
    {
        // 다이내믹 프로그래밍을 사용하여 값이 최소가 되는 경우 찾기
        for (int j = 1; j <= i; j++)
        {
            DP[i] = (DP[i] < DP[i - j] + CardPrice[j]) ? DP[i] : DP[i - j] + CardPrice[j];
        }
    }
    cout << DP[N];

    return 0;
}