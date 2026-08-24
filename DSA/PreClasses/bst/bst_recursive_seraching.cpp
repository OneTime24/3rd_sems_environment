

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
};




int main(){

    tree t1;
    t1.createtree();
    t1.levelorder();

    Node* search_n1 = t1.searchBST(80);

    if(search_n1 != nullptr)
        cout <<endl<<search_n1->data;
    else
        cout << "Key not found";


    Node* search_n2 = t1.rsearch(root,90);

    if(search_n2 != nullptr)
        cout <<endl<<search_n2->data;
    else
        cout << "Key not found";

}