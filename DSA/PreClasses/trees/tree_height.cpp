

#include <iostream>
#include <queue>
#include <stack>
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
        cout<<"Enter value of root:";
        cin>>x;
        root=new Node;
        root->data=x;
        root->left=nullptr;
        root->right=nullptr;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            p=q.front();
            q.pop();

            cout<<"Enter "<<p->data<<" Left CHuld: ";

            cin>>x;
            
            if(x!=-1){
                t=new Node;
                t->data=x;
                t->left=nullptr;
                t->right=nullptr;

                p->left=t;
                q.push(t);
            }

            cout<<"Enter "<<p->data<<" Right CHild: ";

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

    void itrpreorder(){
        stack<Node*> st;
        Node *p=root;

        while(p!=nullptr || !st.empty()){

            if(p!=nullptr){
                cout<<p->data<<" ";
                st.push(p);
                p=p->left;
            }else{
                p=st.top();
                st.pop();
                p=p->right;
            }
        }
    }

    void itrinorder(){

        stack <Node*> st;

        Node *p=root;

        while(p!=nullptr || !st.empty()){

            if(p!=nullptr){
                st.push(p);
                p=p->left;
            }else{
                p=st.top();
                st.pop();
                cout<<p->data<<" ";
                p=p->right;
            }
        }
    }


    void levelorder(){
        queue <Node*> q;
        Node *p=root;

        if(p==nullptr){
            return ;
        }

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

    int height(Node *root){
        Node *p=root;

        if(p==nullptr){
            return -1;
        }

        int x=height(p->left);
        int y=height(p->right);

        return max(x,y)+1;


    }

    int totalcount(Node *root){
        Node *p=root;

        if(p==nullptr){
            return 0;
        }
        return totalcount(p->left) + totalcount(p->right) + 1;
    }

    int leafNode(Node *root){
        Node *p=root;
         if (p == nullptr)
            return 0;

        if (p->left == nullptr && p->right == nullptr)
            return 1;

        return leafNode(p->left) + leafNode(p->right);
    }
};


int main(){

    tree t1;
    t1.createtree();
    t1.itrpreorder();
    cout<<endl;
    t1.itrinorder();
    cout<<endl;
    t1.levelorder();
    cout<<endl;

    cout<<t1.height(root)<<endl;

    cout<<t1.leafNode(root)<<endl;

    cout<<t1.totalcount(root)<<endl;
}