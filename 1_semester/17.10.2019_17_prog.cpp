//Реализовать умножение Карацубы для длинной арифметики
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
typedef int digit;
typedef unsigned long int size_length; 
 
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
 
void normalize(long_value &C) {

  for (size_length i = 0; i < C.length - 1; ++i) {
    if (C.values[i] >= 10) { 
      digit carryover = C.values[i] / 10;
      C.values[i + 1] += carryover;
      C.values[i] -= carryover * 10;
    } else if (C.values[i] < 0) { 
      digit carryover = (C.values[i] + 1) / 10 - 1;
      C.values[i + 1] += carryover;
      C.values[i] -= carryover * 10;
    }
  }
}


long_value karatsuba(long_value a, long_value b) {
  long_value product; 
  product.length = a.length + b.length;
  product.values = new digit[product.length];
 
  if (a.length < 4) { 
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
    long_value number1, number2;
    cin >>  number1;
    cin >>  number2;
    
    cout << karatsuba (number1, number2) << endl;
    return 0;
}
