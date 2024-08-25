#include <iostream>

 using namespace std;

class Deque
{
public:
    int Capacity;
    int front;
    int back;
    int *Array;
// public:
    Deque(int N)
        : Capacity(N+1), front((N-1)/2), back((N+1)/2)
    {
        Array = new int[N+1]; // push 최대 개수가 N이고, front, back을 N의 중간 2개로 잡으므로 크기는 N+1로 할당
    }
    ~Deque()
    {
        delete []Array; // 동적할당 했었으므로 소멸자로 해제
    }
    void Push_front(int num)
    {
        Array[front--]=num;
    }
    void Push_back(int num)
    {
        Array[back++]=num;
    }
    void Pop_front()
    {
        if (front+1 == back) // empty인 조건, back-front==1
            cout << "-1" << '\n';
        else
            cout << Array[++front] << '\n';
    }
    void Pop_back()
    {
        if (front+1 == back)
            cout << "-1" << '\n';
        else
            cout << Array[--back] << '\n';
    }
    void Size()
    {
        cout << back-front-1 << '\n';
    }
    void Empty()
    {
        if (front+1 == back)
            cout << '1' << '\n';
        else
            cout << '0' << '\n';
    }
    void Front()
    {
        if (front+1 == back)
            cout << "-1" << '\n';
        else   
            cout << Array[front+1] << '\n'; 
    }
    // front은 push_front 했을 때 값이 들어가는 곳의 인덱스이므로 그거보다 +1인 곳이 덱의 전단이다
    void Back()
    {
        if (front+1 == back)
            cout << "-1" << '\n';
        else
            cout << Array[back-1] << '\n'; 
    // back은 push_back 했을 때 값이 들어가는 곳의 인덱스이므로 그거보다 -1인 곳이 덱의 후단이다

    }
};

 int main ()
 {
    int N;
    int num;
    string command;

    cin >> N;
    Deque deque(N); //생성자를 이용해서 deque 생성
    
    for (int i=0; i<N; i++)
    {
        cin >> command;
        if (command == "push_front")
        {
            cin >> num;
            deque.Push_front(num);
        }
        else if (command == "push_back")
        {
            cin >> num;
            deque.Push_back(num);
        }
        else if (command == "pop_front")
            deque.Pop_front();
        else if (command == "pop_back")
            deque.Pop_back();
        else if (command == "size")
            deque.Size();
        else if (command == "empty")
            deque.Empty();
        else if (command == "front")
            deque.Front();
        else if (command == "back")
            deque.Back();
        else
          cout << "illegal input" << '\n';

    }
    return 0;

 }