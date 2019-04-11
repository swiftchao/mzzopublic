/*************************************************************************
    > File Name: 17.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2019-04-11 21:31:17
 ************************************************************************/

#include <stdio.h>

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

/*直接互换的选择排序*/
void select_sort(int iarr[], int n) {
  int i, high, tmp, j;
  tmp = 0;
  for (i = 0, high = n - 1; i <= high; ++i) {
    for (j = i + 1; j <= high; ++j) {
      if (iarr[i] > iarr[j]) {
        swap(&iarr[i], &iarr[j]);
      }
    }
  } 
}

/*先拿最小值的小标再进行替换的选择排序*/
void select_sort2(int iarr[], int n) {
  int i, high, tmp, j, minindex;
  tmp = 0;
  for (i = 0, high = n - 1; i <= high; ++i) {
    minindex = i;
    for (j = i + 1; j <= high; ++j) {
      /*始终拿最小的值和后面的值比较*/
      if (iarr[minindex] > iarr[j]) {
        /*只拿到最小值的下标,一次循环结束,再互换值*/
        minindex = j;
      }
    }
    /*一个循环替换一次*/
    if (minindex != i) {
      swap(&iarr[minindex], &iarr[i]);
    }
  } 
}

int main(void) {
  int i;
  int s[] = {8, 4, 0, -1, 6, 0, -5, 1, -20, 200, 2, 10, 53, 7, 9};
  printf("The array before reset is:");
  for (i = 0; i < sizeof(s)/sizeof(s[0]); ++i) {
    printf("%4d", s[i]);
  }
  printf("\n");

  int n = sizeof(s) / sizeof(s[0]);
//  select_sort(s, n);
  select_sort2(s, n);

  printf("The array after reset is:");
  for (i = 0; i < sizeof(s)/sizeof(s[0]); ++i) {
    printf("%4d", s[i]);
  }
  printf("\n");
  return 0;
}
