#include <iostream>
#include <cstdlib>


class Node
{
public:
    Node* next;
    int data;
};

Node *head = NULL;

using namespace std;

class LinkedList
{
public:
    int length;
    Node* head;

    LinkedList();
    ~LinkedList();
    void add(int data);
    Node* find(int data) const;
    void remove(Node* data);
    void remove1(int data);
    int sum();
    void display();
};

// Initialize the lists management information
LinkedList::LinkedList(){
    this->length = 0;// Your code here
    this->head = NULL; // Your code here
}

// Clear the list management information and release all allocated Nodes
LinkedList::~LinkedList(){
    Node* current = this->head;
    while(current){
        this->head = current->next;
        this->length -= 1;
        delete current;
        current = this->head;
    }
    std::cout << "LIST DELETED: " << this->length << std::endl;
}

// Add a new node that contains 'data'
void LinkedList::add(int data){

    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        return;
    }
    Node *cur = head;
    while(cur) {
        if(cur->next == NULL) {
            cur->next = newNode;
            this->length = length +1;
            return;
        }
        cur = cur->next;
    }

}

struct Node *searchNode(int n) {
    //cout << "H1 = " << endl;
    if(head == NULL) return head;
    //cout << "H2 = " << endl;
    Node *cur = head;
    Node *prev = head;
    while(cur) {
        if(cur->data == n) return cur;
        if(cur->data > n) return prev;
        prev = cur;
        cur = cur->next;
    }
}

Node* LinkedList::find(int value) const
{
    for (Node* node_ptr=this->head; node_ptr != NULL; node_ptr=node_ptr->next) { if (node_ptr->data == value) { return node_ptr; }
    }
    return NULL;
}

void LinkedList::remove(Node *target_node_ptr) {
    Node *prev_ptr = NULL;
    Node *node_ptr;
    for (node_ptr = this->head;
         node_ptr != NULL && node_ptr != target_node_ptr; node_ptr = node_ptr->next) { prev_ptr = node_ptr; }
    if (node_ptr == NULL) { throw target_node_ptr; }
    else if (prev_ptr == NULL) {
        this->head = target_node_ptr->next;
        delete target_node_ptr;
        //this->length = length - 1;
    } else {
        prev_ptr->next = target_node_ptr->next;
        delete target_node_ptr;
        //this->length = length - 1;
    }
}


// Locate the node that contains 'val' in the list and remove the node
void LinkedList::remove1(int val){
    Node *ptr = searchNode(val);
    //Node *ptr = search_item(val);
    if(ptr == NULL)
        cout << "No node with data = " << val << endl;
    if(ptr == head) {
        head = ptr->next;
        return;
    }
    Node *cur = head;
    Node *prev = head;

    while(cur) {
        if(cur == ptr) {
            prev->next = cur->next;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}





// Sum all the integer data elements in the list
int LinkedList::sum(){

    struct Node *list = head;
    int sum = 0;

    while(list) {
        cout << list->data <<" ";
        sum = sum + list->data;
        list = list->next;
    }
    cout << endl;
    return sum;
}

// print the entire list's data
void LinkedList::display(){
    Node* head = this->head;
    int i = 1;
    while(head){
        std::cout << i << ": " << head->data << std::endl;
        head = head->next;
        i++;
    }
    this->length =i-1;
}


// Main performs various list operations and reports results
int main(int argc, char const *argv[])
{
    LinkedList* list = new LinkedList();
    int j = 49;
    int sum = 0;
    int testSum = 0;

    // Install inital values in list
    for (int i = 0; i < 50; i += 2)
    {
        testSum = testSum + i + j;
        list->add(i+1);
        list->add(j-1);
        j -= 2;
    }

    list->display();
    std::cout << "List initial sum: " << testSum << std::endl;
    sum = list->sum();
    std::cout << "List initial sum: " << sum << std::endl;
    if (sum != testSum)
    {
        std::cout << "Ooops!  Initialization failed" << std::endl;
        return(1);
    }

    // Test 1
    std::cout << std::endl << "- - - -" << std::endl;
    list->remove(list->find(2));

    //delete_position(2);
    list->display();
    std::cout << "List Length: " << list->length << std::endl;
    sum = list->sum();
    std::cout << "sum 1: " << sum << std::endl;

    // Test 2
    std::cout << std::endl << "- - - -" << std::endl;
    for (int i = 10; i < 20; i++)
    {
        list->remove(list->find(i));
        //list->remove(i);
    }
    list->display();
    std::cout << "List Length: " << list->length << std::endl;
    sum = list->sum();
    std::cout << "sum 2: " << sum << std::endl;

    delete list;
    return 0;
}
