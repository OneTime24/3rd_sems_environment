


// #include <iostream>
// using namespace std;

// // class node{
    
// // }


// node* reverse(node *head){

//     node *curr=head;

//     node *next=nullptr;
//     node *prev=nullptr;

//     while(curr!=nullptr){
//         next=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=next;
//     }
//     head=prev;

//     return head;
// }

// bool ispalin(node *head)
// {
//     node *bfr = head;
//     node *afr = reverse(head);

//     while(bfr != nullptr)
//     {
//         if(bfr->data != afr->data)
//         {
//             return false;
//         }

//         bfr = bfr->next;
//         afr = afr->next;
//     }

//     return true;
// }

// int main(){

// }