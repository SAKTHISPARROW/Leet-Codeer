#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *nxt;
};
void middle(Node *head)
{
    Node *slw = head;
    Node *fast = head;
    if (head != NULL)
    {
        while (fast != NULL && fast->nxt != NULL)
        {
            slw = slw->nxt;
            fast = fast->nxt->nxt;
        }
        cout << "Middle Element is " << slw->data;
    }
}
void insert(Node **head, int data)
{
    Node *n = new Node();
    n->data = data;
    n->nxt = *head;
    *head = n;
}

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
    insert(&head, 32);
    /*No need for & i.e. address as we do not
    need to change head address
    */
    display(head);

    // deleting first occurance of a value in linked list
    middle(head);

    return 0;
}