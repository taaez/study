/*
출발점과 도착점이 어떠한 원 안에 있으면 진입, 이탈 해야하는 원이 생긴다
즉, 출발점은 몇 개의 원 안에 있고 도착점은 몇 개의 원 안에 있는지 구하면 됨
이는 원의 중심과 출발점, 도착점 사이의 거리가 반지름보다 큰지 작은지를 살피면 된다
단, 출발점과 도착점이 모두 하나의 원 안에 있다면 이 경우는 제외
*/

#include <iostream>

using namespace std;

// 어떠한 점이 어떠한 원 안에 들어있는지 판단하는 함수, 원은 중심과 거리가 같은 점들의 집합임을 이용
int IsInCircle(int cx1, int cy1, int cx2, int cy2, int r) 
{
	if ( ((cx1 - cx2)*(cx1 - cx2) + (cy1 - cy2)*(cy1 - cy2)) < r*r ) 
		return 1;
	else
		return 0;
}

int main()
{
	int T;
	cin >> T;
	
	for (int i=0; i<T; i++) // while(T--) 이런 식으로도 반복문 횟수가 주어졌을 때 반복 수행 가능, 참고
	{
		int count=0;
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		int n;
		cin >> n;
		for (int i=0; i<n; i++)
		{
			int cx, cy, r;
			cin >> cx >> cy >> r;
			
			if (IsInCircle(x1, y1, cx, cy, r) && IsInCircle(x2, y2, cx, cy, r)==0)
				count++;
			if (IsInCircle(x1, y1, cx, cy, r)==0 && IsInCircle(x2, y2, cx, cy, r))
				count++;
			// 출발점과 도착점 모두 어떠한 원 안에 있으면 진입, 이탈이 생기지 않는다 따라서 그 경우는 제외
			// 둘 중 하나는 원 안에 다른 하나는 원 밖에 있는 경우만 카운트
		}
		cout << count << endl;
	}
}