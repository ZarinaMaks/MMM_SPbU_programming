//Написать функцию сортировки массива, использующую указательную арифметику вместо обращения по индексам. 
#include <iostream>
#include <string>
using namespace std;

int sort(int *array,int k) {
int t=0; k=0;
int *i=array+k;
for(int *x=array; x< i-1 ; x++) {
   for(int *y=array; y< i-k ; y++) {
      if(*y>*(y+1)) {
          t=*y;
          *y=*(y+1);
          *(y+1)=t; }
   }
        k++; 
}
}

int main() { 
  int n,z;
  cin >> n;
  int A[n];
  for(int i=0; i<n; cin >> A[i++]){}
  int *x= A;
  z=*x;
  sort(A,n);
  for(int i=0; i<n; cout << " " << A[i++]){}
  return 0;
}

