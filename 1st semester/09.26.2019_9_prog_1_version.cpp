//Напишите эффективную программу, находящую все числа длины n являющиеся палиндромами. В комментариях напишите, почему перебор - эффективный
//Перебор эффективный, поскольку перебирается только левая часть палиндрома ([n/2] чисел), все остальное просто копируется в обратном порядке

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, a, b, k;
    cin >> n;
    a=1;
    k=n/2;
    for(int i=0; i < k-1; i++){
        a=a*10;
    }
    cout << a << endl;
    b=a;
    if (n==1){
        cout << 1 << endl << 2 << endl << 3 << endl << 4 << endl << 5 << endl << 6 << endl << 7 << endl << 8 << endl << 9;
    }
    if ((n%2==0)){for (; b<(a*10); b++) {
        cout << b;
        for(int c=b; c!=0; c=c/10){
            cout << (c%10);
        }
        cout << endl;
    }
}
 else if(n > 1){
    for (; b<(a*10); b++){
    for (int i=0; i<10; i++){
        cout << b << i;
        for (int c=b; c!=0; c=c/10){
            cout << (c%10);
        }
    cout << endl;
    }
}
return 0;
}
}
