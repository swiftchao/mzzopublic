/*************************************************************************
    > File Name: 15-2.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2019-03-09 09:32:40
 ************************************************************************/

#include <stdio.h>

int main(void) {
  int n = 0;
  printf("Please input primes numbers:");
  scanf("%d", &n);
  printf("prime numbers are:%d\n", n);
  int np = 0;
  int primes[n];
  primes[0] = 2;
  np = 1;
  int m = 3;
  while (np < n) {
    int i;
    int isnotprime = 0;
    for (i = 0; (primes[i] * primes[i] <= m); ++i) {
      if (m % primes[i] == 0) {
        isnotprime = 1;
        break;
      }
    }
    if (!isnotprime) {
      primes[np++] = m;
    }
    m += 2;
  }
  int j;
  for (j = 0; j < np; ++j) {
    printf("%4d", primes[j]);
  }
  printf("\n");
  return 0;
}
