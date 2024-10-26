/*
    24.10.21.
    골드바흐 파티션
    17103
*/
#include <iostream>

using namespace std;

int IsPrime[1000001] = {0, }; // 0으로 초기화, 소수인 것을 0으로

// 에라토스테네스의 체
// 소수이면 0, 소수가 아니면 1을 갖도록, 그냥 모든 범위에 대해서 각각이 소수인지 아닌지 구함
void Find_All_Prime()
{
    for (int i=2; i * i <= 1000000; i++)
    {   
        if (IsPrime[i] == 0)  
        {
            // i의 모든 배수에 대해 반복문 실행, 다 소수가 아니므로 1 대입
            // j = i * i로 해도 앞에서 지웠어서 ㄱㅊ
            for (int j = i * i; j <= 1000000; j+=i)
            {
                IsPrime[j] = 1;
            }
        }
    }
}

int main()
{
    // c++의 입출력 성능을 최적화 하는 코드
    ios_base::sync_with_stdio(false); 
    // c++의 표준 입출력(cin, cout)과 c의 표준 입출력(scanf, printf) 사이의 동기화를 끊는다
    cin.tie(NULL);
    // cin과 cout의 연결을 끊는다 
    cout.tie(NULL);
    // 다른 출력 스트림과 cout 사이의 연결을 끊음 (cin.tie(NULL)과 대칭성을 위해 사용)

    int T;
    cin >> T;

    Find_All_Prime(); // 범위내 소수 다 구하기

    for (int i=0; i < T; i++)
    {
        int Num;
        int Count=0;
        cin >> Num;

        if (IsPrime[Num - 2] == 0) Count++; // 2와 Num - 2가 파티션을 이룰 경우

        for (int i=3; i <= Num/2; i+=2)
        {
            if (IsPrime[i] == 0 && IsPrime[Num - i] == 0) // 둘 다 소수일 조건
                Count++;
        }
        cout << Count << '\n';
    }

    return 0;
}