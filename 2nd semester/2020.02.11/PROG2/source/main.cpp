#include <iostream>
#include <stack> 
using namespace std;
 
int main() {
    stack <char> bstack; 
    cout << "Enter even number of elements:"<< endl;
    int n;
    cin >> n;
    
    string a;
    cout << "Enter the first element: " << endl;
    cin >> a[0];
    if ( (a[0]=='{') || (a[0]=='(') ) { bstack.push(a[0]); }
        else { cout << "Wrong brackets combination" << endl; }
        
    cout << "Enter other elements: " << endl;
    
    for (int i=1; i < n; i++) {
        cin >> a[i];
        if ( (a[i]=='{') || (a[i]=='(') ) { bstack.push(a[i]); }
        
      /*  if (( (a[i]==')') && (bstack.top()=='{') ) || ( (a[i]==')') && (bstack.top()=='{') )) {
          cout << "Wrong brackets combination" << endl;
        } */
        if (( (a[i]=='}') && (bstack.top()=='{') ) || ( (a[i]==')') && (bstack.top()=='(') )) {bstack.pop();}
        else {cout << "Wrong brackets combination" << endl;}
    }
    
            
        if (bstack.empty() == true) {
          cout << "Correct brackets combination" << endl;
        }
        else {
          cout << "Wrong brackets combination" << endl;
        }
      system("pause");
      return 0;
}
