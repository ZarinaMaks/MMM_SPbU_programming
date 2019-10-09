//Напишите эффективную программу, находящую все числа длины n являющиеся палиндромами. 
#include <iostream>
using namespace std;
void Swap(int *a, int i, int j)
{
  int s = a[i];
  a[i] = a[j];
  a[j] = s;
}
bool NextSet(int *a, int n)
{
  int j = n - 2;
  while (j != -1 && a[j] >= a[j + 1]) j--;
  if (j == -1)
    return false; 
  int k = n - 1;
  while (a[j] >= a[k]) k--;
  Swap(a, j, k);
  int l = j + 1, r = n - 1; 
  while (l<r)
    Swap(a, l++, r--);
  return true;
}
void Print(int *a, int n, int x)  
{
  static int num = 1; 
  cout.width(3); 
  cout << num++ << ": ";
  for (int i = 0; i < x; i++)
    cout << a[i] << " ";
  for (int j = x-1; j > -1; j--)
    cout << a[j] << " ";
  cout << endl;
}
int main() 
{
  int n, *a, x;
  cout << "vvedite chetnoe N = ";
  cin >> x;
  n = x;
  a = new int[n];
  for (int i = 0; i < 9; i++)
    a[i] = i + 1;
  Print(a, n, x);
  while (NextSet(a, n))
    Print(a, n, x);
  cin.get(); cin.get();
  return 0;
}
