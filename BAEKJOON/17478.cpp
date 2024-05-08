#include <iostream>

using namespace std;

void Line(int n)
{
	for (int i=1; n - i>0; i++)
		cout << "____";
}

void Recursion(int count, int cycle)
{	
	Line(cycle); cout << "\"재귀함수가 뭔가요?\"" << endl;
	
	if (count > 0)
	{
		Line(cycle); cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어." << endl;
		Line(cycle); cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << endl;
		Line(cycle); cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << endl;
	}
 	else
	{
		Line(cycle); cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << endl;
		Line(cycle); cout << "라고 답변하였지." << endl;
		return;
	}
	
	Recursion(count - 1, cycle + 1);
	
	Line(cycle); cout << "라고 답변하였지." << endl;
}

int main()
{
	int number;
	
	cin >> number;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << endl;
	Recursion(number, 1);
	
	return 0;
}