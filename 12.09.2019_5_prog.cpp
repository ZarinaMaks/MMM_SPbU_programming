#include <iostream>
using namespace std;

//I guess you expected us to do this exercise without creating a new array, but it hadn't been specified explicitly.

int main () {
    
int j=0;
int n=5;
int A[n];
int B[n];

for (int i=0; i<n ; i++){
    cin >> A[i];
}
for (int i=0; i<n ; i++) {
if (A[i] % 2 == 1) {
   B[j]=A[i]; 
   cout << B[j];
   j++;
}
}

return 0;
}