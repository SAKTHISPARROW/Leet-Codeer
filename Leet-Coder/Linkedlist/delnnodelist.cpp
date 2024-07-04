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
void disp(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->nxt;
    }
    cout << endl;
}
void deln(Node **head, int k)
{
    int n = calc(*head);
    Node *temp = *head;
    Node *prev;
    k = n - k;
    if (k < 1 || n < k)
    {
        cout << "Invalid pos.\n";
        return;
    }
    if (k == 1)
    {
        *head = temp->nxt;
        cout << temp->data << " is deleted from list\n";
        free(temp);

        return;
    }
    while (k--)
    {
        prev = temp;
        temp = temp->nxt;
    }
    prev->nxt = temp->nxt;
    cout << temp->data << " is deleted from list\n";
    free(temp);
    // cout << temp->data;
}
int main()
{
    Node *head = NULL;

    ints(&head, 12);
    ints(&head, 16);
    ints(&head, 20);
    ints(&head, 14);
    ints(&head, 17);
    cout << "Before deleting" << endl;
    disp(head);
    deln(&head, 2);
    cout << "After deleting" << endl;
    disp(head);
    return 0;
}