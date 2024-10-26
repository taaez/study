/*
    24.10.19.
    숨바꼭질 6
    17087

    유클리드호제법을 통해 최대공약수를 구하는 함수의 최적화
    abs 함수를 통해 절댓값 구하기
    abs(a - b) 하면 a, b의 절댓값 abs(a, b)가 아님에 주의
*/
#include <iostream>

using namespace std;

// 삼항연산자 또는 조건문으로 나누어 떨어질 때 까지 재귀로 돌림
// 결국 마지막은 반환값 정수, 조건 만족안하면 자기 자신 반환
// 이 꼴로 하면 재귀하다가 원하는 값 얻어내기 가능
int Gcd(int a, int b)
{
    return (a % b) == 0 ? b : Gcd(b, a%b);
    /*
    if (b == 0)
        return a;
    else
        return Gcd(b, a%b);
    */
}

int main()
{
    //입력의 개수가 많아서 사용
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int NumYounger, SubinPos, YoungerPos;
    int MaxMove;
    cin >> NumYounger >> SubinPos >> YoungerPos;

    MaxMove = abs(SubinPos - YoungerPos); // 절댓값 함수 abs

    // 동생이 2명이상일 때부터 반복문 실행
    for (int i=1; i < NumYounger; i++)
    {
        cin >> YoungerPos; // 동생 위치 그때그떄 입력 받아서 실행, 미리 다 받아놓을 필요가 없다
        MaxMove = Gcd(MaxMove, abs(SubinPos - YoungerPos));
    }
    cout << MaxMove;

    return 0;
}