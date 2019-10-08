//Напишите программу перебирающую все перестановки массива букв в лексикографическом порядке. Программа должна работать не более чем за O(n!*n) шагов. 
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
 
int main()
{
    string s = "cadb";
    sort(s.begin(), s.end());
    do
    {
        cout << s << endl;
    } while(next_permutation(s.begin(), s.end()));
}
