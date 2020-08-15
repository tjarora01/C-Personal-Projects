#include<stdio.h>
#include<iostream>
#include<math.h>
#include "stack.h"
#include "disc.h"
using namespace std;

Stack::Stack()
{

}
/*
Stack::~Stack()
{
	// delete data;
}
*/

void Stack::push(void* inData)
{
    node* temp = new node;
    Disc* letsGo = (Disc*) inData;

    temp->data = letsGo->getSize();
    temp->pNext = pTop;
    pTop = temp;
}

void* Stack::pop()
{
    node* temp;
    node* ret;

    if (pTop == nullptr) {
        return nullptr;
    }

    temp = pTop;
    ret = pTop;

    pTop = pTop->pNext;
    free(temp);

    return ret;
}

void* Stack::top()
{
    if (empty()) {
        cout << "stack is empty";
    }

    return pTop;
}

bool Stack::empty()
{
    if (pTop == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

void Stack::display()
{
    node *p1;
    p1 = pTop;

    while (p1 != nullptr)
    {
        cout << "the disc is " << p1->data << endl;

        p1 = p1->pNext;
    }
    cout<<endl;

}