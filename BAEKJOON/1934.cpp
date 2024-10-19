/*
    24.10.16.
    최소공배수
*/
#include <iostream>

using namespace std;

// 최대공약수
int Gcd(int a, int b)
{
    int c = a%b;

    while (c != 0) // 0으로 나눠떨어질때까지
    {
        a = b; // 작은 수를
        b = c; // 나머지로 나누기
        c = a%b;
    }

    return b; // 0으로 나눠떨어졌을 떄 나누는 수 반환
}

// 최소공배수
int Lcm(int a, int b)
{
    // 두 수의 곱(a*b) = 최대공약수와 최소공배수의 곱(Gcd * Lcm)
    return (a*b) / Gcd(a, b);
}
int main()
{
    int T;
    cin >> T;

    for (int i=0; i < T; i++)
    {
        int A, B;

        cin >> A >> B;
        cout << Lcm(A, B) << '\n';
    }

    return 0;
}