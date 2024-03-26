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
/*void dels(Node **head)
{
    if (*head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }
    if ((*head)->nxt == *head)
    {
        cout << "Node deleted " << (*head)->data << endl;
        *head = NULL;
        return;
    }
    Node *curr = *head;
    while (curr->nxt != *head)
    {
        curr = curr->nxt;
    }
    curr->nxt = (*head)->nxt;
    Node *temp = *head;
    *head = (*head)->nxt;
    cout << "Node deleted " << temp->data << endl;
    delete (temp);
}*/
void dels(Node **head)
{
    if (*head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }
    if ((*head)->nxt == *head)
    {
        cout << "Node deleted " << (*head)->data << endl;
        *head = NULL;
        return;
    }
    cout << "Node deleted " << (*head)->data << endl;
    (*head)->data = (*head)->nxt->data;
    Node *temp = (*head)->nxt;

    (*head)->nxt = (*head)->nxt->nxt;

    delete (temp);
}
void kdels(Node **head, int k)
{
    if (*head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }
    if (k == 1)
    {
        dels(head);
        return;
    }
    Node *curr = *head;
    for (int i = 0; i < k - 2; i++)
        curr = curr->nxt;

    Node *temp = curr->nxt;
    curr->nxt = curr->nxt->nxt;
    cout << temp->data << " is deleted from list";
    delete (temp);
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
    display(head);
    dels(&head);
    display(head);

    dels(&head);
    display(head);
    kdels(&head, 2);
    display(head);

    // last node
    kdels(&head, 1);
    display(head);
    return 0;
}