#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *nxt;
};
void disp(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->nxt;
    }
    cout << endl;
}
void ints(Node **head, int data)
{
    Node *n = new Node();
    n->data = data;
    n->nxt = *head;
    *head = n;
}
Node *rev(Node *head)
{
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        Node *front = temp->nxt;

        temp->nxt = prev;

        prev = temp;
        temp = front;
    }

    return prev;
}
Node *getknode(Node *temp, int k)
{
    k -= 1;
    while (temp->nxt != NULL && k > 0)
    {
        k--;
        temp = temp->nxt;
    }
    return temp;
}
Node *revn(Node *head, int k)
{
    Node *temp = head;

    Node *prevLast = NULL;

    while (temp != NULL)
    {
        Node *kThNode = getknode(temp, k);

        if (kThNode == NULL)
        {
            if (prevLast)
            {
                prevLast->nxt = temp;
            }
            break;
        }
        Node *nextNode = kThNode->nxt;
        kThNode->nxt = NULL;
        rev(temp);
        if (temp == head)
        {
            head = kThNode;
        }
        else
        {
            prevLast->nxt = kThNode;
        }
        prevLast = temp;
        temp = nextNode;
    }
    return head;
}
int main()
{
    Node *head = NULL;

    ints(&head, 12);
    ints(&head, 16);
    ints(&head, 20);
    ints(&head, 14);
    ints(&head, 17);
    cout << "Before Reversing" << endl;
    disp(head);
    head = revn(head, 2);
    cout << "After Reversing" << endl;
    disp(head);
    return 0;
}