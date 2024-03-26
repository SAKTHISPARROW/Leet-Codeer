#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *nxt;
};

int calc(Node *n)
{
    int s = 0;
    while (n != NULL)
    {
        s++;
        n = n->nxt;
    }
    return s;
}

void ints(Node **head, int data)
{
    Node *n = new Node();
    n->data = data;
    n->nxt = *head;
    *head = n;
}

void intl(Node **head, int data)
{
    Node *n = new Node();
    n->data = data;
    n->nxt = NULL;
    if (*head == NULL)
    {
        *head = n;
        return;
    }
    else
    {
        Node *temp = *head;
        while (temp->nxt != NULL)
        {
            temp = temp->nxt;
        }
        temp->nxt = n;
    }
}

void intk(Node **head, int data, int pos)
{
    int n = calc(*head);
    if (pos < 1 || n < pos)
        cout << "Can link data with list.,Invalid pos" << endl;
    else
    {
        Node *new_node = new Node();
        new_node->data = data;
        new_node->nxt = NULL;
        Node *temp = *head;
        while (--pos)
        {
            temp = temp->nxt;
        }
        new_node->nxt = temp->nxt;
        temp->nxt = new_node;
    }
}

void disp(Node *head)
{
    Node *n = head;
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->nxt;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;

    ints(&head, 12);
    ints(&head, 16);
    ints(&head, 20);
    ints(&head, 12);
    intl(&head, 10);
    intl(&head, 14);
    intl(&head, 18);
    intl(&head, 11);
    intk(&head, 25, 3);
    disp(head);
    return 0;
}
