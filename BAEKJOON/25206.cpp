#include <iostream>

using namespace std;

int main()
{
	char Subject[51], Letter[3]; // 문자열 끝에 항상 NULL(\0)이 있음을 생각하고 할당할 것!!!
	double TotalGrade = 0.0, TotalScore = 0.0;
	
	for (int i=0; i<20; i++)
	{
		double Score = 0.0, Grade = 0.0;
		cin >> Subject >> Score >> Letter;
		if (Letter[0] == 'P') continue;
		TotalScore += Score;
		if (Letter[0] == 'F') continue; // 0/0 은 정의되지 않지만, 0/(어떤 정수)는 0임을 이용해서 모든 성적이 F일 떄를 해결
		 Grade = 'E' - Letter[0]; // 42 서울떄 했던 한 문자를 받았을 때 원하는 정수값으로 바꾸는 일반화 방법, 아스키코드 값으로 생각해서 적절한 문자에서 빼거나 or 적절한 문자를 빼거나
		if (Letter[1] == '+') Grade += 0.5; // A+, B+ 와 같은 + 일 때 0.5점 추가
		TotalGrade += Grade * Score;
	}
	
		cout << TotalGrade/TotalScore << endl;
	
	return 0;
}