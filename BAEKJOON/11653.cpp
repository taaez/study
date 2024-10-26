/*
    24.10.26.
    소인수분해
    11653

    2로 이미 다 나누고 나면 4, 6 등 2의 배수로는 무조건 나누어 떨어짐
    따라서 미리 소수를 구해둘 필요가 없음
*/
#include <iostream>

using namespace std;

int main()
{
    int Num;
    int idx=0;
    cin >> Num;
    
    if (Num == 1)
        return 0;

    for (int i=2; i * i <= Num; i++)
    {
        while (Num % i == 0)
        {
            cout << i << '\n';
            Num /= i;
        }
    }

    // 처음부터 소수가 주어졌을 때
    if (Num > 1)
        cout << Num << '\n';

    return 0;    
}