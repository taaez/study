#include <iostream>
#include <stack>

using namespace std;

int arr[1000001];
int answer[1000001];
int main()
{
    int Size;
    cin >> Size;
    stack <int> s;

    for (int i=0; i<Size; i++)
    {
        cin >> arr[i];
    }
    
    for (int i = Size-1; i>=0; i--) //뒤에서 부터 반복문
    {
        while (!s.empty() && s.top() <= arr[i])
        {
            s.pop();
            // 뒤에서부터 반복문 돌기에 top이 곧 오른쪽에서 가장 가까운 수이다
            // 이 수와 비교하여 현재수가 더 크거나 같다면 top을 삭제
        }

        answer[i] = s.empty() ? -1 : s.top();
        // 처음 반복문 돌 때, 오른쪽에 자신보다 큰 수가 없을 때 s.empty()가 1이 되어 -1 들어감
        // 위의 while문으로 오른쪽 가장 가까운 큰 수를 찾고 그걸 답안배열에 대입

        s.push(arr[i]);
        // 현재 수를 top으로 만들고 다음 수와 비교
    }

    for (int i=0; i<Size; i++)
    {
        cout << answer[i] << ' ';
    }

    // 2중 반복문은 시간복잡도 O^2으로 시간초과 남
    /*
    for (int i=0; i<Size; i++)
    {
        for (int j=1; arr[i+j] != -1; j++)
        {
            if (arr[i] < arr[i+j])
            {
                cout << arr[i+j];
                break;
            }
            else if (arr[i+j+1] == -1)a
            {
                cout << "-1";
            }
        }
        if (arr[i+1] != -1)
            cout << ' ';
        else if (arr[i+1] == -1)
            cout << "-1";
    }
    */
}