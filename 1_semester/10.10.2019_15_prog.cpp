#include <iostream>
using namespace std;

int main() {
    
     int k=0; int n=0;
     cin >> k >> n;
     
     int A[k][n];
     double B[n];
     for(int i=0; i < n; i++){
         B[i]=0;
     }
     
     for(int i=0; i < k; i++){
         for(int j=0; j < n; j++){
             cin >> A[i][j];
         }
     }
     
     
     for(int j=0, i=0; (i<n)&&(j<n); ){
         if(A[0][i]==A[1][j]){
             B[k]=A[1][j];
             k++;
         }
         if(A[0][i]<A[1][j]){
             i++;
         } else{
             j++;
         }
     }
     
    bool flag=false;
    
    for(int l=0, i=2, j=0; (i<k)&&(j<n); i++){
        l=0;
        flag=false;
        for (; l<k; l++){
            j=0;
            for(; j<n; j++){
                if(B[l]==A[i][j]){
                    flag=true;
                }
                }
            if (flag==false){
                B[l]=0.1;
            }
    }
}

    for(int i=0; i<k; i++){
        if(B[i]!=0.1){
            cout << B[i] << endl;

        }
    };
    return 0;
}