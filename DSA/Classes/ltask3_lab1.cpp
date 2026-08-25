#include <iostream>
using namespace std;

int main() {
    int rgbVals[3] = {40, 90, 180};
    int* ptr = rgbVals;
    for (int i = 0; i < 3; i++)
        cout << "RGB Value " << i << ": " << *(ptr + i) << endl;
}