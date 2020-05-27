#include <iostream>
using namespace std;

// Node declaration
struct Node
{
    int Priority;
    int Info;
    struct Node *link;
};

//PriorityQueue declaration
class PriorityQueue
{
private:
    Node *front;

public:

    PriorityQueue();
    void Insert(int item, int Priority);
    void display();
};