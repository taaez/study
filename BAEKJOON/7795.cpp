#include <iostream>

using namespace std;

void Swap(int* A, int* B)
{
	int Temp = *A;
	*A = *B;
	*B = Temp;
}

// 퀵정렬에 필요한 기준요소를 정하고, 수색섬멸을 하는 함수
int Partition(int DataSet[], int Left, int Right)
{
	int First = Left;
	int Pivot = DataSet[First]; // 첫번째 요소를 기준으로
	
	++Left;
	
	while (Left<=Right)
	{
		while (DataSet[Left]<=Pivot && Left<Right)
			++Left;
		
		while (DataSet[Right]>=Pivot && Left<=Right)
			--Right;
		
		if (Left<Right)
			Swap(&DataSet[Left], &DataSet[Right]);
		else
			break;
	}
	
	Swap(&DataSet[First], &DataSet[Right]);
	
	return Right;
}

// 재귀함수를 통한 퀵정렬에 필요한 함수
void QuickSort(int DataSet[], int Left, int Right)
{
	if (Left < Right)
	{
		int Index = Partition(DataSet, Left, Right);
		
		QuickSort(DataSet, Left, Index - 1);
		QuickSort(DataSet, Index + 1, Right);
	}
}

int main()
{
	int T;
	int N, M;
	
	cin >> T; // 케이스가 몇 개인지
	
	while (T>0)
	{
		int count = 0;
		cin >> N >> M;
		
		int * A = new int[N]; // new로 필요한 만큼 동적할당
		for (int i=N; i>0; i--)
		{
			cin >> A[N-i];
		}
		int * B = new int[M];
		for (int i=M; i>0; i--)
		{
			cin >> B[M-i];
		}
		
		/*
		정렬이 안되어 있다면 시간복잡도가 엄청나게 올라간다!! 정렬 전에는 시간복잡도 O(n^2)이고 정렬하면 O(nlogn)이다
		정렬에는 삽입정렬, 버블정렬, 퀵정렬 등등(병합정렬, 힙정렬, 셸정렬, 선택정렬)이 있다
		이 문제에서는 퀵정렬을 사용
		*/
		
		QuickSort(A, 0, N-1);
		QuickSort(B, 0, M-1);
		
		for (int i=0; i<N; i++)
		{
			for (int j=0; j<M; j++) // 이중반복문에서 안에있는 반복문 변수를 돌릴 때마다 살리고 싶을 떄 for문 사용
			{
				if (A[i] > B[j]) 
					count++;
				else 
					break;
			}
		}
		cout << count << endl;
		T--;
		
		delete []A;
		delete []B; // 메모리 누수 방지로 동적할당 해제
	}
	
	return 0;
}