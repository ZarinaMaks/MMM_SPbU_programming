 /* (10 баллов)
 * Реализовать Stack целых чисел с операцией многократного извлечения(multipop)
 */

#include <iostream>
#include <stack> 
using namespace std;
 
   class stack {
	      public:
	        	stack(size_t size): top(0), data(new T[size]) {}
          bool empty() { return top == 0; }
          void push(T x) { data[top++] = x; }
	        	T pop() {
			          if (empty())
               throw invalid_argument("underflow"); 
             else
               return data[--top]; 
             }
          void multipop(size_t k) {
			       while (!empty() && k--)
			      	pop(); 
          ~stack() { delete [] data; }
       private:
          size_t top; 
		        T* data; 
         }

int main() {
  stack <int> steck;  // creating stack
  int i = 0;
 
  cout << "Enter 6 integer numbers: " << endl;
  while (i != 10) {
    int a;
    cin >> a; 
 
    steck.push(a);  // adding entered numbers
    i++;
  }
  
  if (steck.empty()) cout << "Stack is not empty";  // checking whether stack is empty
 
  cout << "Top stack element: " << steck.top() << endl; // display top element
  
  cout << "Let's delete top element " << endl;
  steck.pop();  // deleting top element
  cout << "Here is the new top element: " << steck.top(); 
  
  cout << "Let's delete k elements" << endl;
  cin >> size_k;
  steck.multipop(size_k); //deleting k elements
  cout << "Here is the new stack: " << steck();
  
  system("pause");
  return 0;
}
