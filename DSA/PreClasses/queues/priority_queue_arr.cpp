#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int arr[100];
    int n;

public:
    PriorityQueue() {
        n = 0;
    }

    void insert(int x) {
        arr[n++] = x;
    }

    int deleteMax() {
        if (n == 0) {
            cout << "Queue Empty\n";
            return -1;
        }

        int maxIndex = 0;

        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        int x = arr[maxIndex];

        // Replace with last element
        arr[maxIndex] = arr[n - 1];
        n--;

        return x;
    }

    void display() {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {

    PriorityQueue pq;

    pq.insert(30);
    pq.insert(10);
    pq.insert(50);
    pq.insert(20);

    pq.display();

    cout << "Deleted: " << pq.deleteMax() << endl;

    pq.display();
}