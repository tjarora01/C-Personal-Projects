#include <iostream>
#include "PQueue.h"

using namespace std;

int main(){

    yeah* add = new yeah;
    yeah* add2 = new yeah;
    add2->x = 7;
    PQueue* t1 = new PQueue();

    t1->push(add, 5);
    t1->push(add2, 190);
    t1->push(add2, 270);
    t1->top();
    t1->pop();
    t1->top();

    if (t1->isEmpty() == true) {
        cout << "it is empty" << endl;
    }
    else {
        cout << "not empty" << endl;
    }
    t1->display();

    /*
    node* x = t1->getFront()->next->next;
    cout << x->priority << endl;

    if (x->next == nullptr) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }

    */
    return 0;
}

