#include <iostream>
#include <stack>
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
void spy(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> s;
    s.push(root);
    stack<Node *> t;
    while (!s.empty() || !t.empty())
    {
        while (!s.empty())
        {
            Node *temp = s.top();
            s.pop();
            cout << temp->data << " ";
            if (temp->left != NULL)
                s.push(temp->left);
            if (temp->right != NULL)
                s.push(temp->right);
        }
        while (!s.empty())
        {
            Node *temp = t.top();
            t.pop();
            cout << temp->data << " ";
            if (temp->left != NULL)
                s.push(temp->right);
            if (temp->right != NULL)
                s.push(temp->left);
        }
    }
}
int main()
{
    Node *root = new Node(20);
    root->left = new Node(70);
    root->right = new Node(90);
    root->left->left = new Node(30);
    root->left->left = new Node(40);
    root->right->right = new Node(70);

    // print_left_view(root, 1);
    spy(root);
}