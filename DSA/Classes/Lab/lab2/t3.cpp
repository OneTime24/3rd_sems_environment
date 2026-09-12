#include <iostream>

using namespace std;


class arra{

    private:
    int *arr;
    int size;
    int len;

    public:

    arra(int sz){
        arr=new int[sz];

        size=sz;
        len=0;
    }

    void append(int val){     

        if(len==size){
            cout<<"Product List is full.. "<<endl;
            return ;
        }

        for(int i=0;i<len;i++){
            if(*(arr+i)==val){
                cout<<"Duplicate Product ID is not allowed..."<<endl;
                return ;
            }
        }
        
        *(arr+len++)=val;
        return ;
    }

    void insert(int pos, int val){

        if(len==size){
            cout<<"Product List is full.. "<<endl;
            return ;
        }

        if(pos<0 || pos>len){
            cout<<"Invalid position..."<<endl;
            return ;
        }

        for(int i=0;i<len;i++){
            if(*(arr+i)==val){
                cout<<"Duplicate Product ID is not allowed..."<<endl;
                return ;
            }
        }

        for(int i=len-1;i>=pos;i--){
            *(arr+i+1)=*(arr+i);
        }

        *(arr+pos)=val;
        len++;

    }

    void remove_id(int id){

        for(int i=0;i<len;i++){
            if(*(arr+i)==id){

                for(int j=i;j<len-1;j++){
                    *(arr+j)=*(arr+j+1);
                }

                len--;

                cout<<"Product ID "<<id<<" removed successfully..."<<endl;
                return ;
            }
        }

        cout<<"Product Not Found..."<<endl;
        return ;
    }

    void remove(int pos){

        if(pos<0 || pos>=len){
            cout<<"Invalid position..."<<endl;
            return ;
        }

        for(int i=pos;i<len-1;i++){
            *(arr+i)=*(arr+i+1);
        }

        len--;

        cout<<"Product removed successfully..."<<endl;
    }

    void search(int id){

        for(int i=0;i<len;i++){
            if(*(arr+i)==id){
                cout<<"Product ID available at Index: "<<i<<endl;
                return ;
            }
        }

        cout<<"Product Not Found: "<<endl;
        return ;
    }

    void traverse(){

        if(len==0){
            cout<<"No Product Records Found | Product List is empty: "<<endl;
            return ;
        }

        for(int i=0;i<len;i++){
            cout<<"Product ID: "<<*(arr+i)<<endl;
        }
    }

    void count(){

        cout<<"Current Number of Products: "<<len<<endl;
    }

    void exists(int id){

        for(int i=0;i<len;i++){
            if(*(arr+i)==id){
                cout<<"Product ID exists in the catalog..."<<endl;
                return ;
            }
        }

        cout<<"Product ID does not exist in the catalog..."<<endl;
    }
};


int main(){

    arra products(15);

    products.append(101);
    products.append(102);
    products.append(103);
    products.append(104);
    products.append(105);
    products.append(106);
    products.append(107);
    products.append(108);
    products.append(109);
    products.append(110);

    cout<<"\n_______________________________\n";
    cout<<"Initial Product List"<<endl;
    cout<<"_______________________________\n";

    products.traverse();

    cout<<"\n_______________________________\n";
    cout<<"After Insertion"<<endl;
    cout<<"_______________________________\n";

    products.insert(5,500);
    products.traverse();

    cout<<"\n_______________________________\n";
    cout<<"Trying Duplicate Product"<<endl;
    cout<<"_______________________________\n";

    products.append(105);

    cout<<"\n_______________________________\n";
    cout<<"After Removing Product ID"<<endl;
    cout<<"_______________________________\n";

    products.remove_id(105);
    products.traverse();

    cout<<"\n_______________________________\n";
    cout<<"After Removing Product by Position"<<endl;
    cout<<"_______________________________\n";

    products.remove(2);
    products.traverse();

    cout<<"\n_______________________________\n";
    cout<<"Searching Product"<<endl;
    cout<<"_______________________________\n";

    products.search(108);
    products.search(999);

    cout<<"\n_______________________________\n";
    cout<<"Checking Product Existence"<<endl;
    cout<<"_______________________________\n";

    products.exists(110);
    products.exists(999);

    cout<<"\n_______________________________\n";
    products.count();

}
