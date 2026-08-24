

#include <iostream>
#include <queue>
using namespace std;


struct Node{
    Node *left;
    int data;
    Node *right;
};



Node *root;


class tree{

    public:

    tree(){
        root=new Node;
        root=nullptr;
    }

    void createtree(){
        Node *p;
        Node *t;

        int x;

        cout<<"Enter root value: ";
        cin>>x;

        root=new Node;
        root->data=x;
        root->left=nullptr;
        root->right=nullptr;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            p=new Node;
            p=q.front();
            q.pop();

            cout<<"Enter left child of "<<p->data<<" value: ";
            cin>>x;
            
            if(x!=-1){
                t=new Node;
                t->data=x;
                t->left=nullptr;
                t->right=nullptr;

                p->left=t;
                q.push(t);
            }


            cout<<"Enter RIght child of "<<p->data<<" value: ";
            cin>>x;
            
            if(x!=-1){
                t=new Node;
                t->data=x;
                t->left=nullptr;
                t->right=nullptr;

                p->right=t;
                q.push(t);
            }

        }

    }
    int Height(Node *p)
{
    if (p == nullptr)
        return 0;

    int x = Height(p->left);
    int y = Height(p->right);

    return (x > y ? x : y) + 1;
}
Node* InPre(Node *p)
{
    while (p && p->right != nullptr)
        p = p->right;

    return p;
}
Node* InSucc(Node *p)
{
    while (p && p->left != nullptr)
        p = p->left;

    return p;
}
    void levelorder(){
        Node *p=new Node;
        p=root;

        if(p==nullptr){
            return ;
        }

        queue<Node*> q;
        q.push(p);

        while(!q.empty()){
            p=q.front();
            q.pop();

            cout<<p->data<<" ";

            if(p->left!=nullptr){
                q.push(p->left);
            }
            if(p->right!=nullptr){
                q.push(p->right);
            }
        }



    }

    Node* searchBST(int key){
        Node *p=new Node;
        p=root;

        while(p!=nullptr){

            if(key==p->data){
                return p;
            }
            if(key<p->data){
                p=p->left;
            }
            if(key>p->data){
                p=p->right;
            }
            
        }
        return nullptr;

    }
    Node* rsearch(Node *root, int key){
        
        Node *p=root;

        if(p==nullptr){
            return nullptr;
        }


        if(key==p->data){
            return p;
        }

        if(key<p->data){
           return rsearch(p->left,key);
        }

        return rsearch(p->right,key);


    }
    void insert(int key){

        Node *p=root;
        Node *q=nullptr;
        while(p!=nullptr){
            q=p;
            if(key<p->data){
                p=p->left;
            }else if(key>p->data){
                p=p->right;
            }else{
                return ;
            }
        }

        Node *t=new Node;

        
        t->data=key;

        t->left=nullptr;
        t->right=nullptr;

        if (root == nullptr)
    {
        root = t;
        return;
    }
        if(key<q->data){
            q->left=t;
        }else{
            q->right=t;
        }
    }
    Node* Rinsert(Node* p, int key){

        if(p==nullptr){
            Node *t=new Node;
            t->data=key;
            t->left=nullptr;
            t->right=nullptr;
            return t;
        }

        if(key<p->data){
            p->left= Rinsert(p->left,key);
        }else if(key>p->data){
            p->right= Rinsert(p->right,key);
        }
        return p;
    }
    Node* Delete(Node *p, int key)      
{
    if (p == nullptr)
        return nullptr;

    // Leaf node
    if (p->left == nullptr && p->right == nullptr)
    {
        if (p == root)
            root = nullptr;

        delete p;
        return nullptr;
    }

    // Search
    if (key < p->data)
    {
        p->left = Delete(p->left, key);
    }
    else if (key > p->data)
    {
        p->right = Delete(p->right, key);
    }
    else
    {
        // Node found

        if (Height(p->left) > Height(p->right))
        {
            Node *q = InPre(p->left);

            p->data = q->data;

            p->left = Delete(p->left, q->data);
        }
        else
        {
            Node *q = InSucc(p->right);

            p->data = q->data;

            p->right = Delete(p->right, q->data);
        }
    }

    return p;
}
};




int main(){

    tree t1;

    root = t1.Rinsert(root, 50);
    root = t1.Rinsert(root, 30);
    root = t1.Rinsert(root, 70);
    root = t1.Rinsert(root, 20);

    t1.levelorder();


    Node *updated=t1.Delete(root,70);

    cout<<"\nDeleted: "<<updated->data;


}