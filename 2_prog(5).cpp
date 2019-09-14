#include <iostream>
using namespace std;

 int supfunction(int n, int x)
 {
 switch(n)
 {
 case 0: return (x+1);
 case 1: return x;
 case 2: return 0;
 case 3: return 1;
 default: return 2;
 }
 }
 
 int main(int n, int x, int y) //функция Аккермана
 {
 int z;
 if(n==0||y==0)
 z=supfunction(n, x);
 else
 {
 z=main(n, x, y-1);
 z=main(n-1, z, x);
 }
 return z;
 }