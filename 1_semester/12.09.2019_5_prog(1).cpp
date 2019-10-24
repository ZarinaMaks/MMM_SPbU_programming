//С СОЗДАНИЕМ ВСПОМОГАТЕЛЬНОГО МАССИВА
//Написать функцию удаляющую из целочисленного массива все четные элементы. Гарантируется, что в массиве есть хотя бы один нечетный элемент
#include <iostream>
using namespace std;

int main () {
    
int j=0;
int k=0;
int n=5;
int A[n];

for (int i=0; i<n ; i++){
    if (A[i]%2==1) {
       k++;
    };
}    

int B[k];

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
