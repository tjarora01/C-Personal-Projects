#include<stdio.h>
#include<iostream>
#include<math.h>
#include "stack.h"
#include "disc.h"

using namespace std;

Disc* a;
Disc* b;
Stack* t1 = new Stack();
Stack* t2 = new Stack();
Stack* t3 = new Stack();


void setStacks(int n) {
    int i;
    int x;

    for (i = n; i >= 1; i--)
    {
//d.setSize(i);
        Disc* d = new Disc(i);
        cout << d->toString() << endl;
        t1->push(d);
    }
}

void toh(int n, Stack* beg, Stack* aux, Stack* end) {

    if (n == 1) {

        //cout << "Move disk from pole " << beg << " to pole " << end << endl;
        end->push(beg->top());
        beg->pop();

    }
    else {
        toh(n - 1, beg, end, aux);
        toh(1, beg, aux, end);
        toh(n - 1, aux, beg, end);
    }
}

int main()
{
    int n;
    cout<<"enter the number of disksn";
    cin>>n;

    setStacks(n);

    toh(n, t1, t2, t3);

    cout << "The order of discs in t3 is: " << endl;
    t3->display();
    t1->empty();
    return 0;
}
