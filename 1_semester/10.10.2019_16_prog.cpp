//Реализовать timsort без использования дополнительной памяти.
#include <iostream>
using namespace std;

void mergesort(int* a1, int* a2, int* b1, int* b2)
{
    int temp=0;
    do
    {
        if (*a1>*b1)
        {
            temp=*b1;
            for (int*p=b1; p!=a1; p--)
            {
                *p=*(p-1);
            }
            *a1=temp;
            a1+=1; a2+=1; b1+=1;
        }
        else
        {
            a1+=1;
        }
    }
    while (a2!=b2 && a1!=b1);
}

int getmin(int n)
{
    int r=0;
    while (n>=64)
    {
        r|=n&1;
        n>>=1;
    }
    return n+r;
}

void insertionsort(int* a, int n)
{
    int base=0, temp=0, k=0;
    while (base < n-1)
    {
        temp=a[base+1];
        k=0;
        while (temp > a[k])
        {
            k+=1;
        }
        for (int i=base+1; i>k; i--)
        {
            a[i] = a[i-1];
        }
        a[k]=temp;
        base+=1;
    }
}

void timsort(int* a1, int n, int min)
{
    if (n>min)
    {
        int n1,n2;
        if (n%2==0)
        {
            n1=n/2;
            n2=n1;
        }
        else
        {
            n1=n/2;
            n2=n1+1;
        }
        timsort(a1, n1, min);
        timsort(a1+n1, n2, min);
        mergesort(a1,a1+n1-1, a1+n1, a1+n-1);
    }
    else
    {
        insertionsort(a1,n);
    }
}

void in_array(int* a, int n)	
{
    cout<<"array before: ";
    for (int i=0; i<n; cin >> a[i++]);
}

void out_array(int* a, int n)
{
    cout << "array after  : ";
    for (int i=0; i<n; cout << a[i++] << " ");
    cout << endl;
}

int main()
{
    int n = 0;
    cout << "chislo elementov: ";
    cin >> n;
    if (n > 0)
    {
        int* mas = new int[n];
        in_array(mas,n);
        timsort(mas,n, getmin(n)); 
        out_array(mas,n);
        delete[] mas;
    }
    else
    {
        cout << "Incorrect" << endl;
    }
    return 0;
}