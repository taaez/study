/*
    24.10.18.
    팩토리얼
*/
#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    if (N == 0)
    {
        cout << '1';
        return 0;
    }
    else
    {
        for (int i=N; i > 1; i--)
        {
            N*=i-1; // N 범위가 <= 12라 int로 해도 가능
        }
    }
    cout << N;

    return 0;
}