//Написать программу, находящую среднее арифметическое факториалов последовательности чисел
  #include <iostream> 
  using namespace std; 
   
   
  int factor(int num){ 
   int result = 1; 
   if(num == 0 || num ==1) 
   return 1; 
   else if(num < 0) 
   return 0; 
   for(int i = 1; i <= num; i++){ 
   result *= i; 
   } 
   return result; 
  } 
   
   
  int main() { 
   int n; 
   cin »n; 
   int *array = new int[n]; 
   double sum = 0; 
   for(int i = 0; i < n; i++){ 
   cin »array[i]; 
   array[i] = factor(array[i]); 
   cout « array[i] « endl; 
   sum += (double)array[i]; 
   } 
   cout « sum/n; 
   return 0; 
  }
