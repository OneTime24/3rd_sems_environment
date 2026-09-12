#include <iostream>

using namespace std;


class supplyList{

    private:
    int *arr;
    int capacity;
    int len;

    public:

    supplyList(int cap){
        arr=new int[cap];

        capacity=cap;
        len=0;
    }

    void add(int code){

        if(len==capacity){
            cout<<"Supply list is full.. "<<endl;
            return ;
        }

        *(arr+len++)=code;
        cout<<"Supply code added successfully..."<<endl;
    }


    void insert(int pos,int code){

        if(len==capacity){
            cout<<"Supply list is full.. "<<endl;
            return ;
        }

        if(pos<0 || pos>len){
            cout<<"Invalid position..."<<endl;
            return ;
        }

        for(int i=len-1;i>=pos;i--){
            *(arr+i+1)=*(arr+i);
        }

        *(arr+pos)=code;
        len++;

        cout<<"Supply code inserted successfully..."<<endl;
    }


    void remove(int pos){

        if(len==0){
            cout<<"Supply list is empty..."<<endl;
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

        cout<<"Supply code removed successfully..."<<endl;
    }


    void remove_all(int code){

        if(len==0){
            cout<<"Supply list is empty..."<<endl;
            return ;
        }

        int i=0;

        while(i<len){

            if(*(arr+i)==code){

                for(int j=i;j<len-1;j++){
                    *(arr+j)=*(arr+j+1);
                }

                len--;
            }
            else{
                i++;
            }
        }

        cout<<"All occurrences of supply code "<<code<<" removed..."<<endl;
    }


    void search(int code){

        bool found=false;

        cout<<"Supply code "<<code<<" found at positions: ";

        for(int i=0;i<len;i++){

            if(*(arr+i)==code){
                cout<<i<<" ";
                found=true;
            }
        }

        if(!found){
            cout<<"No positions found";
        }

        cout<<endl;
    }


    void display(){

        if(len==0){
            cout<<"Supply list is empty..."<<endl;
            return ;
        }

        cout<<"Supply arr: ";

        for(int i=0;i<len;i++){
            cout<<*(arr+i)<<" ";
        }

        cout<<endl;
    }


    void reverse(){

        int start=0;
        int end=len-1;

        while(start<end){

            int temp=*(arr+start);
            *(arr+start)=*(arr+end);
            *(arr+end)=temp;

            start++;
            end--;
        }

        cout<<"Supply list reversed successfully..."<<endl;
    }


    void status(){

        cout<<"Current Size: "<<len<<endl;
        cout<<"Capacity: "<<capacity<<endl;
    }


    void clear(){

        len=0;

        cout<<"Supply list cleared successfully..."<<endl;
    }


    ~supplyList(){
        delete[] arr;
    }
};

int main(){

    supplyList supplies(10);

    int choice;
    int code;
    int pos;


    do{

        cout<<"\n\n========== Emergency Relief Supply List ==========\n";

        cout<<"1. Add supply code"<<endl;
        cout<<"2. Insert supply code"<<endl;
        cout<<"3. Remove supply code"<<endl;
        cout<<"4. Remove all occurrences"<<endl;
        cout<<"5. Search supply code"<<endl;
        cout<<"6. Display supply list"<<endl;
        cout<<"7. Reverse supply list"<<endl;
        cout<<"8. Display size and capacity"<<endl;
        cout<<"9. Clear supply list"<<endl;
        cout<<"0. Exit"<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;


        switch(choice){

            case 1:

                cout<<"Enter supply code: ";
                cin>>code;

                supplies.add(code);

                break;


            case 2:

                cout<<"Enter position: ";
                cin>>pos;

                cout<<"Enter supply code: ";
                cin>>code;

                supplies.insert(pos,code);

                break;


            case 3:

                cout<<"Enter position to remove: ";
                cin>>pos;

                supplies.remove(pos);

                break;


            case 4:

                cout<<"Enter supply code to remove: ";
                cin>>code;

                supplies.remove_all(code);

                break;


            case 5:

                cout<<"Enter supply code to search: ";
                cin>>code;

                supplies.search(code);

                break;


            case 6:

                supplies.display();

                break;


            case 7:

                supplies.reverse();

                break;


            case 8:

                supplies.status();

                break;


            case 9:

                supplies.clear();

                break;


            case 0:

                cout<<"Exiting program..."<<endl;

                break;


            default:

                cout<<"Invalid choice..."<<endl;
        }

    }while(choice!=0);


    return 0;
}


/*
Sample Run:


========== Emergency Relief Supply List ==========
1. Add supply code
2. Insert supply code
3. Remove supply code
4. Remove all occurrences
5. Search supply code
6. Display supply list
7. Reverse supply list
8. Display size and capacity
9. Clear supply list
0. Exit
Enter your choice: 1

Enter supply code: 101
Supply code added successfully...


Enter your choice: 1
Enter supply code: 202
Supply code added successfully...


Enter your choice: 1
Enter supply code: 303
Supply code added successfully...


Enter your choice: 1
Enter supply code: 202
Supply code added successfully...


Enter your choice: 1
Enter supply code: 404
Supply code added successfully...


Enter your choice: 6
Supply arr: 101 202 303 202 404


Enter your choice: 2
Enter position: 2
Enter supply code: 999
Supply code inserted successfully...


Enter your choice: 6
Supply arr: 101 202 999 303 202 404


Enter your choice: 5
Enter supply code to search: 202
Supply code 202 found at positions: 1 4


Enter your choice: 4
Enter supply code to remove: 202
All occurrences of supply code 202 removed...


Enter your choice: 6
Supply arr: 101 999 303 404


Enter your choice: 7
Supply list reversed successfully...


Enter your choice: 6
Supply arr: 404 303 999 101


Enter your choice: 8
Current Size: 4
Capacity: 10


Enter your choice: 9
Supply list cleared successfully...


Enter your choice: 6
Supply list is empty...


Enter your choice: 0
Exiting program...
*/