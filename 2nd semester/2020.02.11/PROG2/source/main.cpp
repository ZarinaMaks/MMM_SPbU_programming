/* (10 баллов)
 * С помощью <stack> из STL написать программу для проверки корректности скобочной последовательности. 
 * Используются скобки “{“, “}”, “(”, “)”
 */
 
#include <iostream>
#include <stack> 
using namespace std;
 
int main() {
    stack <char> bstack; 
    cout << "Enter even number of elements:"<< endl;
    int n;
    cin >> n;
    int i = 0;
    
    string a;
    cout << "Enter the first element: " << endl;
    cin >> a[0];
    if ( (a[i]=='{') || (a[i]=='(') ) { bstack.push(a[i]); }
        else { cout << "Wrong brackets combination" << endl; }
    
    
    for (int i=1; i < n; i++) {
        cin >> a;
        if ( (a[i]=='{') || (a[i]=='(') ) {
          bstack.push(a[i]);
        }
        else
        if (( (a[i]==')') && (bstack.top()=='{') ) || ( (a[i]==')') && (bstack.top()=='{') ) || (bstack.empty() == true)) {
          cout << "Wrong brackets combination" << endl;
        }
        else {bstack.pop();}
        
        if (bstack.empty() == true) {
          cout << "Correct brackets combination" << endl;
        }
        else {
          cout << "Wrong brackets combination" << endl;
        }
    }
      system("pause");
      return 0;
}
