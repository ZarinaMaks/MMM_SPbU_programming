#include "Dispatcher.h" 
 
PriorityQueue::PriorityQueue() {
            front = NULL;
        }
        
//Insert into PriorityQueue
void PriorityQueue::Insert(int item, int Priority) {
            Node *tmp, *q;
            tmp = new Node;
            tmp->Info = item;
            tmp->Priority = Priority;
            if (front == NULL || Priority < front->Priority)
            {
                tmp->link = front;
                front = tmp;
            }
            else
            {
                q = front;
                
                while (q->link != NULL && q->link->Priority <= Priority)
                    q=q->link;
                tmp->link = q->link;
                q->link = tmp;
            }
        }
        
        
//Display PriorityQueue
void PriorityQueue::display() {
            Node *ptr;
            ptr = front;
            if (front == NULL)
                cout<<"Queue is empty\n";
            else
            {	cout<<"Queue is :\n";
                cout<<"Priority       Item\n";
                while(ptr != NULL)
                {
                    cout<<ptr->Priority<<"                 "<<ptr->Info<<endl;
                    ptr = ptr->link;
                }
            }
        }