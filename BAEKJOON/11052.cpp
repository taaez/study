/*
    24.11.11.
    카드 구매하기
    11052
*/
#include <iostream>

using namespace std;

int main()
{
    int N;
    int CardPrice[10001] = {0};
    int DP[10001] = {0}; // DP[i]는 카드 i개를 구매하는데 드는 최대 비용

    cin >> N;
    
    for (int i = 1; i <= N; i++)
    {
        cin >> CardPrice[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            DP[i] = (DP[i] > DP[i - j] + CardPrice[j]) ? DP[i] : DP[i - j] + CardPrice[j];
        }
    }

    cout << DP[N];

    return 0;
}