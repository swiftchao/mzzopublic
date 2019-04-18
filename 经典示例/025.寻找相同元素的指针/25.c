/*************************************************************************
    > File Name: 25.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2019-04-19 02:58:27
 ************************************************************************/

#include <stdio.h>

/*函数在已知两个从小到大有序的数组中寻找都出现的第一个元素的指针*/
int *search(int arr[], int arr2[], int n, int n2) {
  int *pa, *pa2; 
  pa = arr;
  pa2 = arr2; /*为pa,pa2设定初值*/
  while (pa < (arr + n) && pa2 < (arr2 + n2)) {
    /*数组一的值小于数组二的值,继续移动数组指针寻找下一个值和数组二比较*/
    if (*pa < *pa2) {
      ++pa; /*调整数组一的当前元素的指针*/
    } else if (*pa > *pa2) {
      ++pa2; /*调整数组二的当前元素的指针*/
    } else {
      return pa; /*返回在这两个数组中找到的相等的元素*/
    }
  }
  return NULL;
}

int main(void) {
  int i, *pv;
  int arr[] = {1, 3, 5, 7, 9, 13, 15, 27, 29, 37};
  int arr2[] = {2, 4, 6, 8, 10, 13, 14, 27, 29, 37};
  puts("The elements of array arr is :");
  int n = sizeof(arr) / sizeof(arr[0]);
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  for (i = 0; i < n; ++i) {
    printf("%4d ", arr[i]);
  }
  printf("\n");

  puts("The elements of array arr2 is :");
  for (i = 0; i < n2; ++i) {
    printf("%4d ", arr2[i]);
  }
  printf("\n");

  pv = search(arr, arr2, n, n2);
  if (pv) {
    printf("The first same number in both arrays is : %d\n", *pv);
  } else {
    printf("Not found!\n");
  }
  return 0;
}
