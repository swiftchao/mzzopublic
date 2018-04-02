#include <stdio.h>

int main(void)
{
  printf("\n\n * * * * * * * * *\n\n");
  int i = 0, j = 0;
  for (i = 1; i <= 9; ++i)
  {
    for (j = 1; j <= i; ++j)
    {
      printf("%d * %d = %2d  ", j, i, j * i);
    }
    printf("\n");
  }
  return 0;
}