

#include <iostream>

using namespace std;

class rect{
    private:
        int len;
        int bred;

    public:

        rect(){
            len=bred=0;
        }
        rect(int l, int b);

        int area();

        int peri();

        void changel(int l);
        void changeb(int b);
        void change(int l,int b);

};

rect::rect(int l,int b){
    len=l;
    bred=b;
}

int rect::area(){
    return len*bred;
}

int rect::peri(){
    return 2*(len+bred);
}

void rect::changeb(int b){
    bred=b;
}

void rect::changel(int l){
    len=l;
}

void rect::change(int l,int b){
    len=l;
    bred=b;
}



int main(){
    rect r1(2,2);
    cout<<r1.area();
    cout<<endl<<r1.peri()<<endl;

    r1.change(4,4);
    
    cout<<r1.area();
    cout<<endl<<r1.peri()<<endl;

    }