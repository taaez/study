/*
    24.10.16.
   접미사 배열

    <substr 함수>
    string str;
    str.substr(pos, len)으로 사용 
    첫번째 변수(pos)는 시작주소, 두번째 변수(len)는 출력할 길이다
    pos의 기본값은 0이고 len의 기본값은 npos이다. len의 길이가 출력할 문자열을 넘어가면 자동으로 짤라줌
    
    <alogrithm 라이브러리의 sort 함수>
    c++에서 제공하는 표준 리이브러리에 있는 함수, 퀵정렬, 힙정렬, 삽입정렬을
    상황에 맞게 섞어쓰는 것으로 알려져 있다.
    intro sort를 사용하는데(정렬 여러가지 섞는거)
    평균 시간복잡도(O(NlogN)가 가장 빠른 퀵정렬을 주력으로 사용하고 최악의 시간복잡도(O(N^2))을 되게 되는
    재귀의 깊이 logN을 초과하면 힙정렬로 바꾸어서 진행한다.
    정렬해야할 배열의 크기가 작은 경우에는 삽입정렬을 사용한다.

    sort(시작주소, 끝나는주소, 정렬기준)로 사용
    세가지 변수를 사용. 정렬기준의 기본값은 오름차순이고 생략가능
    다른 기준으로 정렬하고 싶으면 보통 return 값이 비교 연산자를 포함한 수식이 있는 함수를 이용

    sort함수는 같은 요소가 있을 때에도 정렬전과 순서를 똑같이 유지하는 안정정렬은 아니다
    안정정렬을 사용하려면 stable_sort를 사용하면 된다.
*/
#include <iostream>
#include <string>
//#include <algorithm> sort 함수가 내장되어 있는 라이브러리

using namespace std;

void Swap(string *A, string *B)
{
    string temp = *A;
    *A = *B;
    *B = temp;
}

int Partition(string DataSet[], int Left, int Right)
{
    int First = Left; // 비교할 기준은 분할된 부분의 첫번쨰 요소로
    string Pivot = DataSet[First];

    ++Left;

    while (Left <= Right)
    {
        // while문을 통해 먼저 Left의 위치를 정해놓고
        while (DataSet[Left] <= Pivot && Left < Right)
            ++Left;

        // 다른 while문으로 Right 위치 정함
        while (DataSet[Right] >= Pivot && Left <= Right)
            --Right;
        
        if (Left < Right)
            Swap(&DataSet[Right], &DataSet[Left]);
        else
            break; // break 조건이 Left >= Right임, 해당 분할부분의 정렬이 끝났음을 의미
    }

    Swap(&DataSet[First], &DataSet[Right]);
    return Right;
}

void QuickSort(string DataSet[], int Left, int Right)
{
    if (Left < Right)
    {
        int Index = Partition(DataSet, Left, Right); // 다음 분할의 기준을 정하면서 partition 함수를 호출해서 현재 기준에 대해 정렬

        QuickSort(DataSet, Left, Index - 1); // 분할된 것의 왼쪽
        QuickSort(DataSet, Index + 1, Right); // 분할된 것의 오른쪽
    }
}

int main()
{
    string Str;
    int Len;
    
    cin >> Str;
    Len = Str.length();
    string* Arr = new string[Len];

    for (int i=0; i < Len; i++)
    {
        Arr[i] = Str.substr(i, Len); // 문자열의 일부를 저장해서 모든 접미사 저장
    }
   
    // 퀵정렬을 이용한 정렬
    // 분할정복 - 부분부분 나눠서 정렬
    // 수색섬멸 - 2인이 양쪽에서 조건을 만족하는 값 찾고 서로 바꾸기
    QuickSort(Arr, 0, Len - 1);
    // sort(Arr, Arr + Len); 표준 라이브러리 sort 함수를 이용한 정렬

    for (int i=0; i < Len; i++)
    {
        cout << Arr[i] << '\n';
    }

    return 0;
}