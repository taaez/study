/*
    24.12.07.
    스티커
    9465

    table[행][열] 이라고 할 때
    table[1][1]을 뗄 경우 선택지는 
    1. table[2][2] 떼기
    2. table[1][3] 떼기
    3. table[2][3] 떼기
    4. table[1][4] or table[2][4] 뗴기 이다

    이때 2번을 선택하면 table[2][2]를 떼는 것이 더 큰 값이 나올 것이고
    4번을 선택하면 2열이나 3열에서 하나를 떼는 것이 더 큰 값이 나올 것이다.
    따라서 고려해야 하는 것은 table[2][2]를 떼는 것과 table[2][3]을 뗴는 것 두 개 이다.

    이 문제는 N이 주어지고 1열부터 모든 경우의 수를 구하는 것보다 (바텀업)
    어떤 스티커를 뗐다고 했을 때 그 이전에 어떤 스티커를 뗐어야 최댓값인지 
    N열 스티커를 똈을때, N-1열과 N-2열 중 어떤 스티커를 똈어야 최댓값인지 (탑다운)
    구하는 방법이 더 효율적이다.
*/
#include <iostream>
#include <algorithm> // max함수 사용

using namespace std;

int table[2][100001] = {0, };
// int dp[2][100001] = {0, };

int main()
{
    int T;
    cin >> T;

    for (int i=0; i < T; i++)
    {
        int N;
        cin >> N;

        // 스티커가 붙여진 테이블 세팅
        for (int i=0; i < 2; i++) // [0][n]은 1행 [1][n]은 2행
        {
            for (int j=0; j < N; j++)
            {
                cin >> table[i][j]; // [행][열], cin은 빈칸, 개행을 기준으로 나눈다
            }
        }

        // 열이 1개일 때
        if (N == 1)
        {
            cout << max(table[0][0], table[1][0]) << '\n';
            continue;
        }

        // 열이 2개일 때
        table[0][1] += table[1][0];
        table[1][1] += table[0][0];
        // 이전 대각선에 있는 스티커의 값 더하기

        // 열이 3개일 때 ~
        for (int i=2; i < N; i++) // N열은, [0][N-1]과 [1][N-1] 이다
        {
            table[0][i] += max(table[1][i-1], table[1][i-2]);
            table[1][i] += max(table[0][i-1], table[0][i-2]);
        }
        cout << max(table[0][N-1], table[1][N-1]) << '\n';
    }

    return 0;
}