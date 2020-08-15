#include <iostream>
using namespace std;

void testArr(int arr[]) {
    arr[0] = 1;
}

int main() {
    cout << "yes" << endl;
    int yes[] = {5,6,7};
    int* arr = yes;

    testArr(yes);

    return 0;
}



