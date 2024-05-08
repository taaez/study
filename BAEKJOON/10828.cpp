#include <iostream>
#include <string>

using namespace std;

class Stack
{
private:
	int Top;
	int Capacity;
	int* Array;
public:
	Stack(int N, int _Top)
		:Capacity(N), Top(_Top) // 생성자를 이용해서 스택을 구현할 정수형 배열 생성
	{
		Array = new int[N];
	}
	~Stack()
	{
		delete []Array; // 메모리 누수방지, 동적할당 해줬으면 해제까지 항상 !!
	}
	void Empty()
	{
		if (Top == -1) 
			cout << '1' << endl; // Top의 위치로 스택이 비어있는지 아닌지 유무 판단		
		else
			cout << '0' << endl;
	}
	int IsFull()
	{
		if (Capacity - 1 <= Top) return 1;
		return 0;
	}
	void Push(int Num)
	{
		if (IsFull())
		{
			cout << "Stack is Full" << endl; // 스택이 꽉 차있을때
			return;
		}
		Array[++Top] = Num; // Top을 1 증가시키고 스택에 값 넣기
	}
	void Pop()
	{
		if (Top == -1) 
			cout << "-1" << endl;
		else
			cout << Array[Top--] << endl; // 스택에 있는 값 출력하고 Top 1 낮추기
	}
	void Size()
	{
		cout << Top + 1 << endl; // 정수의 개수 출력, Top보다 1 많게 정수가 있다
	}
	void TopStack()
	{
		if (Top == -1) 
			cout << "-1" << endl;
		else
			cout << Array[Top] << endl; // 스택의 Top에 있는 값 출력만
	}
};

int main()
{
	int N; // 명령어가 들어올 개수 push가 최대 N번 이므로 스택의 크기는 N으로 설정
	string Command; // 명령어를 받을 문자열
	
	cin >> N;
	Stack stack(N, -1); // 용량이 N이고 Top이 -1인 객체 생성
	
	for (int i=0; i<N; i++)
	{
		cin >> Command;
		if (Command == "push")
		{
			int Num;
			cin >> Num;
			stack.Push(Num);
		}
		else if (Command == "pop")
			stack.Pop();
		else if (Command == "size")
			stack.Size();
		else if (Command == "empty")
			stack.Empty();
		else if (Command == "top")
			stack.TopStack();
		else
			cout << "Illegal command" << endl;
		
	}
		
	return 0;
}