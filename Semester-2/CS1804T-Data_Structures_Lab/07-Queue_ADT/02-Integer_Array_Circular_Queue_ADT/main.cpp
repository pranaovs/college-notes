#include <iostream>
using namespace std;

class queue
{
    int arr[5];
    int front, rear,size;

    public:

    queue()
    {
        front = -1;
        rear = -1;
        size = 0;
    }

    void enqueue(int x)
    {
        if(size == 5)
        {
            cout << "Queue is full" << endl;
            return;
        }
        if(front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % 5;
        arr[rear] = x;
        size++;
    }

    void dequeue()
    {
        if(size == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        front = (front + 1) % 5;
        size--;
    }

    void peek()
    {
        if(size == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << arr[front] << endl;
    }
};

int main()
{
    int exit = 0;
    queue q;
    while(exit == 0)
    {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Exit" << endl;
        int choice;
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "Enter the element to be enqueued: ";
                int x;
                cin >> x;
                q.enqueue(x);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                exit = 1;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}