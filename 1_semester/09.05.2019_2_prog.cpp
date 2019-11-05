//Ackermann's function is a recursive mathematical algorithm that can be used to test how well a computer performs recursion. 
//If m=0 then return n+1
//If n=0 then return A(m-1,1)
//Otherwise, return A(m-1, A(m, n-1))

#include <stdio.h>
int ackermann(int m, int n)
{
  if (m == 0) return n+1;
  if (n == 0) return ackermann( m - 1, 1 );
  return ackermann( m - 1, ackermann( m, n - 1 ) );
}

int main()
{
  for (int i = 0; i < 6; ++i)
    for (int j = 0; j < 6; ++j)
      printf("ackermann(%d,%d) = %d\n", i, j, ackermann(i,j));
      
  return 0;
}
