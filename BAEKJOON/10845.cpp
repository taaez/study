#include <iostream>

 using namespace std;

class Queue
{
private:
    int Capacity;
    int front;
    int rear;
    int *Array;
public:
    Queue(int N, int _front, int _rear)
        : Capacity(N), front(_front), rear(_rear)
    {
        Array = new int[N]; // push 최대 개수가 N이므로 최대크기 N
    }
    ~Queue()
    {
        delete []Array; // 동적할당 했었으므로 소멸자로 해제
    }
    void Enqueue(int num)
    {
        Array[rear++]=num;
    }
    void Dequeue()
    {
        if (rear == front) // empty인 조건
            cout << "-1" << '\n';
        else
            cout << Array[front++] << '\n';
    }
    void Size()
    {
        cout << rear-front << '\n';
    }
    void Empty()
    {
        if (rear == front)
            cout << '1' << '\n';
        else
            cout << '0' << '\n';
    }
    void Front()
    {
        if (rear == front)
            cout << "-1" << '\n';
        else   
            cout << Array[front] << '\n'; 
    }
    void Rear()
    {
        if (rear == front)
            cout << "-1" << '\n';
        else
            cout << Array[rear-1] << '\n'; 
    // rear는 enqueue 했을 때 값이 들어가는 곳의 인덱스이므로 그거보다 -1인 곳이 큐의 후단이다

    }
};

 int main ()
 {
    int N;
    int num;
    string command;

    cin >> N;
    Queue queue(N, 0, 0); //생성자를 이용해서 queue 생성

    for (int i=0; i<N; i++)
    {
        cin >> command;
        if (command == "push")
        {
            cin >> num;
            queue.Enqueue(num);
        }
        else if (command == "pop")
            queue.Dequeue();
        else if (command == "size")
            queue.Size();
        else if (command == "empty")
            queue.Empty();
        else if (command == "front")
            queue.Front();
        else if (command == "back")
            queue.Rear();
        else
          cout << "illegal input" << '\n';

    }
    return 0;

 }