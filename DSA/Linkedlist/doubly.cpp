#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *nxt;
};

void insertStart(Node **head, int data)
{
    Node *n = new Node;
    n->data = data;
    n->nxt = *head;
    n->prev = NULL;
    if (*head != NULL)
    {
        (*head)->prev = n;
    }
    *head = n;
}
void insertLast(Node **head, int data)
{
    Node *n = new Node();
    n->data = data;
    n->nxt = NULL;
    if (*head == NULL)
    {
        *head = n;
        n->prev = NULL;
        return;
    }
    Node *temp = *head;
    while (temp->nxt != NULL)
    {
        temp = temp->nxt;
    }
    temp->nxt = n;
    n->prev = temp;
}
void display(Node *head)
{
    Node *end;
    cout << "List in Forward direction: \n";
    while (head != NULL)
    {
        cout << head->data << " ";
        end = head;
        head = head->nxt;
    }
    cout << "\nList in backward direction: \n";
    while (end != NULL)
    {
        cout << end->data << " ";
        end = end->prev;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;

    insertStart(&head, 12);
    insertStart(&head, 16);
    insertStart(&head, 20);

    insertLast(&head, 10);
    insertLast(&head, 14);
    insertLast(&head, 18);
    insertLast(&head, 11);

    display(head);

    return 0;
}
