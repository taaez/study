/*
    24.10.18.
    팩토리얼 0의 개수
    
    주어진 수의 팩토리얼을 계산한 수가 있을 때
    뒤에서부터 0이 몇 개 있는지를 구하자
    ex) 5! = 120 이므로 0은 1개 있다
    0의 개수는 팩토리얼 계산에서 10이 몇 개 곱해졌는지로 정해진다
    10은 2와 5를 약수로 가지므로 
    2와 5의 개수를 구해서 10이 몇 개 곱해졌는지 파악
*/
#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int two=0, five=0; // 인수 2와 5가 몇 개 있는지

    for (int i=N; i >= 2; i--)
    {
        int j=i;
        while (j % 2 == 0) // 2로 나눠떨어진다는 것은 2를 인수로 가진다는 말
        {
            j/=2;
            two++;
        }
        int k=i;
        while (k % 5 == 0) // 위와 동일
        {
            k/=5;
            five++;
        }
    }

    if (two == 0 || five == 0) // 2나 5 둘 중 하나가 0개라면 다른 쪽이 몇 개가 있던 10이 안 만들어짐
        cout << '0';
    else
        cout << (two <= five ? two : five); // 인수 2와 5의 개수 중 작은 쪽 출력
    
    return 0;
}