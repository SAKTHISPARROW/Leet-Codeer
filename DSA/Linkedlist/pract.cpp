#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *nxt;
};
int calc(Node *head)
{
    int s = 0;
    while (head != NULL)
    {
        s++;
        head = head->nxt;
    }
    return s;
}
void ins(Node **head, int data)
{
    Node *n = new Node();
    n->data = data;
    n->nxt = *head;
    *head = n;
}
void disp(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->nxt;
    }
    cout << endl;
}
int findd(Node *head, int k)
{
    while (k--)
    {
        head = head->nxt;
    }
    cout << "Element :" << head->data;
    return head->data;
}
int main()
{
    Node *head = NULL;
    ins(&head, 11);
    ins(&head, 10);
    ins(&head, 9);
    ins(&head, 7);
    ins(&head, 5);
    ins(&head, 3);
    ins(&head, 2);

    disp(head);
    int x;
    cout << "Enter num to find: " << endl;
    cin >> x;
    int k = calc(head) - x;
    findd(head, k);
    return 0;
}