#include <iostream>
using namespace std;

int findMax(int* start, int* end) {
    if (start == end)
        return -1;

    int maxVal = *start;
    int* current = start + 1;

    while (current != end) {
        if (*current > maxVal)
            maxVal = *current;

        current++;
    }

    return maxVal;
}

int main() {
    int data[] = {19, 11, 4};

    int* start = data;
    int* end = data + 3;

    int result = findMax(start, end);

    cout << "Maximum value: " << result << endl;

    return 0;
}