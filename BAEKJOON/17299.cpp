/*
    24.09.23.
    오등큰수
    
    스택
    배열을 0으로 초기화하기
*/
#include <iostream>
#include <stack>

using namespace std;

// int frequency[1000002];
int frequency[1000002] = {0, }; // 배열의 첫번째 요소에 0을 넣고 그다음 요소들에도 0을 넣어서 초기화한다
// int arr[1000] = {0, 1, }; 은 첫번째 0, 두번째 1, * 나머지는 0 * 으로 초기화한다
int arr[1000002];
int answer[1000002];

int main()
{
    int Size;
    cin >> Size;
    stack <int> s;

    // for (int i=1; i<=Size; i++) frequency[i] = 0;
    // = {0, } 을 이용해서 위에서 선언과 동시에 초기화 함

    for (int i=1; i<=Size; i++)
    {
        cin >> arr[i];
        frequency[arr[i]]++; // 해당 숫자가 나오는 빈도를 저장
    }

    for (int i=Size; i>0; i--)
    {
        while(!s.empty() && frequency[s.top()] <= frequency[arr[i]])
        {
            s.pop();
        }

        answer[i] = s.empty() ? -1 : s.top();

        s.push(arr[i]);
    }

    for (int i=1; i<=Size; i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}