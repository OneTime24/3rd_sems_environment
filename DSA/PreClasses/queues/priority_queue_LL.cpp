#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insert(int x) {

    Node* t = new Node;
    t->data = x;
    t->next = nullptr;

    // Empty list or insert at front
    if (head == nullptr || x > head->data) {
        t->next = head;
        head = t;
        return;
    }

    Node* p = head;

    while (p->next != nullptr && p->next->data > x)
        p = p->next;

    t->next = p->next;
    p->next = t;
}

int deleteHighest() {

    if (head == nullptr) {
        cout << "Queue Empty\n";
        return -1;
    }

    Node* t = head;

    int x = t->data;

    head = head->next;

    delete t;

    return x;
}

void display() {

    Node* p = head;

    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }

    cout << endl;
}

int main() {

    insert(30);
    insert(10);
    insert(50);
    insert(20);
    insert(40);

    display();

    cout << "Deleted: " << deleteHighest() << endl;

    display();
}