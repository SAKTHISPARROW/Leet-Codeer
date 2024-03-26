#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *nxt;

    Node(int val)
    {
        data = val;
        nxt = NULL;
    }
};
/*void insertn(Node **head, int data)
{
    Node *n = new Node(data);
    if (*head == NULL)
    {
        *head = n;
        (*head)->nxt = *head;
        return;
    }
    Node *temp = *head;
    while (temp->nxt != *head)
    {
        temp = temp->nxt;
    }
    temp->nxt = n;
    n->nxt = *head;
    *head = n;
}
void insertLast(Node **head, int data)
{
    Node *n = new Node(data);
    if (*head == NULL)
    {
        *head = n;
        (*head)->nxt = *head;
        return;
    }
    Node *curr = *head;
    while (curr->nxt != *head)
    {
        curr = curr->nxt;
    }
    curr->nxt = n;
    n->nxt = *head;
}*/
// OptimizedApproach
void insertn(Node **head, int data)
{
    Node *n = new Node(data);
    if (*head == NULL)
    {
        *head = n;
        (*head)->nxt = *head;
        return;
    }
    n->nxt = (*head)->nxt;
    (*head)->nxt = n;
    int temp = (*head)->data;
    (*head)->data = n->data;
    n->data = temp;
}
void insertLast(Node **head, int data)
{
    Node *n = new Node(data);
    if (*head == NULL)
    {
        *head = n;
        (*head)->nxt = *head;
        return;
    }
    n->nxt = (*head)->nxt;
    (*head)->nxt = n;
    int temp = (*head)->data;
    (*head)->data = n->data;
    n->data = temp;
    *head = n;
}
void display(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->nxt;
    } while (temp != head);
    cout << endl;
}
int main()
{
    Node *head = NULL;
    insertn(&head, 12);
    insertn(&head, 16);
    insertn(&head, 20);
    insertn(&head, 24);
    insertn(&head, 30);
    insertn(&head, 22);
    insertLast(&head, 12);
    insertLast(&head, 16);
    insertLast(&head, 20);
    insertLast(&head, 24);
    insertLast(&head, 30);
    insertLast(&head, 22);
    display(head);

    return 0;
}