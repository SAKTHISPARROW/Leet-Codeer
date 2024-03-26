#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *nxt;
    Node *prev;
};
void deletenode(Node **head, int data)
{
    Node *temp = *head;
    Node *prev = new Node();
    if (temp->nxt == NULL)
    {
        *head = NULL;
        cout << data << " is deleted from list\n";
        free(temp);
        return;
    }
    if (temp != NULL && temp->data == data)
    {
        *head = temp->nxt;
        (*head)->prev = NULL;
        cout << data << " is deleted from list\n";
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->nxt;
    }
    if (temp == NULL)
    {
        cout << "Element not found\n";
        return;
    }
    prev->nxt = temp->nxt;
    if (temp->nxt == NULL)
    {
        cout << data << " is deleted from list\n";
        free(temp);
        return;
    }
    Node *t = new Node();
    t = temp->nxt;
    t->prev = prev;
    free(temp);
    cout << data << " is deleted from list\n";
}
void insert(Node **head, int data)
{
    Node *n = new Node();
    n->data = data;
    n->nxt = *head;
    n->prev = NULL;
    if (*head != NULL)
        (*head)->prev = n;
    *head = n;
}
void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->nxt;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;

    /*Need & i.e. address as we
    need to change head address only needs to traverse
    and access items temporarily*/

    insert(&head, 12);
    insert(&head, 16);
    insert(&head, 20);
    insert(&head, 24);
    insert(&head, 30);
    insert(&head, 22);

    /*No need for & i.e. address as we do not
    need to change head address*/
    display(head);

    // deleting first occurance of a value in linked list
    deletenode(&head, 22);
    display(head);

    deletenode(&head, 20);
    display(head);

    deletenode(&head, 12);
    display(head);

    deletenode(&head, 30);
    display(head);

    deletenode(&head, 16);
    display(head);

    deletenode(&head, 24);
    display(head);

    return 0;
}