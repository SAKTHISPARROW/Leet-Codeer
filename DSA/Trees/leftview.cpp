#include <bits/stdc++.h>
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
int m = 0;
void print_left_view(Node *root, int curr)
{
    if (root == NULL)
        return;
    if (m < curr)
    {
        cout << root->data << " ";
        m = curr;
    }
    print_left_view(root->left, curr + 1);
    print_left_view(root->right, curr + 1);
}
void optleft(Node *root, int curr)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (i == 0)
                cout << temp->data << " ";
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
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
    optleft(root, 1);
}