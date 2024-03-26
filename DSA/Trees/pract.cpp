#include <iostream>
#include <limits.h>
#include <queue>
#include <algorithm>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void printLevelOrder(Node *root)
{
    int sum = 0;
    int size = 0;
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *n = q.front();
        sum += n->data;
        size++;
        cout << n->data << " ";
        q.pop();
        if (n->left != NULL)
            q.push(n->left);
        if (n->right != NULL)
            q.push(n->right);
    }
    cout << "\nSum of all nodes is " << sum;
    cout << "\n Total number of nodes is " << size;
}
int mcal(Node *root)
{
    if (root == NULL)
        return INT_MIN;
    else
    {
        return max(root->data, max(mcal(root->left), mcal(root->right)));
    }
}
int main()
{

    Node *root = new Node(10);
    root->left = new Node(15);
    root->right = new Node(20);
    root->left->left = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(35);
    root->right->right = new Node(40);
    root->left->left->left = new Node(45);
    printLevelOrder(root);
    cout << "\nMax element in tree is " << mcal(root);
}