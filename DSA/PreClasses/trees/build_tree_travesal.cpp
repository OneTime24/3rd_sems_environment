// hard for now, will learn later

#include <iostream>
using namespace std;

struct Node
{
    Node *left;
    int data;
    Node *right;
};

int search(int inorder[], int start, int end, int key)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == key)
            return i;
    }
    return -1;
}

Node* buildTree(int preorder[],
                int inorder[],
                int start,
                int end)
{
    static int preIndex = 0;

    if (start > end)
        return nullptr;

    // Create root
    Node *root = new Node;
    root->data = preorder[preIndex++];
    root->left = nullptr;
    root->right = nullptr;

    // Leaf node
    if (start == end)
        return root;

    // Find root in inorder
    int split = search(inorder, start, end, root->data);

    // Build left subtree
    root->left = buildTree(preorder,
                           inorder,
                           start,
                           split - 1);

    // Build right subtree
    root->right = buildTree(preorder,
                            inorder,
                            split + 1,
                            end);

    return root;
}

void inorderTraversal(Node *p)
{
    if (p)
    {
        inorderTraversal(p->left);
        cout << p->data << " ";
        inorderTraversal(p->right);
    }
}

int main()
{
    int preorder[] = {1,2,4,5,3,6,7};
    int inorder[]  = {4,2,5,1,6,3,7};

    int n = 7;

    Node *root = buildTree(preorder, inorder, 0, n - 1);

    cout << "Inorder Traversal:\n";
    inorderTraversal(root);
}