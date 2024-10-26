/*
    24.10.20.
    8진수 2진수
    1212

    플래그 라는 bool 변수를 통해 조건 만들기
    시간과 공간은 보통 반비례 한다
    메모리를 많이 써서 8진수 조합에 대한 정보를 다 저장해놓으면 빨라짐
*/
#include <iostream>

using namespace std;

int main()
{
    string Octal;
    cin >> Octal;

    // 8진수 입력이 0일 때 그냥 0 출력하고 종료
    if (Octal[0] == '0')
    {
        cout << '0';
        return 0;
    }

    bool flag = true; // 첫 1을 찾기 위한 플래그

    for (int i=0; i < Octal.length(); i++)
    {
        int IntOctal = Octal[i] - '0'; // 연산을 위해 정수로 변환
        for (int j=4; j >= 1; j/=2)
        {
            if (IntOctal / j >= 1)
            {
                cout << '1';
                flag = false;
            }
            else if (!flag) // 1이 나온 후에만 0을 출력해서 맨 앞에 1이 나오는 것을 방지
                cout << '0';
            IntOctal%=j;
        }
    }
    
    return 0;
}