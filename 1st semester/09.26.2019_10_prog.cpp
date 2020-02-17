//Напишите программу перебирающую все перестановки массива букв в лексикографическом порядке. Программа должна работать не более чем за O(n!*n) шагов. 
#include <iostream>
#include <set>
#include <string>
#include <cstring>
using namespace std;

int main()
{
   char chars[] = "reowfdsgba";
   int size = sizeof(chars) / sizeof(chars[0]) - 1; 
   char temp; 
   int count = 0;
   // bubble sort
   for (int i = 0; i < size - 1; i++) {
      for (int j = 0; j < size - i - 1; j++) {
         if (chars[j] > chars[j + 1]) {
            temp = chars[j];
            chars[j] = chars[j + 1];
            chars[j + 1] = temp;
            ++count;
         }
      }
   }
   for (int i = 0; i < size; i++) {
      cout << chars[i] << " ";
   }
   cout << endl;
   return 0;
}
