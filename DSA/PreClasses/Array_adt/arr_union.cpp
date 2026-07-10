#include <iostream>
using namespace std;

struct Array{
    int *ary;
    int leng;
    int size;
};

void disp(Array arr){
    cout << "\n----------------------\n";
    for(int i=0;i<arr.leng;i++){
        cout << arr.ary[i] << endl;
    }
    cout << "----------------------\n";
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

Array sort(Array arr){

    for(int i=0;i<arr.leng-1;i++){
        for(int j=0;j<arr.leng-i-1;j++){
            if(arr.ary[j]>arr.ary[j+1]){
                swap(&arr.ary[j],&arr.ary[j+1]);
            }
        }
    }

    return arr;
}

Array unio(Array arr1,Array arr2){

    int i=0,j=0,k=0;

    Array unio;
    unio.size=arr1.leng+arr2.leng;
    unio.ary=new int[unio.size];

    while(i<arr1.leng && j<arr2.leng){

        if(arr1.ary[i]<arr2.ary[j]){
            unio.ary[k++]=arr1.ary[i++];
        }
        else if(arr2.ary[j]<arr1.ary[i]){
            unio.ary[k++]=arr2.ary[j++];
        }
        else{
            unio.ary[k++]=arr1.ary[i];
            i++;
            j++;
        }
    }

    while(i<arr1.leng){
        unio.ary[k++]=arr1.ary[i++];
    }

    while(j<arr2.leng){
        unio.ary[k++]=arr2.ary[j++];
    }

    unio.leng=k;

    return unio;
}

Array differ(Array arr1,Array arr2){

    int i=0,j=0,k=0;

    Array dife;
    dife.size=arr1.leng;
    dife.ary=new int[dife.size];

    while(i<arr1.leng && j<arr2.leng){

        if(arr1.ary[i]<arr2.ary[j]){
            dife.ary[k++]=arr1.ary[i++];
        }
        else if(arr2.ary[j]<arr1.ary[i]){
            j++;
        }
        else{
            i++;
            j++;
        }
    }

    while(i<arr1.leng){
        dife.ary[k++]=arr1.ary[i++];
    }

    dife.leng=k;

    return dife;
}

Array intersec(Array arr1,Array arr2){

    int i=0,j=0,k=0;

    Array inter;
    inter.size=(arr1.leng<arr2.leng)?arr1.leng:arr2.leng;
    inter.ary=new int[inter.size];

    while(i<arr1.leng && j<arr2.leng){

        if(arr1.ary[i]<arr2.ary[j]){
            i++;
        }
        else if(arr2.ary[j]<arr1.ary[i]){
            j++;
        }
        else{
            inter.ary[k++]=arr1.ary[i];
            i++;
            j++;
        }
    }

    inter.leng=k;

    return inter;
}

int main(){

    Array arr;

    cout<<"Enter size of the array: ";
    cin>>arr.size;

    arr.ary=new int[arr.size];

    cout<<"Enter number of elements: ";
    cin>>arr.leng;

    for(int i=0;i<arr.leng;i++){
        cout<<"Enter values of array 1: ";
        cin>>arr.ary[i];
    }

    Array arr2;

    cout<<"Enter size of the array: ";
    cin>>arr2.size;

    arr2.ary=new int[arr2.size];

    cout<<"Enter number of elements: ";
    cin>>arr2.leng;

    for(int i=0;i<arr2.leng;i++){
        cout<<"Enter values of array 2: ";
        cin>>arr2.ary[i];
    }

    Array arr1_sort=sort(arr);
    Array arr2_sort=sort(arr2);

    cout<<"\nSorted Array 1";
    disp(arr1_sort);

    cout<<"\nSorted Array 2";
    disp(arr2_sort);

    cout<<"\nUnion";
    Array uni=unio(arr1_sort,arr2_sort);
    disp(uni);

    cout<<"\nIntersection";
    Array inter=intersec(arr1_sort,arr2_sort);
    disp(inter);

    cout<<"\nDifference (Array1 - Array2)";
    Array difer=differ(arr1_sort,arr2_sort);
    disp(difer);

    return 0;
}