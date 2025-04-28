#include <iostream>
using namespace std;

class queue
{
    struct node
    {
        int data;
        node *next;
    };
    node *front, *rear;
    
    public:
    
    queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int x)
    {
        node *temp = new node;
        temp->data = x;
        temp->next = NULL;
        if(front == NULL)
        {
            front = temp;
            rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void dequeue()
    {
        if(front == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        node *temp = front;
        front = front->next;
        delete temp;
    }

    void peek()
    {
        if(front == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << front->data << endl;
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
                cout << "Enter the element to enqueue: ";
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
    return 0;
}
