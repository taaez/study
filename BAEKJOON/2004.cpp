/*
    24.10.18.
    조합 0의 개수
    
    2로 몇번 나눠지는지 5로 몇번 나눠지는지로 파악하면 반복문을 너무 많이 돌린다
    100!을 예로 들면 100을 5로 나누었을 떄 몫과 25로 나누었을 때 몫을 더하면 
    100!에 들어있는 5의 개수이다
    5로 나누어떨어지는 수 : 5, 10, 15, 20, 25, ...
    25로 나누어떨어지는 수도 더해주는 이유는 25, 50, 75, 100은 5로 나누어 
    떨어지는 수에서 카운트 되긴 했지만 5가 2개 들어가기에 하나 더 더해주기 위함이다
*/
#include <iostream>

using namespace std;

long long Count_Twos(long long n)
{
    long long TwoCount=0;

    // n이 long long 이니까 i도 long long 으로 (터지지 않게)
    for (long long i=2; i <= n; i *= 2) // i*=i 로 제곱표현
    {
        TwoCount += n/i;
    }

    return TwoCount;
}

long long Count_Fives(long long n)
{
    long long FiveCount=0;

    for (long long i=5; i <= n; i *= 5)
    {
        FiveCount += n/i;
    }

    return FiveCount;
}

int main()
{
    // 범위가 <= 2,000,000,000이라 long long 으로
    long long N, M;
    cin >> N >> M;

    long long Two, Five;

    Two = Count_Twos(N) - Count_Twos(N-M) - Count_Twos(M); // nCm은 n!/(n-m)!m!이다
    Five = Count_Fives(N) - Count_Fives(N-M) - Count_Fives(M); // 따라서 분모의 2, 5 개수는 뺴주기

    if (Two == 0 || Five == 0) // 2나 5 둘 중 하나가 0개라면 다른 쪽이 몇 개가 있던 10이 안 만들어짐
        cout << '0';
    else
        cout << (Two <= Five ? Two : Five); // 인수 2와 5의 개수 중 작은 쪽 출력
    
    return 0;
}