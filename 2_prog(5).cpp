//Ackermann's function is a recursive mathematical algorithm that can be used to test how well a computer performs recursion. 
//If m=0 then return n+1
//If n=0 then return A(m-1,1)
//Otherwise, return A(m-1, A(m, n-1))

#include <stdio.h>
int ack(int m, int n)
{
  if (m == 0) return n+1;
  if (n == 0) return ack( m - 1, 1 );
  return ack( m - 1, ack( m, n - 1 ) );
}

int main()
{
  for (int i = 0; i < 6; ++i)
    for (int j = 0; j < 6; ++j)
      printf("ack(%d,%d) = %d\n", i, j, ack(i,j));
      
  return 0;
}