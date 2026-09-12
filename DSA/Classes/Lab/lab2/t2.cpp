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
    }

    void append(int val){       //tp insert at the end of the program

        if(len==size){
            cout<<"Patient List is full.. "<<endl;
            return ;
        }
        
        *(arr+len++)=val;
        return ;
    }

    void insert(int pos, int val){
        if(len==size){
            cout<<"Patient List is full.. "<<endl;
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

        if(pos<0 || pos>=len){
            cout<<"Invalid position..."<<endl;
            return ;
        }

        for(int i=pos;i<len-1;i++){
            *(arr+i)=*(arr+i+1);
        }

        len--;

        
    }

    void remove_id(int id){

        for(int i=0;i<len;i++){
            if(*(arr+i)==id){

                for(int j=i;j<len-1;j++){
                    *(arr+j)=*(arr+j+1);
                }

                len--;

                cout<<"Patient ID "<<id<<" removed successfully..."<<endl;
                return ;
            }
        }

        cout<<"Patient Not Found..."<<endl;
        return ;
    }

    void search(int id){

        for(int i=0;i<len;i++){
            if(*(arr+i)==id){
                cout<<"Patient ID available at Index: "<<i<<" and Address: "<<(arr+i)<<endl;
                return ;
            }
        }

        cout<<"Patient Not Found: "<<endl;
        return ;
    }

    void traverse(){

        if(len==0){
            cout<<"No Patient Records Found | Patient List is empty: "<<endl;
            return ;
        }

        for(int i=0;i<len;i++){
            cout<<"Patient ID: "<<*(arr+i)<<endl;
        }
    }

    void first(){

        if(len==0){
            cout<<"Patient List is empty..."<<endl;
            return ;
        }

        cout<<"First Patient ID: "<<*(arr)<<endl;
    }

    void last(){

        if(len==0){
            cout<<"Patient List is empty..."<<endl;
            return ;
        }

        cout<<"Last Patient ID: "<<*(arr+len-1)<<endl;
    }

    void count(){

        cout<<"Current Number of Patients: "<<len<<endl;
    }
};


int main(){

    arra patients(20);

    int choice;
    int pos;
    int id;

    do{

        cout<<"\n_______________________________\n";
        cout<<"       Hospital Patient List"<<endl;
        cout<<"_______________________________\n";

        cout<<"1. Insert Patient at End"<<endl;
        cout<<"2. Insert Patient at Position"<<endl;
        cout<<"3. Delete Patient by Position"<<endl;
        cout<<"4. Delete Patient by ID"<<endl;
        cout<<"5. Search Patient"<<endl;
        cout<<"6. Display Patient List"<<endl;
        cout<<"7. Display First Patient"<<endl;
        cout<<"8. Display Last Patient"<<endl;
        cout<<"9. Display Number of Patients"<<endl;
        cout<<"0.Exit"<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){

            case 1:
                cout<<"Enter Patient Id: ";
                cin>>id;
                patients.append(id);
                break;

            case 2:
                cout<<"Enter position: ";
                cin>>pos;

                cout<<"Enter Patient ID: ";
                cin>>id;

                patients.insert(pos,id);
                break;

            case 3:
                cout<<"Enter position: ";
                cin>>pos;

                patients.remove(pos);
                break;

            case 4:
                cout<<"Enter Patient ID: ";
                cin>>id;

                patients.remove_id(id);
                break;

            case 5:
                cout<<"Enter Patient ID to search: ";
                cin>>id;

                patients.search(id);
                break;

            case 6:
                patients.traverse();
                break;

            case 7:
                patients.first();
                break;

            case 8:
                patients.last();
                break;

            case 9:
                patients.count();
                break;

            case 0:
                cout<<"Exiting Program..."<<endl;
                break;

            default:
                cout<<"Invalid Choice..."<<endl;
        }

    }while(choice!=0);

}


/*
Sample Execution:

1. Insert Patient at End
Enter Patient ID: 101

1. Insert Patient at End
Enter Patient ID: 102

1. Insert Patient at End
Enter Patient ID: 103

2. Insert Patient at Position
Enter position: 1
Enter Patient ID: 150

6. Display Patient List

Patient ID: 101
Patient ID: 150
Patient ID: 102
Patient ID: 103

3. Delete Patient by Position
Enter position: 2

6. Display Patient List

Patient ID: 101
Patient ID: 150
Patient ID: 103

5. Search Patient
Enter Patient ID to search: 999

Patient Not Found:
*/
