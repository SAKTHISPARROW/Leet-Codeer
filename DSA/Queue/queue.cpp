#include <iostream>
using namespace std;
/*#define SIZE 5

int arr[SIZE], front = -1, rear = -1;
void Enqueue(int a)
{
    if (rear == SIZE - 1)
        cout << "Queue overflow";
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    arr[rear] = a;
    cout << a << "Enqueued in Queue\n";
}
void Dequeue()
{
    if (rear == -1)
        cout << "Queue underflow";
    else
    {
        cout << arr[front] << "is Dequeued from queue\n";
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}
void display()
{
    if (rear == -1)
        cout << "Queue empty";
    else
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i];
        }
}
// Struct approach
struct myQ
{
    int front;
    int rear;
    unsigned size;
    int *arr;
};

struct myQ *create(unsigned size)
{
    struct myQ *queue = (struct myQ *)malloc(sizeof(struct myQ));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    queue->arr = (int *)malloc(queue->size * sizeof(int));
    return queue;
}
void Enqueue(struct myQ *q, int val)
{
    if (q->rear == q->size - 1)
        cout << "Queue overflow\n";
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->arr[q->rear] = val;
    cout << val << " Enqueued in queue\n";
}
void Dequeue(struct myQ *q)
{
    if (q->front == -1)
    {
        cout << "Queue underflow\n";
    }
    else
    {
        cout << q->arr[q->front] << " is Dequeuef from queue\n";
        q->front++;
        if (q->front > q->rear)
            q->front = q->rear = -1;
    }
}
void display(struct myQ *q)
{
    if (q->front == -1)
        cout << "Queue empty\n";
    for (int i = q->front; i <= q->rear; i++)
    {
        cout << q->arr[i];
    }
}*/
class Q
{
    int front, rear, curr;
    unsigned maxcap;
    int *arr;

public:
    Q(int size)
    {
        maxcap = size;
        front = 0;
        rear = maxcap - 1;
        curr = 0;
        arr = new int[maxcap];
    }
    void enq(int x);
    void deq();
    void disp();
    bool isfull();
    bool isemp();
};
bool Q::isfull()
{
    if (curr == maxcap)
    {
        cout << "Queue Overflow\n";
    }
    return (curr == maxcap);
}
bool Q::isemp()
{
    if (curr == 0)
    {
        cout << "Queue underflow\n";
    }
    return (curr == 0);
}
void Q::enq(int x)
{
    if (isfull())
        cout << " ";
    rear = (rear + 1) % maxcap;
    arr[rear] = x;
    curr = curr + 1;
    cout << x << " is added in queue\n";
}
void Q::deq()
{
    if (isemp())
        cout << "";
    int i = arr[front];
    front = (front + 1) % maxcap;
    cout << i << " dequeued from queue\n";
}
void Q::disp()
{
    if (isemp())
        cout << "";

    else
    {
        int i, j;
        for (i = front, j = 0; j < curr; j++)
            cout << arr[(i + j) % maxcap] << " ";
    }
}
int main()
{
    // struct myQ *q = create(10);
    Q queue = Q(5);
    queue.enq(10);
    queue.enq(20);
    queue.enq(30);
    queue.enq(40);

    queue.deq();
    queue.deq();

    queue.disp();
    return 0;
}
