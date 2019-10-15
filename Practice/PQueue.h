struct node
{
    int priority;
    void* data;
    node* next;
};

struct yeah
{
    int x = 6;
    int y = 7;
};


class PQueue
{

private:
    node* front;
    node* rear;

public:

    PQueue()
    {
        front = nullptr;
        rear = nullptr;
    }

    void push(void *item, int priority);
    void* top();
    void pop();
    void display();
    bool isEmpty();
    node* getFront();
    node* getRear();


};
