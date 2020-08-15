#include <iostream>
using namespace std;


void basicPointers() {
    char x = 'c';

    void* ptr = &x;

    cout << ptr << endl;
};

int main() {

    basicPointers();
    return 0;
}