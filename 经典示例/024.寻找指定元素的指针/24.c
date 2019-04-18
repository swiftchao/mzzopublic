/*************************************************************************
    > File Name: 24.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2019-04-19 01:59:34
 ************************************************************************/

#include <stdio.h>

/*查找数组中的值,返回下标*/
int search(int *pa/*已知数表的首元指针*/, int n/*数组中元素的个数*/, int key/*要寻找的值*/) {
  int *pi;
  for (pi = pa; pi < pa + n; ++pi) {
    if (*pi == key) {
      return pi - pa; /*返回找到的元素的下标*/
    }
  }
  return -1;
}

/*查找数组中的值,返回对应元素的指针*/
int *find(int* pa, int n, int key) {
  int *pi;
  for (pi = pa; pi < pa + n; ++pi) {
    if (*pi == key) {
      return pi; /*返回找到的元素的指针*/
    }
  }
  return NULL;
}

int main(void) {
  int arr[] = {90, 80, 70, 60, 50, 40, 30, 20, 10, 9, 8, 7, 6, 5, 42, 40, 50, 1, 2, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  int i, key;
  printf("The elements of array arr is:\n");
  for (i = 0; i < n; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  printf("The address of arr[0] is : %p\n", &arr[0]);
  printf("Please input the key number you want to search: ");
  scanf("%d", &key);
  i = search(arr, n, key);
  printf("The label number of the key number %d in the array is: %d\n", key, i);

  int *pi = find(arr, n, key);
  printf("The point value of the key number %d in the array is: %p -> %d\n", key, pi, *pi);
  return 0;
}
