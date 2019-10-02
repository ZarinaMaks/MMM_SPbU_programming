//В ОДНОМ МАССИВЕ
//Написать функцию удаляющую из целочисленного массива все четные элементы. Гарантируется, что в массиве есть хотя бы один нечетный элемент. 
#include <iostream>
using namespace std;

void rplc(int* arr, int n){
    int i, j = n - 1;
    for(i = 0; i < n; i++){
        if(i == j){
            if(arr[i] % 2 == 1)
                arr[i] = 0;
            break;
        }
        if(arr[i] % 2 == 1){
            while(arr[j] % 2 == 1){
                arr[j] = 0;
                j--;
            }
            arr[i] = arr[j];
            arr[j] = 0;
            j--;
        }
    }
}

int main() {
    int n, i;
    cin >>n;
    int *a = new int[n];
    for(i = 0; i < n; i++)
        cin >>a[i];


    rplc(a, n);
    for(i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
