#include <iostream>
#include <chrono> 
using namespace std;
using namespace chrono;

int main () {
int A[1000];
int s=0;
 // Get starting timepoint 
    auto start = high_resolution_clock::now();
for (int i=0; i<1000; i++) {
    s+=A[i];
}
 // Get ending timepoint 
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<nanoseconds>(stop - start); 
  
    cout << "Time taken by function: "
         << duration.count() << " nanoseconds" << endl; 
return 0;
}