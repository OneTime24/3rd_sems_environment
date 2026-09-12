#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;

    node(int val) {
        data = val;
        next = nullptr;
    }
};

class linkedl {

private:
    node* head;

public:

    linkedl() {
        head = nullptr;
    }

    void insert(int val) {

        node* newnode = new node(val);

        if (head == nullptr) {
            head = newnode;
            return;
        }

        node* curr = head;

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = newnode;
    }

    void remove(int x) {

        if (head == nullptr)
            return;

        if (head->data == x) {

            node* temp = head;
            head = head->next;

            delete temp;
            return;
        }
                node* curr = head;

        while (curr->next != nullptr) {

            if (curr->next->data == x) {

                node* temp = curr->next;

                curr->next = temp->next;

                delete temp;
                return;
            }

            curr = curr->next;
        }
    }

    void display() {

        if (head == nullptr) {
            cout << "EMPTY list\n";
            return;
        }

        node* curr = head;

        while (curr != nullptr) {

            cout << curr->data<<" ";
            curr = curr->next;
        }

        cout <<endl;
    }
};

int main() {

    cout<<"Enter number of devices connected: \n";

    int N;
    cin >> N;

    linkedl list;

    for (int i = 0; i < N; i++) {
        cout<<"Enter Node Value: "<<endl;
        int x; 
        cin >> x;

        list.insert(x);
    }

    cout<<"Enter number of faulty device: \n";
    int Q;
    cin >> Q;

    while (Q--) {
        cout<<"Enter faulty device value: "<<endl;
        int x;
        cin >> x;

        list.remove(x);
        list.display();
    }

    return 0;
}