 /* (10 баллов)
 * Реализовать Stack целых чисел с операцией многократного извлечения(multipop)
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

class stack
{
    int sp;
    char mass[100000];

public:
    stack()
    { sp = 0;}

    void pop();
    void multipop(int k);
    void push(char x);
    void clear();
    int top();
    bool empty();
};

int main()
{
    stack multistack;
    int i = 0;
    cout << "Enter 10 integer numbers: " << endl;

  while (i != 11) {
    int a;
    cin >> a; 
    multistack.push(a);
    i++;
  }
  
  int k = 0;
  cout << "Enter number of deleting elements k = " << endl;
  cin >> k;
  
  multistack.multipop(k);
  cout << "Here is the new top element: " << multistack.top(); 
  
    return 0;
}

bool stack::empty()
{
    if (sp == 0)
        return 1;
    else
        return 0;
}

void stack::clear(){ sp = 0;}

void stack::push(char x) { mass[sp++] = x;}

void stack::pop() { sp--;}

void stack::multipop(int k) {
    for ( int j = 0; j < k; j++)
        sp--;
}

int stack::top() {return (mass[sp - 1]);}
