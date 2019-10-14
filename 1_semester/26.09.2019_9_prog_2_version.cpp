//Напишите эффективную программу, находящую все числа длины n являющиеся палиндромами. В комментариях напишите, почему перебор - эффективный
//Перебор эффективный, поскольку не использует лишних массивов для хранения палиндромов, а печатает комбинации чисел через рекурсивное дерево

#include<bits/stdc++.h>  
using namespace std;  
  
void comb(int arr[], int data[],  
                    int start, int end,  
                    int index, int r);  
  
 
void print(int arr[], int n, int r)  
{  
    int data[r];  
    comb(arr, data, 0, n-1, 0, r);  
}  

void comb(int arr[], int data[],  
                    int start, int end,  
                    int index, int r)  
{  
    
    if (index == r)  
    {  
        for (int j = 0; j < r; j++)  
            cout << data[j] << " ";  
        
        for (int j = r-1; j > -1; j--)  
            cout << data[j] << " "; 
            cout << endl;
            
        return;  
    }  
for (int i = start; i <= end &&  
        end - i + 1 >= r - index; i++)  
    {  
        data[index] = arr[i];  
        comb(arr, data, i+1,  
                        end, index+1, r);  
    }  
}  
  
int main()  
{  
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int r, x;
    cout << "vvedite chetnoe N=";
    cin >> x;
    r=x/2;
    int n = sizeof(arr)/sizeof(arr[0]);  
    print(arr, n, r);  
}  
  
