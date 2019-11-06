//Написать функцию сортировки массива, использующую указательную арифметику вместо обращения по индексам. 
#include <iostream>
using namespace std;

int bubblesort(int *arr,int k){
    int temp;
    int *i=arr+k;
    k=0;
    for(int *p=arr; p<(i-1); p++){
    for(int *q=arr; q<(i-k); q++){
        if((*q)>(*(q+1))){
            temp=*q;
            *q=*(q+1);
            *(q+1)=temp;
        }
        
    }
    k++;
    
}
}

int main() { 
    int n,x;
    cin >> n;
    int A[n];
    for(int i=0; i<n; cin>>A[i++]) {}
    int *p= A;
    x=*p;
    bubblesort(A,n);
    for(int i=0; i<n; cout <<" "<<A[i++]){}
    return 0;
    
}
