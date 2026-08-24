

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

            queue<Node*> q;

            cout<<"Enter ROOT Value: ";
            cin>>x;
            root=new Node;
            root->data=x;
            root->left=nullptr;
            root->right=nullptr;

            q.push(root);
            
            while(!q.empty()){
                p=q.front();
                q.pop();
                
                cout<<"Enter LEft Child of"<<p->data<<" Value: ";
                cin>>x;
                if(x!=-1){
                t=new Node;
                t->data=x;
                t->left=nullptr;
                t->right=nullptr;

                p->left=t;
                q.push(t);
                }
                cout<<"Enter Right Child of"<<p->data<<" Value: ";
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

        void preorder(Node *p){

            if(p!=nullptr){

                cout<<p->data<<" ";
                preorder(p->left);
                preorder(p->right);
            }
        }
        void inorder(Node *p){

            if(p!=nullptr){

                inorder(p->left);
                cout<<p->data<<" ";
                inorder(p->right);
            }
       
        }


        void postorder(Node *p){

            if(p!=nullptr){

                postorder(p->left);
                postorder(p->right);
                cout<<p->data<<" ";
                
            }
        }


};


int main(){

    tree t1;
    t1.createtree();
    t1.preorder(root);
    cout<<endl;
    t1.inorder(root);
    cout<<endl;
    t1.postorder(root);
}

