/*
    24.10.18.
    골드바흐의 
    
    에라토스테네스의 체
    소수판별법 중 하나. 특정범위에 대해서 나올 수 있는 소수를 미리 다 구해놓고 판별하는 방법
*/
#include <iostream>

using namespace std;

int IsPrime[1000001] = {0, }; // 0으로 초기화

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

    Find_All_Prime();

    while (1)
    {
        int Num;
        cin >> Num;

        if (Num == 0)
            break;
        
        // 홀수 입력시 예외 처리
        if (Num % 2 == 1)
        {
            cout << "Illegal Input" << '\n';
            continue;
        }

        bool found = false;
        for (int i=3; i <= Num/2; i+=2)
        {
            if (IsPrime[i] == 0 && IsPrime[Num - i] == 0) // 둘 다 소수일 조건
            {
                cout << Num << " = " << i << " + " << Num - i << '\n';
                found = true;
                break;
            }
        }
        
        // 골드바흐의 추측이 틀렸을 경우 처리
        if (!found)
            cout << "Goldbach's conjecture is wrong." << '\n';
    }

    return 0;
}