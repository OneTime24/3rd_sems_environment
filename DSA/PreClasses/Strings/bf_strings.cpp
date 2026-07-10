

// just a rendom strings problem for resresh

#include <iostream>
#include <string>
using namespace std;


class detail{

    private:
     string name;
     int age;

     public:

     detail(){
        name="nill";
        age=-1;
     }
     detail(string s, int a):name(s),age(a){};


     
     void output(){
        cout<<"Name: "<<name<<"\nAge"<<age<<endl;
     }
};

int main(){

    detail std[5];

    for(int i=0;i<5;i++){
        std[i]={"Ali",0+i};
    }



    for(int i=0;i<5;i++){
        std[i].output();
    }


}