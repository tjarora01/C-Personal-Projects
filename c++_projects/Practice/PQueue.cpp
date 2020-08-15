#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "PQueue.h"

/*
 * Class Priority Queue
 */

using namespace std;

/*
* Insert into Priority Queue
*/
void PQueue::push(void *item, int rank)
{
    node* temp = new node;
    temp->priority = rank;
    temp->data = item;
    temp->next = nullptr;
    /*
    temp = (node*) item;
    temp->priority = rank;
    temp->next = nullptr;
     */

    //if the list is empty, point fron and rear both to the new temp node created

    if (front == nullptr && rear == nullptr) {
        front = temp;
        rear = temp;
    }

    //if the list is not empty, link the last node to the new temp and point rear to temp

    rear->next = temp;
    rear = temp;
}

/*
 * Display first element in list
 */
void* PQueue::top()
{
    if(isEmpty()) {
        cout << "Queue is empty" << endl;
    }
    else {
        cout << front->priority << endl;
    }

    return front;
}
/*
 * Delete from Priority Queue
 */
void PQueue::pop()
{
    if(isEmpty()) {
        cout << "list is empty" << endl;
    }

    //if the list just has 1 element, just clear the 1st node
    if (front == rear) {
        front = rear = nullptr;
    }
        //if the list has multiple elements, assign temp to the 1st node and move front to the 2nd node. Then free temp.
    else {
        node* temp = front;
        front = front->next;
        free(temp);
    }

}

/*
 * Print Priority Queue
 */
void PQueue::display()
{

    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    }
    else {
        node* ptr = front;

        while (ptr->next != nullptr) {
            cout << ptr->priority << endl;
            cout << ptr->data << endl;

            ptr = ptr->next;
        }
    }

}

bool PQueue::isEmpty() {
    if (front == nullptr && rear == nullptr) {
        //cout << "isEmpty" << endl;
        return true;
    }
    else {
        //cout << "is NOT Empty" << endl;
        return false;
    }
}

node* PQueue::getFront() {
    cout << "front priority is " << front->priority << endl;
    return front;
}

node* PQueue::getRear() {
    cout << "rear priority is " << rear->priority << endl;
    return rear;
}
