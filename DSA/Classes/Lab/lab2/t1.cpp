#include <iostream>

using namespace std;


class arra{

    private:
    int *arr;
    int size;
    int len;
    int curr;

    public:

    arra(int sz){
        arr=new int[sz];

        size=sz;
        len=0;
        curr=-1;
    }

    void append(int val){       //inserting at the end of the program

        if(len==size){
            cout<<"Array size is full.. "<<endl;
            return ;
        }
        
        *(arr+len++)=val;
        return ;
    }

    void insert(int pos, int val){
        if(len==size){
            cout<<"Array size is full.. "<<endl;
            return ;
        }


        if(pos<0 || pos>len){
            cout<<"Invalid position..."<<endl;
            return ;
        }

        for(int i=len-1;i>=pos;i--){
            *(arr+i+1)=*(arr+i);
        }

        *(arr+pos)=val;
        len++;

    }

    void remove(int pos){

        if(len==0){
            cout<<"Array list is empty..."<<endl;
            return ;
        }

        if(pos<0 || pos>=len){
            cout<<"Invalid position..."<<endl;
            return ;
        }

        for(int i=pos;i<len-1;i++){
            *(arr+i)=*(arr+i+1);
        }

        len--;

        
    }

    void traverse(){

        if(len==0){
            cout<<"Array list is empty..."<<endl;
            return ;
        }


        for(int i=0;i<len;i++){
            cout<<"Student ID: "<<*(arr+i)<<endl;
        }
    }

    void search(int id){

        for(int i=0;i<len;i++){
            if(*(arr+i)==id){
                cout<<"Student ID available at Index: "<<i<<" and Address: "<<(arr+i)<<endl;
                return ;
            }
        }

        cout<<"Student Not Found: "<<endl;
        return ;
    }

    void status_array(){
        if(len==0){
            cout<<"No Student Record Found | Array list is emptry: "<<endl;
        }else if(len==size){
            cout<<"Database/ArrayList is Full | More Student records insertion is not possible..."<<endl;
        }else{
            cout<<"Database/Arraylist have space for more insertion..."<<endl;
        }
    }
};


int main(){

    arra stdids(10);

    int choice;
    int id;
    int pos;

    do{

        cout<<"\n_______________________________\n";
        cout<<"1. Add Student ID"<<endl;
        cout<<"2. Insert Student ID"<<endl;
        cout<<"3. Remove Student ID"<<endl;
        cout<<"4. Search Student ID"<<endl;
        cout<<"5. Display Student IDs"<<endl;
        cout<<"6. Check List Status"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;


        switch(choice){

            case 1:
                cout<<"Enter Student ID: ";
                cin>>id;
                stdids.append(id);
                break;

            case 2:
                cout<<"Enter position: ";
                cin>>pos;
                cout<<"Enter Student ID: ";
                cin>>id;
                stdids.insert(pos,id);
                break;

            case 3:
                cout<<"Enter position: ";
                cin>>pos;
                stdids.remove(pos);
                break;

            case 4:
                cout<<"Enter Student ID: ";
                cin>>id;
                stdids.search(id);
                break;

            case 5:
                stdids.traverse();
                break;

            case 6:
                stdids.status_array();
                break;

            case 7:
                cout<<"Program Exited..."<<endl;
                break;

            default:
                cout<<"Invalid choice..."<<endl;
        }

    }while(choice!=7);


}