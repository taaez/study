/*
    24.11.29.
    동물원
    1309

    사자를 안 넣었을 때를 An, 사자를 한 곳에 넣었을 때를 Bn이라고 한다면
    An = A(n-1) + 2Bn 이다, (사자를 한 곳에 넣는 것은 왼쪽, 오른쪽 두 가지)
    Bn을 구하면 An을 구할 수 있고, A1, A2와 같은 초항을 구해놓고 바텀업을 진행하면
    원하는 N에 대한 경우의 수를 구할 수 있다.
    Bn = A(n-2) + B(n-1) 이다 (사자를 한 곳에 넣으면 다음 줄은 하나로 정해짐)
    A(n-1) = A(n-2) + 2B(n-1)을 빼면 Bn 항의 차를 구할 수 있고 이를 사용해서 An만을
    이용한 점화식으로 표현가능하다
    An = 2A(n-1) + A(n-2) 이고 *초항 두 개만 알면 모든 항을 구할 수 있다.*
*/
#include <iostream>
#define MOD 9901

using namespace std;

int dp[100'001];

int main()
{
    int N;
    cin >> N;

    dp[1]=3, dp[2]=7;
    for (int i=3; i <= N; i++)
    {
        dp[i] = ((2 * dp[i-1]) + dp[i-2]) % MOD;
    }
    cout << dp[N] % MOD;

    return 0;
}