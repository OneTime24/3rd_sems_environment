#include <iostream>

using namespace std;

struct rectangle{
    float len;
    float br;

    float area(){
        return len*br;
    }
};

int main(){


    // rectangle r[5];
    // for(int i=0;i<5;i++){
    //     r[i].len=i;
    //     r[i].br=i+1;
    // }


    // for(int i=0;i<5;i++){
    //     cout<<"Area: "<<r[i].area()<<endl;
    // }


    rectangle pt={10,20};
    cout<<"Area: "<<pt.area()<<endl;
    rectangle *p=new rectangle;
    p->len=20;
    p->br=20;
    cout<<"Area: "<<p->area()<<endl;
    delete p;
}