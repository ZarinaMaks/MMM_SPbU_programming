/*
(15 баллов)Дан массив, содержащий перестановку чисел от 0 до N. 
Посчитать амортизационную стоимость линейного поиска элемента со значением i.
*/

#include <iostream>
#include <cmath>
#include <locale>

using namespace std;

void Swap (int *A, int i, int j)
{
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    
}

bool Var (int *A, int n, int t)
{
    int j = n - 2;
    int k = n - 1;
    int q = j + 1; 
    int r = n - 1;
    
    while ( j != -1 && A[j] >= A[j+1] ) { j--; }
    while (A[j] >= A[k]) { k--; }
    Swap(A, j, k);
    
    while ( q < r ){ Swap( A, q++ , r-- ); }
    
    if ( j == -1)  { return false; }
    return true;
}

void Print (int *A, int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << endl;
    
}

bool LinearSearch (int*A, int*B, int n) {
    
    for (int i = 0; i < n; i++)
    {
    if (A[i] != B[i]) { return false; }
    return true;
        
    }
}

int main()
{
    int n, m;
    double Cost = 0;
    
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter element with number m = ";
    cin >> m;
    for (int i = 0; i < m; i++) {
        
        int *A = new int[n];
        int *B = new int[n];
        
        for (int i = 0; i < n; i++) { A[i] = i; }
        
        for (int i = 0; i < n; i++) { cin >> B[i]; }
        
        Cost++;
        
        if  (LinearSearch(A, B, n))
        {
            continue;
            
            while(Var(A, n, Cost)) {
            Cost++;
            if (LinearSearch(A, B, n)) break;
     }
     
     delete [] A;
     delete [] B;
     }
     
    Cost = Cost / m;
    cout << "The Amortization Cost is: " << Cost;
    return 0;
    }
    
    }
