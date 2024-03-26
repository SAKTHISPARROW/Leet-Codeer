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
void print(std::vector<Node *> const &a)
{
    cout << "The path is: : ";

    for (int i = 0; i < a.size(); i++)
        cout << a.at(i)->data << ' ';
    return;
}
bool ispath(Node *root, vector<Node *> &p, int x)
{
    if (root == NULL)
        return false;
    p.push_back(root);
    if (root->data == x)
    {
        return true;
    }
    if (ispath(root->left, p, x) || ispath(root->right, p, x))
        return true;
    p.pop_back();
    return false;
}
Node *lsa(Node *root, int x, int y)
{
    vector<Node *> v, u;
    if (!ispath(root, v, x) || !ispath(root, u, y))
        return NULL;
    cout << "For node 1: ";
    print(v);
    cout << "\nFor node 2: ";
    print(u);
    for (int i = 0; i < v.size() - 1 && i < u.size() - 1; i++)
        if (v[i + 1] != u[i + 1])
            return v[i];
    return NULL;
}

int main()
{

    Node *root = new Node(70);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(50);
    root->left->right = new Node(10);
    root->left->left->left = new Node(60);
    root->left->left->right = new Node(40);
    root->left->left->left->left = new Node(90);
    root->left->left->right->right = new Node(110);
    root->left->right->right = new Node(80);
    root->left->right->right->right = new Node(100);

    Node *result = lsa(root, 90, 110);
    cout << "\nLowest Common Ancestor: " << result->data;
}