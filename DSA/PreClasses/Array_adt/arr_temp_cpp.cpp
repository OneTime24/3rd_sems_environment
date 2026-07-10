#include <iostream>
using namespace std;

template <class T>
class Array
{
private:
    T *ary;
    int leng;
    int size;

public:
    // Default Constructor
    Array()
    {
        size = 10;
        leng = 0;
        ary = new T[size];
    }

    // Parameterized Constructor
    Array(int sz)
    {
        size = sz;
        leng = 0;
        ary = new T[size];
    }

    // Destructor
    ~Array()
    {
        delete[] ary;
    }

    // Add element at the end
    void add(T x)
    {
        if (leng < size)
        {
            ary[leng++] = x;
        }
        else
        {
            cout << "Array is full!\n";
        }
    }

    // Insert at a given index
    void insert(int ind, T x)
    {
        if (ind >= 0 && ind <= leng && leng < size)
        {
            for (int i = leng; i > ind; i--)
            {
                ary[i] = ary[i - 1];
            }

            ary[ind] = x;
            leng++;
        }
        else
        {
            cout << "Invalid index or array is full!\n";
        }
    }

    // Delete element at a given index
    void delet(int ind)
    {
        if (ind >= 0 && ind < leng)
        {
            for (int i = ind; i < leng - 1; i++)
            {
                ary[i] = ary[i + 1];
            }

            leng--;
        }
        else
        {
            cout << "Invalid index!\n";
        }
    }

    // Display array
    void display()
    {
        cout << "\nArray Elements:\n";
        for (int i = 0; i < leng; i++)
        {
            cout << ary[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Array<int> arr(10);

    arr.add(10);
    arr.add(50);
    arr.add(20);

    arr.insert(1, 30);

    arr.delet(0);

    arr.display();

    return 0;
}