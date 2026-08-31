#include <iostream>
using namespace std;

class arra {
private:
    int *arr;
    int *curr;
    int size;
    int len;

public:

    arra(int sz) {
        size = sz;
        arr = new int[size];
        curr = nullptr;
        len = 0;
    }

    ~arra() {
        delete[] arr;
    }

    void start() {
        curr = arr;
    }

    void tail() {
        curr = arr + len - 1;
    }

    void next() {
        if (curr < arr + len - 1)
            curr++;
    }

    void back() {
        if (curr > arr)
            curr--;
    }

    void append(int val) {
        if (len < size) {
            tail();
            next();
            *curr = val;
            len++;
        }
    }

    void insert(int pos, int val) {
        if (len >= size || pos < 0 || pos > len)
            return;

        tail();

        for (int i = len; i > pos; i--)
            *(arr + i) = *(arr + i - 1);

        start();

        for (int i = 0; i < pos; i++)
            next();

        *curr = val;
        len++;
    }

    void remove(int pos) {
        if (pos < 0 || pos >= len)
            return;

        start();

        for (int i = 0; i < pos; i++)
            next();

        for (int i = pos; i < len - 1; i++)
            *curr = *(curr + 1), next();

        len--;

        if (len > 0)
            tail();
        else
            curr = nullptr;
    }

    int get(int pos) {
        if (pos < 0 || pos >= len)
            return -1;

        start();

        for (int i = 0; i < pos; i++)
            next();

        return *curr;
    }

    void update(int pos, int val) {
        if (pos < 0 || pos >= len)
            return;

        start();

        for (int i = 0; i < pos; i++)
            next();

        *curr = val;
    }

    int find(int val) {
        if (len == 0)
            return -1;

        start();

        for (int i = 0; i < len; i++) {
            if (*curr == val)
                return i;

            next();
        }

        return -1;
    }

    int length() {
        return len;
    }

    void clear() {
        len = 0;
        curr = nullptr;
    }

    void copy(const arra &other) {
        if (size < other.len) {
            delete[] arr;
            size = other.size;
            arr = new int[size];
        }

        len = other.len;

        start();

        for (int i = 0; i < len; i++) {
            *curr = *(other.arr + i);
            next();
        }

        if (len > 0)
            tail();
    }

    void display() {
        if (len == 0) {
            cout << "List is empty\n";
            return;
        }

        start();

        for (int i = 0; i < len; i++) {
            cout << *curr << " ";
            next();
        }

        cout << endl;
    }
};

int main() {

    arra list(10);

    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);

    list.display();

    list.insert(2, 25);
    list.display();

    list.remove(1);
    list.display();

    cout << "Get: " << list.get(2) << endl;

    list.update(1, 100);
    list.display();

    cout << "Find 30: " << list.find(30) << endl;

    cout << "Length: " << list.length() << endl;

    list.clear();
    list.display();

    return 0;
}