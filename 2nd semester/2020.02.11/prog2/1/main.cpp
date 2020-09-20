/* (10 баллов) 
 * С помощью <stack> из STL написать программу для проверки корректности скобочной последовательности. 
 * Используются скобки “{“, “}”, “(”, “)”
 */

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<char> bstack;
    int brackets_num = 0;
    string a;

    cout << "Enter EVEN number of elements:"<< endl;
    cin >> brackets_num;
    if (brackets_num % 2 = 1) { cout << "please enter EVEN number" << endl; }
    
    cout << "Enter the first element: " << endl;
    cin >> a[0];
   
    if ( a[0] == '{' || a[0] == '(' ) {
        cout << "Wrong brackets combination" << endl; 
        return 0;   
    }
    bstack.push(a[0]);
        
    cout << "Enter other elements: " << endl;
    
    for (int i = 1; i < brackets_num; i++) {
        cin >> a[i];
        if ( a[i] == '}' || a[i] == ')' ) {
            bstack.push(a[i]);
            continue;
        }
        if ( (a[i] == '{') && (bstack.top() != '}') || (a[i] == '(') && (bstack.top() != ')')) {
            cout << "Found mismatch: input elem = " << a[i] << ", stack top = " << bstack.top() << endl;
            break;
        } 
        bstack.pop();  
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

