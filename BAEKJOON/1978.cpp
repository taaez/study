/*
    24.10.16.
    소수 찾기
*/
#include <iostream>

using namespace std;

// 42서울에서 짰던 코드
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
		while (i < nb / 2)
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
    int N;
    int Count=0;
    cin >> N;

    for (int i=0; i < N; i++)
    {
        int num;
        cin >> num;

        if (Is_Prime(num))
            Count++;
    }

    cout << Count;

    return 0;
}
