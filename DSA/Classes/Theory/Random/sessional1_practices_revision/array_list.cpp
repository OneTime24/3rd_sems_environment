#include <iostream>
using namespace std;


class arra{
    private:

    int *arr;
    int len;
    int size;

    int *curr;

    public:

    arra(int size){

        this->size=size;
        arr=new int[size];
        len=0;
        curr=nullptr;
    }

    void start(){

        curr=arr;
    }

    void next(){
        if(curr < arr+len-1)
            curr=curr+1;
    }

    void back(){
        if(curr > arr){
            curr=curr-1;
        }else{
            cout<<"invalid position: \n";
        }
    }

    void tail(){

        curr=arr+len-1;
    }

    void insert(int pos, int val){

        if(pos<1 || pos>len+1){
            cout<<"Invalid Position : \n";
            return;
        }

        for(int i=len;i>=pos;i--){
            *(arr+i)=*(arr+i-1);
        }

        arr[pos-1]=val;
        len++;

        return;
    }

    void remove(int val){

        int pos=-1;

        for(int i=0;i<len;i++){
            if(arr[i]==val){
                pos=i;
                break;
            }
        }

        if(pos==-1){
            return;
        }

        for(int i=pos;i<len-1;i++){
            arr[i]=arr[i+1];
        }

        len--;
    }

    void clear(){

        len=0;
        cout<<"List cleared: \n";

        return ;
    }

    int get(int pos){ 


        start();

        return *(curr+pos-1);

    }

    void update(int pos, int nv){

        start();

        *(curr+pos-1)=nv;
    }

    void findx(int val){   
        
        start();

        for(int i=0;i<len;i++){
            if(*(curr+i)==val){
                cout<<*(curr+i)<<" found at position: "<<i+1<<endl;
            }
            return ;
        }
        cout<<"not found\n";
    }

    int length(){
        return len;
    }


    arra copy(arra t1){

        arra t2(t1.size);

        t2.len=t1.len;

        for(int i=0;i<t1.len;i++){
            t2.arr[i]=t1.arr[i];
        }

    return t2;
}
    void display(){

        for(int i=0;i<len;i++){
            cout<<arr[i]<<" ";
        }

        cout<<endl;
    }
    ~arra(){
    delete[] arr;
}
};
int main(){

    arra a1(10);

    // INSERT
    cout<<"--- INSERT ---\n";

    a1.insert(1,10);
    a1.insert(2,20);
    a1.insert(3,30);
    a1.insert(4,40);

    a1.display();


    // START
    cout<<"\n--- START ---\n";

    a1.start();
    cout<<"First element: "<<a1.get(1)<<endl;


    // NEXT
    cout<<"\n--- NEXT ---\n";

    a1.start();
    a1.next();
    cout<<"After next: "<<a1.get(2)<<endl;


    // BACK
    cout<<"\n--- BACK ---\n";

    a1.back();
    cout<<"After back: "<<a1.get(1)<<endl;


    // TAIL
    cout<<"\n--- TAIL ---\n";

    a1.tail();
    cout<<"Last element: "<<a1.get(4)<<endl;


    // GET
    cout<<"\n--- GET ---\n";

    cout<<"Element at position 2: "<<a1.get(2)<<endl;


    // UPDATE
    cout<<"\n--- UPDATE ---\n";

    a1.update(2,25);
    a1.display();


    // FIND
    cout<<"\n--- FIND ---\n";

    a1.findx(25);
    a1.findx(100);


    // LENGTH
    cout<<"\n--- LENGTH ---\n";

    cout<<"Length: "<<a1.length()<<endl;


    // REMOVE
    cout<<"\n--- REMOVE ---\n";

    a1.remove(25);
    a1.display();


    // COPY
    cout<<"\n--- COPY ---\n";

    arra a2 = a1.copy(a1);

    cout<<"Original: ";
    a1.display();

    cout<<"Copied: ";
    a2.display();


    // CLEAR
    cout<<"\n--- CLEAR ---\n";

    a1.clear();
    a1.display();

    cout<<"Length after clear: "<<a1.length()<<endl;


    // INSERT AFTER CLEAR
    cout<<"\n--- INSERT AFTER CLEAR ---\n";

    a1.insert(1,100);
    a1.insert(2,200);
    a1.display();


    // INVALID INSERT
    cout<<"\n--- INVALID INSERT ---\n";

    a1.insert(10,500);


    // INVALID REMOVE
    cout<<"\n--- INVALID REMOVE ---\n";

    a1.remove(999);


    // BACK AT START
    cout<<"\n--- INVALID BACK ---\n";

    a1.start();
    a1.back();


    return 0;
}