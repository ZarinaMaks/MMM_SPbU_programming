/*(20 баллов) Реализовать структуру данных очередь с приоритетом с таймером и с помощью такой структуры данных эмулировать работу диспетчера задач.
 *1 - Highest Priority, 2 - Lower Priority, 3 - More Lower Priority etc.
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "Dispatcher.h"

using namespace std;
 
int main()
{
    int choice, item, Priority;
    PriorityQueue pq; 
    do
    {
        cout<<"1.Insert\n";
        cout<<"2.Display\n";
        cout<<"3.Quit\n";
        cout<<"Enter your choice : "; 
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Input the item value to be added in the queue : ";
            cin>>item;
            cout<<"Enter its Time-to-Solve : ";
            cin>>Priority;
            pq.Insert(item, Priority);
            break;
        case 2:
             pq.display();
            break;
        case 3:
        break;
        default :
            cout<<"Wrong choice\n";
        }
    }
    while(choice != 3);
    return 0;
}