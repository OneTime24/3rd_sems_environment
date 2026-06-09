

#include <iostream>
using namespace std;

template<class T>
class rect{
    private:
        T len;
        T bred;
    public:

    rect(){
        len=bred=0;
    }
    rect(T a,T b);

    T area();
    T peri();

    void change(T l,T b);
};

template<class T>

rect<T>::rect(T a, T b){
    len=a;
    bred=b;
}

template<class T>

T rect<T>::area(){
    return len*bred;
}

template<class T>
T rect<T>::peri(){
    return 2*(len+bred);
}

template<class T>
void rect<T>::change(T l, T b){

    len=l;
    bred=b;
}

int main(){

    rect<int> r1(2,2);
    cout<<r1.area()<<endl;
    cout<<r1.peri()<<endl;

    r1.change(4,4);
    cout<<r1.area()<<endl;
    cout<<r1.peri()<<endl;

    cout<<"-----------------\n";


    rect<float> r2(2,2);
    cout<<r2.area()<<endl;
    cout<<r2.peri()<<endl;

    r2.change(4,4);
    cout<<r2.area()<<endl;
    cout<<r2.peri()<<endl;

}