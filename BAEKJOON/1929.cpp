/*
    24.10.17.
    소수 구하기
*/
#include <iostream>

using namespace std;

int	Is_Prime(int nb)
{
	int	i=3;

	if (nb <= 1)
		return (0);
	else if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	else
	{	
		// i < sqrt(nb)가 조건임. 제곱근을 이용한 소수 판별
		// 양변을 제곱하면 i * i < nb인데 이러면 i * i 에서 오버플로우 날 수도
		// i 하나를 넘겨서 i < nb / i로
		while (i <= nb / i)
		{
			if (nb % i == 0)
				return (0);
			i += 2;
		}
	}
	return (1);
}

int main()
{
    int Start, End;
    cin >> Start >> End;

    while (Start <= End)
    {
        if (Is_Prime(Start)) 
            cout << Start << '\n';
        Start++;
    }

    return 0;
}