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


    rectangle r[5];
    for(int i=0;i<5;i++){
        r[i].len=i;
        r[i].br=i+1;
    }


    for(int i=0;i<5;i++){
        cout<<"Area: "<<r[i].area()<<endl;
    }

}