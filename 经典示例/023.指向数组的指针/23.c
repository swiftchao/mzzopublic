/*************************************************************************
    > File Name: 23.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2019-04-19 01:38:56
 ************************************************************************/

#include <stdio.h>

int main(void) {
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  int j; /*游标变量*/
  int *p; /*指针变量*/
  for (j = 0; j < n; ++j) { /*数组名和下标顺序访问数组的元素*/
    printf("arr[%d] = %d\t", j, arr[j]);
  }
  printf("\n");

  /*让指针顺序顺序指向数组的各元素,遍历数组*/
  for (p = arr; p < arr + n; ++p) {
    printf("*p = %d\t\t", *p);
  }
  printf("\n");


  /*指针与游标结合,改变游标变量遍历数组*/
  for (p = arr, j = 0; j < n; ++j) {
    printf("*(p+%d) = %d\t", *(p+j));
  }
  printf("\n");

  /*指针与游标变量结合,用指针和下标遍历数组*/
  for (p = (arr+n-1), j = (n - 1); j >= 0; --j) {
    printf("p[-%d] = %d\t", j, p[-j]);
  }
  printf("\n");
  return 0;
}
