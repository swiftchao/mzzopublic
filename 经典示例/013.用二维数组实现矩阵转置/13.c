/* 用二维数组实现矩阵的转置 */
#include <stdio.h>
#define ROW 3
#define COL 4
int main() {
  // {1, 2, 3, 4}
  // {5, 6, 7, 8}
  // {9, 10, 11, 12}
  int matrixA[ROW][COL], matrixB[COL][ROW];
  int i, j;
  printf("Please input matrixA[%d][%d]\n", ROW, COL);
  for (i = 0; i < ROW; ++i) {
    for (j = 0; j < COL; ++j) {
      printf("Please input matrixA[%d]*[%d]\n", i, j);
      scanf("%d", &matrixA[i][j]);
    }
  }
  printf("print matrixA[%d][%d]\n", ROW, COL);
  for (i = 0; i < ROW; ++i) {
    for (j = 0; j < COL; ++j) {
      printf("%8d", matrixA[i][j]);
    }
    printf("\n");
  }
  for (i = 0; i < COL; ++i) {
    for (j = 0; j < ROW; ++j) {
        matrixB[i][j] = matrixA[j][i];
    }
  }
  printf("print matrixB[%d][%d]\n", COL, ROW);
  for (i = 0; i < COL; ++i) {
    for (j = 0; j < ROW; ++j) {
        printf("%8d", matrixB[i][j]);
    }
    printf("\n");
  }
  printf("\n Press any key to quit... \n");
  return 0;
}
