

#include <iostream>
#include <queue>
using namespace std;

struct Node{
    Node *left;
    int data;
    Node *right;
};

class tree{

    private:
        Node *root;

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

};


int main(){

    tree t1;
    t1.createtree();
}

