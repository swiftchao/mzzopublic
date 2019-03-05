#include <stdio.h>
#define MAXN 20
int a[MAXN][MAXN];

int main(void) {
  int max, min;
  int row, col, n;
  printf("Please input the order of the matrix:\n");
  scanf("%d", &n);
  printf("Please input the elements of the matrix,\n from a[0][0] to a[%d][%d]:\n", n - 1, n - 1);
  for (row = 0; row < n; ++row) {
      for (col = 0; col < n; ++col) {
          scanf("%d", &a[row][col]);
      }
  }
  for (min = a[0][0], max = a[0][0], row = 0; row < n; ++row) {
    for (col = 0; col < n; ++col) {
      if (min > a[row][col]) {
        min = a[row][col];
      }
      if (max < a[row][col]) {
        max = a[row][col];
      }
    }
  }
  printf("The max is %d, min is %d\n", max, min);
  return 0;
}
