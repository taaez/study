/*
    24.10.16.
    나머지
*/
#include <iostream>

using namespace std;

int main()
{
    int A, B, C;

    cin >> A >> B >> C;

    cout << (A+B) % C << '\n';
    cout << ((A%C) + (B%C)) % C << '\n';
    cout << (A*B) % C << '\n';
    cout << ((A%C) * (B%C)) % C << '\n';
    // 두 수의 합, 곱의 나머지는 두 수 각각 나머지를 더한 것의 나머지와 같다

    return 0;
}