/*
    24.10.16.
    최대공약수와 최소공배수

    나눠지는 수 중 가장 큰 수
    나눠떨어지게 할 수 있는 가장 큰 
    유클리드 호제법
    (GCD) Greatest Common Divisor
    a, b 두 수의 최대공약수는
    a > b 라고 했을 대
    a를 b로 나눈 수를 c라 할 때 b를 c로 나누고 이 값을 또 d라 할 떄
    c를 d로 나눈다 이런식으로 나머지가 0이 될 때 까지 나눴을 때 
    나머지가 0일떄 나누는 수가 최대공약수이다
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
    int A, B;
    int C;

    cin >> A >> B;
    cout << Gcd(A, B) << '\n' << Lcm(A, B);

    return 0;
}