//Реализовать умножение Карацубы для длинной арифметики
#include <iostream>
#include <cstring>
#include <cmath>
typedef long long int bigint;
using namespace std;

struct long_value{
    int length;
    int *values;
};

int strl(char*_s){
    int i=0;
    for(;*_s; ++_s, i++);
    return i;
}

long_value sum(long_value A, long_value B){ 
    long_value product;
    product.length=A.length+1;
    product.values = new int[product.length]{0};
    for(int i=0;i<A.length;i++){
        if(i<B.length){
            product.values[i]=A.values[i]+B.values[i];
        }else{
            product.values[i]=A.values[i];
        }
    }
    int i=product.length;
    for(;product.values[i-1]==0;i--);
    product.length=i;
    return product;
}

void normalize(long_value &C){         
    for(int i=0;i<C.length-1;i++){
        
        if(C.values[i]>=10){
            C.values[i+1]+=C.values[i]/10;
            C.values[i]=C.values[i]%10;
        }else if(C.values[i]<0){
            C.values[i+1]-=abs(C.values[i]/10)+1;
            C.values[i]+=(abs(C.values[i]/10)+1)*10;
        }
    }
    int i = C.length;
    for(;C.values[i-1]==0;i--);
    C.length=i;
}

long_value &sub(long_value &a, long_value b) { 
  for (int i = 0; i < b.length; ++i)
    a.values[i] -= b.values[i];
  return a;
}
istream& operator>>(istream& in, long_value& A){
    char num[256];
    in.getline(num,256);
    A.length=strl(num);
    A.values = new int[strl(num)];
    for(int i=strl(num)-1;i>=0;i--){
        A.values[i]=num[i]-'0';
    }
    return in;
}
ostream& operator<<(ostream& os,const long_value& A){
    for(int i=A.length-1;i>=0;i--){
        os<<A.values[i];
    }
    return os;
}
long_value karatsuba(long_value a,long_value b){ 
    long_value product;
    product.length=a.length+b.length;
    product.values = new int[product.length]{0};
    if(a.length<=2){
        for(int i = 0 ; i < a.length; i++){
            for(int j = 0; j < b.length; j++){
                product.values[i+j]+=a.values[i]*b.values[j];
            }
        }
    }
    else {
        int lengthof;
        long_value a1; 
        a1.values = a.values;
        a1.length=(a.length + 1) / 2;
        long_value a2; 
        a2.values = a.values + a1.length;
        a2.length = a.length/2;
        
        long_value b1; 
        b1.values = b.values;
        b1.length=(a.length + 1) / 2;
        long_value b2; 
        b2.values = b.values + b1.length;
        b2.length = b.length/2;
        long_value sum_A = sum(a1, a2); 
        normalize(sum_A);
        long_value sum_B = sum(b1, b2); 
        normalize(sum_B);
        long_value product_of_sums_of_parts = karatsuba(sum_A, sum_B); 
        long_value product_of_first_parts = karatsuba(a1, b1);
        long_value product_of_second_parts = karatsuba(a2, b2);
        long_value SMP = sub(sub(product_of_sums_of_parts,product_of_first_parts),product_of_second_parts);
        memcpy(product.values,product_of_first_parts.values,product_of_first_parts.length*lengthof);
        memcpy(product.values+product_of_first_parts.length+1,product_of_second_parts.values,product_of_second_parts.length*lengthof);
       
        for(int i = 0; i < SMP.length; i++){
            product.values[a1.length+i]+=SMP.values[i];
        }
        delete [] sum_A.values;
        delete [] sum_B.values;
        delete [] product_of_sums_of_parts.values;
        delete [] product_of_first_parts.values;
        delete [] product_of_second_parts.values;
    }
    normalize(product);
    return product;
}


int main()
{
    long_value number1;
    cin >> number1;
    long_value number2;
    cin >> number2;
    cout << karatsuba(number1, number2) << endl;
    return 0;
}
