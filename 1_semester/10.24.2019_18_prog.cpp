// Написать программу поиска k-ой порядковой статистики, основанный на Qsort
#include <iostream>
using namespace std;

long long ksort(int l,int r,int k) {
    long long arr[10];
        for (int i = 0; i < 10; i++) {
            cout << "[" << i + 1 << "]" << ": ";
            cin >> arr[i];
        }
     long long x = arr[(l+r) / 2];
     int i=l,j=r;
     while(i<=j) { 
         while(arr[i] < x) i++; 
         while(arr[j] > x) j--;
         if(i<=j) { 
             swap(arr[i],arr[j]);
             i++; j--; 
         } 
     } 
     if(l<=k && k<=j) 
     return ksort(l,j,k); 
     if( i<=k && k<=r) 
     return ksort(i,r,k); 
     return arr[k]; 
}

int main()
{
    int l, r, k;
    cin >> l >> r >> k;
    cout << ksort (l, r, k);
    return 0;
}
