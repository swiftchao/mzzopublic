#include <stdio.h>

/* 数列求和 :
 * eg: n=5
 * 1          1
 * 1 2        3
 * 1 2 3      6
 * 1 2 3 4    10
 * 1 2 3 4 5  15
 * 之和       35
 * */

int main(void)
{
  int i, j, n;
  long sum = 0, temp = 0;
  
  printf("Please input a number to n:\n");
  scanf("%d", &n);
  if (n < 1)
  {
    printf("The n must no less than 1!\n");
    return 1;
  }
  
  for (i = 1; i <= n; ++i)
  {
    temp = 0;
    for (j = 1; j <= i; ++j)
    {
      temp += j;
    }
    sum += temp; 
  }
  printf("The sum of the sequence(%d) is %d\n", n, sum);
  return 0;
}
