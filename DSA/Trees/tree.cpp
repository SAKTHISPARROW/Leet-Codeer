#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
void preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
int mdep(node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int lh = mdep(root->left);
        int rh = mdep(root->right);
        if (lh > rh)
            return lh + 1;
        else
            return rh + 1;
    }
}
void knodes(node *root, int k)
{
    if (root == NULL)
        return;
    else if (k == 0)
        cout << root->data << " ";
    else
    {
        knodes(root->left, k - 1);
        knodes(root->right, k - 1);
    }
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->left = new node(4);
    root->right->right = new node(5);

    cout << "\nThe Inorder is : ";
    inorder(root);
    cout << "\nThe Postorder is : ";
    postorder(root);
    cout << "\nThe Preorder is : ";
    preorder(root);
    cout << "\nThe height of tree is :" << mdep(root) << endl;
    knodes(root, 2);
}