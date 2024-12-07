/*
    24.11.11.
    1, 2, 3 더하기
    9095
*/
#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;

    int a[13];

    a[1]=1, a[2]=2, a[3]=4;
    for (int i=0; i < T; i++)
    {
        int N;
        cin >> N;

        for (int j=4; j <= N; j++)
        {
            a[j] = a[j-1] + a[j-2] + a[j-3]; 
            // 1, 2, 3 만을 이용해서 합을 표현하는 것이기에
            // 1로 시작할떄, 2로 시작할떄, 3으로 시작할 때로 나눠서 구함
        }
        cout << a[N] << '\n';
    }

    return 0;
}