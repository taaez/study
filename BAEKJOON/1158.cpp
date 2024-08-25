#include <iostream>

using namespace std;

int main ()
{
    int N;
    int K;
    int idx;
    int count;
    int str[5001]; // 결과 출력을 위해 요세푸스 수열 저장해놓을 숫자배열

    cin >> N >> K;
    idx = K-1;
    int arr[N];

    for (int i=0; i<N; i++)
    {
        arr[i]=i+1;
    }

    str[0]=arr[idx];
    arr[idx]=-1; // 수열에 들어간 숫자는 -1로 바꾸어 더이상 포함안되게

    for (int i=0; i<N-1; i++)
   {
        count=0;
        while (1)
        {
            if (idx == N-1) // 크기 넘어가면 앞에서부터 조사
                idx=0;
            else
                idx++;

            if (arr[idx]!=-1)
                count++; // 이미 사용한 수 제외하고 카운트해서
            if (count == K) // 다음 K번째 사람 찾아서 idx 구하면 break
                break;
        }
        str[i+1]=arr[idx];
        arr[idx]=-1;
    }

    // 결과출력
    cout << '<';
    for (int i=0; i<N-1; i++)
    {
        cout << str[i] << ", ";
    }
    cout << str[N-1] << '>';
}