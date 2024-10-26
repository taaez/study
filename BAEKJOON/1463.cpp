/*
    24.10.26.
    1로 만들기
    1463
*/
#include <iostream>

using namespace std;

int main()
{
    int Num;
    int* arr = new int[1000001]; // 인덱스에 해당하는 수를 만들기 위한 최소 연산을 저장
    cin >> Num;
    arr[1] = 0; // 초기 조건, 1을 1로 만드는데 필요한 연산은 0회

    // 2부터 Num까지 돌면서 그 수를 만드는 최소 연산이 몇인지 계산하고 연산
    for (int i=2; i < Num+1; i++)
    {
        // i를 1로 만드는데 필요한 최소 연산 횟수는 
        // i-1을 1로 만드는 최소 연산 횟수보다 항상 1은 더 많음
        arr[i] = arr[i-1] + 1;

        // arr[i]에 저장된 i-1을 1로 만드는 최소 연산 횟수 + 1과
        // i/3을 1로 만드는 최소연산횟수 + 3으로 나누는 연산 1회를 비교해서
        // 더 작은 값을 저장
        if (i % 3 == 0) 
            arr[i] = (arr[i] > arr[i/3]+1) ? arr[i/3]+1 : arr[i];
        
        // 위와 동일
        if (i % 2 == 0)
            arr[i] = (arr[i] > arr[i/2]+1) ? arr[i/2]+1 : arr[i];
    }
    cout << arr[Num];

    return 0;
}