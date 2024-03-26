#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *nxt;
};
int calc(Node *head)
{
    int n = 0;
    while (head->nxt != NULL)
    {
        n++;
        head = head->nxt;
    }
    return n;
}
void insert(Node **head, int data)
{
    Node *n = new Node();
    n->data = data;
    n->nxt = *head;
    *head = n;
}
void deletenode(Node **head, int data)
{
    Node *temp = *head;
    Node *prev;
    int n = calc(*head);
    if (data < 1 || n < data)
    {
        cout << "Invalid pos.\n";
        return;
    }
    if (data == 1)
    {
        *head = temp->nxt;
        cout << temp->data << " is deleted from list\n";
        free(temp);

        return;
    }
    while (--data)
    {
        prev = temp;
        temp = temp->nxt;
    }
    prev->nxt = temp->nxt;
    cout << temp->data << " is deleted from list\n";
    free(temp);
}
/*void deletenode(Node **head, int data)
{
    Node *temp = new Node();
    temp = *head;
    Node *prev = new Node();
    if (temp->nxt == NULL)
    {
        *head = NULL;
        free(temp);
        cout << data << " is deleted from list" << endl;
        return;
    }
    if (temp != NULL && temp->data == data)
    {
        *head = temp->nxt;
        free(temp);
        cout << data << " is deleted from list" << endl;
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
    free(temp);
    cout << data << " is deleted from list" << endl;
}*/
void display(Node *node)
{
    cout << endl;

    // as linked list will end when Node is Null
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->nxt;
    }
    cout << endl;
}
/*int main()
{
   /*Node *head = NULL;
    /*Need & i.e. address as we
  need to change head address only needs to traverse
  and access items temporarily

    insert(&head, 12);
    insert(&head, 16);
    insert(&head, 20);
    insert(&head, 24);
    insert(&head, 30);
    insert(&head, 22);


    printf("Linked List Before Operations : ");
    display(head);

    // deleting first occurance of a value in linked list
    deletenode(&head, 22);
    deletenode(&head, 20);
    deletenode(&head, 12);

    printf("Linked List After Operations : ");

    display(head);
    return 0;
}*/
int main()
{
    Node *head = NULL;
    /*Need & i.e. address as we
    need to change head address only needs to traverse
    and access items temporarily
    */
    insert(&head, 12);
    insert(&head, 16);
    insert(&head, 20);
    insert(&head, 24);
    insert(&head, 30);
    insert(&head, 22);

    /*No need for & i.e. address as we do not
    need to change head address
    */
    display(head);

    // deleting first occurance of a value in linked list
    deletenode(&head, 1);
    display(head);

    deletenode(&head, 3);
    display(head);

    deletenode(&head, 4);
    display(head);

    deletenode(&head, -2);
    deletenode(&head, 10);
    return 0;
}