

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

int main(){

    Node *root=new Node;
    root->data=25;
    root->left=nullptr;
    root->right=nullptr;

    Node *p1=new Node;
    p1->data=30;
    p1->left=nullptr;
    p1->right=nullptr;

    Node *p2=new Node;
    p2->data=40;
    p2->left=nullptr;
    p2->right=nullptr;

    root->left=p1;
    root->right=p2;
}