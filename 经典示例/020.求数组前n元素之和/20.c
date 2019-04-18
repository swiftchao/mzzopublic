/*************************************************************************
    > File Name: 20.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2019-04-18 12:05:17
 ************************************************************************/

#include <stdio.h>

/*常规的循环求和*/
int sum(int arr[], int n) {
  int i;
  int total = 0;
  for (i = 0; i < n; ++i) {
    total += arr[i];
  }
  return total;
}

/*调用递归求和*/
int sum_recursive(int arr[], int n) {
  if (n <= 0) {
    return 0;
  }
  /*sum_recursive(arr, n)     ==> arr[n - 1] + sum_recursive(arr, n - 1)*/
  /*sum_recursive(arr, n - 1) ==> arr[n - 2] + sum_recursive(arr, n - 2)*/
  /* 
   * eg:
   * sum_recursive(arr, 6)     ==> arr[6 - 1] + sum_recursive(arr, 6 - 1)
   * sum_recursive(arr, 5)     ==> arr[5 - 1] + sum_recursive(arr, 5 - 1)
   * sum_recursive(arr, 4)     ==> arr[4 - 1] + sum_recursive(arr, 4 - 1)
   * sum_recursive(arr, 3)     ==> arr[3 - 1] + sum_recursive(arr, 3 - 1)
   * sum_recursive(arr, 2)     ==> arr[2 - 1] + sum_recursive(arr, 2 - 1)
   * sum_recursive(arr, 1)     ==> arr[1 - 1] + sum_recursive(arr, 1 - 1)
   * */
  //printf("sum_recursive(arr, %d)     ==> arr[%d - 1] + sum_recursive(arr, %d - 1)\n", n, n, n);
  return arr[n - 1] + sum_recursive(arr, n - 1);
}

int main(void) {
  //int arr[] = {1, 2, 3, 4, 5, 15};
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  printf("The arry is:\n");
  int n = sizeof(arr) / sizeof(arr[0]);
  int i;
  for (i = 0; i < n; ++i) {
    printf("%5d", arr[i]);
  }
  printf("\n");
  int (*psum)(int arr[], int n);
  //psum = sum; 
  psum = sum_recursive;
  int total = psum(arr, n);
  printf("Sum of the arry is:%d\n", total);
  return 0;
}
