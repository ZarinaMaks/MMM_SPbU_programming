//Реализовать умножение Карацубы для длинной арифметики
#include <cstring>
#include <iostream>
using namespace std;
 
#define BASE 10 
#define MIN_LENGTH_FOR_KARATSUBA 4 
typedef int digit;
typedef unsigned long int size_length; 
 
using namespace std;
 
struct long_value { 
  digit *values; 
  size_length length; 
};
 
long_value sum(long_value a, long_value b) {
  long_value s;
  s.length = a.length + 1;
  s.values = new digit[s.length];
 
  s.values[a.length - 1] = a.values[a.length - 1];
  s.values[a.length] = 0;
  for (size_length i = 0; i < b.length; ++i)
    s.values[i] = a.values[i] + b.values[i];
  return s;
}
 
long_value &sub(long_value &a, long_value b) {
  for (size_length i = 0; i < b.length; ++i)
    a.values[i] -= b.values[i];
  return a;
}
 
void normalize(long_value l) {

  for (size_length i = 0; i < l.length - 1; ++i) {
    if (l.values[i] >= BASE) { 
      digit carryover = l.values[i] / BASE;
      l.values[i + 1] += carryover;
      l.values[i] -= carryover * BASE;
    } else if (l.values[i] < 0) { 
      digit carryover = (l.values[i] + 1) / BASE - 1;
      l.values[i + 1] += carryover;
      l.values[i] -= carryover * BASE;
    }
  }
}


long_value karatsuba(long_value a, long_value b) {
  long_value product; 
  product.length = a.length + b.length;
  product.values = new digit[product.length];
 
  if (a.length < MIN_LENGTH_FOR_KARATSUBA) { 
    memset(product.values, 0, sizeof(digit) * product.length);
    for (size_length i = 0; i < a.length; ++i)
      for (size_length j = 0; j < b.length; ++j) {
        product.values[i + j] += a.values[i] * b.values[j];

      }
  } else { 
    long_value a1;
    a1.values = a.values;
    a1.length = (a.length + 1) / 2;
 
    long_value a2; 
    a2.values = a.values + a1.length;
    a2.length = a.length / 2;
 
    long_value b1; 
    b1.values = b.values;
    b1.length = (b.length + 1) / 2;
 
    long_value b2; 
    b2.values = b.values + b1.length;
    b2.length = b.length / 2;
 
    long_value sum_a = sum(a1, a2); 
    normalize(sum_a);
    long_value sum_b = sum(b1, b2); 
    normalize(sum_b);
    long_value product_of_sums_of_parts = karatsuba(sum_a, sum_b);
 
    long_value product_of_first_parts = karatsuba(a1, b1); 
    long_value product_of_second_parts = karatsuba(a2, b2); 
    long_value sum_of_middle_terms = sub(sub(product_of_sums_of_parts, product_of_first_parts), product_of_second_parts);
 
 
    memcpy(product.values, product_of_first_parts.values,
      product_of_first_parts.length * sizeof(digit));
    memcpy(product.values + product_of_first_parts.length,
      product_of_second_parts.values, product_of_second_parts.length
      * sizeof(digit));
    for (size_length i = 0; i < sum_of_middle_terms.length; ++i)
      product.values[a1.length + i] += sum_of_middle_terms.values[i];


    delete [] sum_a.values;
    delete [] sum_b.values;
    delete [] product_of_sums_of_parts.values;
    delete [] product_of_first_parts.values;
    delete [] product_of_second_parts.values;
  }
 
  normalize(product);
 
  return product;
}


int main (){ 
    long_value x, y, z;
    digit n=8;
    
    for (int i=0; i<n; i++) {
        cin >> x.values[i];
    }

    for (int i=0; i<n; i++) {
        cin >> y.values[i];
    }
    
    z=karatsuba(x, y);
    cout << z;
    
    return 0;
}