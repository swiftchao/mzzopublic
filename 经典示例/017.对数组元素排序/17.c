/*************************************************************************
    > File Name: 17.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2019-04-11 21:31:17
 ************************************************************************/

#include <stdio.h>
#include <time.h>

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

/*冒泡排序*/
void bubble_sort(int iarr[], int n) {
  int i, j;
  for (i = n - 1; i >= 0; --i) {
    for (j = 0; j < i; ++j) {
      /*将大的值放到右边*/
      if (iarr[j] > iarr[i]) {
        swap(&iarr[j], &iarr[i]);
      }
    }
  }
}

void bubble_sort2(int iarr[], int n) {
  int i, j;
  for (i = 0; i <= n - 1; ++i) {
    for (j = i + 1; j <= n - 1; ++j) {
      /*将小的值放到左边*/
      if (iarr[j] < iarr[i]) {
        swap(&iarr[j], &iarr[i]);
      }
    }
  }
}

/*直接的插入排序*/
void straight_insert_sort(int iarr[], int n) {
  int i = 0, j = 0, tmp = 0;
  for (i = 1; i < n ; ++i) {
    j = i;
    tmp = iarr[i];
    while (j > 0 && iarr[j-1] > tmp) {
      iarr[j] = iarr[j-1];
      --j;
    }
    iarr[j] = tmp;
  }
}

/*希尔排序*/
/*h = 3 * b + 1
 *h = (h - 1) / 3
 * */
void shell_sort(int iarr[], int n) {
  int h = 1;
  while (h < n / 3) {
    /*选择一个恰当增量*/
    h = h * 3 + 1;
  }
  int  i = 0, j = 0, tmp = 0;
  while (h >= 1) {
    for (i = h; i < n; ++i) {
      tmp = iarr[i];
      for (j = i; j >= h && iarr[j - h] > tmp; j -= h) {
        iarr[j] = iarr[j - h];
      }
      iarr[j] = tmp;
    }
    h = (h - 1) / 3;
  }
}

/*快速排序介绍
 * The array before reset is:
 *                                 8    4    0   -1    6    0   -5    1  -20  200    2   10   53    7    9    8   13   16   28
 * left: 0 right:18 base: 8 ==>    7    4    0   -1    6    0   -5    1  -20    2    8   10   53  200    9    8   13   16   28 
 * left: 0 right: 9 base: 7 ==>    2    4    0   -1    6    0   -5    1  -20    7 
 * left: 0 right: 8 base: 2 ==>  -20    1    0   -1   -5    0    2    6    4 
 * left: 0 right: 5 base:-20 ==>  -20    1    0   -1   -5    0 
 * left: 1 right: 5 base: 1 ==>    0    0   -1   -5    1 
 * left: 1 right: 4 base: 0 ==>   -5    0   -1    0 
 * left: 1 right: 3 base:-5 ==>   -5    0   -1 
 * left: 2 right: 3 base: 0 ==>   -1    0 
 * left: 7 right: 8 base: 6 ==>    4    6 
 *
 * 右边的排序
 * left:11 right:18 base:10 ==>    8    9   10  200   53   13   16   28 
 * left:11 right:12 base: 8 ==>    8    9 
 * left:14 right:18 base:200 ==>   28   53   13   16  200 
 * left:14 right:17 base:28 ==>   16   13   28   53 
 * left:14 right:15 base:16 ==>   13   16 
 * Sort Running Time: 19ms
 * The array after reset is:
 *                               -20   -5   -1    0    0    1    2    4    6    7    8    8    9   10   13   16   28   53  200
 *
 * */
/*快速排序*/
void quick_sort(int iarr[], int left, int right) {
  int low = left;
  int high = right;
  /*1.排序开始low = 0, high = right -> n - 1*/
  int key = iarr[left]; /*2.以数组第一个元素为关键数据,赋值给key,即key=iarr[0]*/
  if (low >= high) { /*递归调用的退出条件*/
    return;
  }
  while (low < high) {
    /*3.从high开始向前搜索,即由后向前搜索(--high),找到第一个小于key的值iarr[high],将iarr[high]和iarr[low]互换*/
    while (low < high && iarr[high] >= key) {
      --high; /*向前寻找*/
    }
    /*从右往左寻找到比基线值小的值iarr[high]和基线值所在位置iarr[low]替换,此时iarr[low]既是基线值*/
    swap(&iarr[low], &iarr[high]);
    /*3.从左往右开始向后搜索,即由前向后搜索(++low),找到第一个大于key的值iarr[low],将iarr[low]和iarr[high]互换*/
    while (low < high && iarr[low] <= key) {
      ++low; /*向后寻找*/
    }
    /*从左往右寻找到比基线值大的值即iarr[low],此时基线值所在位置下边为high,基线值为iarr[high]*/
    swap(&iarr[low], &iarr[high]);
  }
  /*此时low==high的值,基准值key为iarr[low],iarr[high],基准值左边所有的值都比基准值小,基准值右边的所有值都比基准值大*/
  /*基准值左边再重复以上过程*/

  /*
   * 打印快速排序的过程
  int i;
  printf("left:%2d right:%2d base:%2d ==> ", left, right, key);
  for (i = left; i <= right; ++i) {
    printf("%4d ", iarr[i]);
  }
  printf("\n");
  */

  quick_sort(iarr, left, low - 1);
  /*基准值右边再重复以上过程*/
  quick_sort(iarr, low + 1, right);
}

int main(void) {
  int i;
  //int s[] = {8, 4, 0, -1, 6, 0, -5, 1, -20, 200, 2, 10, 53, 7, 9};
  int s[] = {8, 4, 0, -1, 6, 0, -5, 1, -20, 200, 2, 10, 53, 7, 9, 8, 13, 16, 28};
  //int s[] = {21, 25, 48, 25, 16, 8};
  printf("The array before reset is:\n%28s", " ");
  for (i = 0; i < sizeof(s)/sizeof(s[0]); ++i) {
    printf("%5d", s[i]);
  }
  printf("\n");

  int n = sizeof(s) / sizeof(s[0]);
  clock_t begintime, endtime;
  begintime = clock();
  void (*sort) (int iarr[], int n);
  //sort = select_sort;
  //sort = select_sort2;
  //sort = bubble_sort;
  //sort = bubble_sort2;
  //sort = straight_insert_sort;
  //sort = shell_sort;
  //sort(s, n);

  int low = 0;
  int high = n - 1;
  quick_sort(s, low, high);

  endtime = clock();
  printf("Sort Running Time: %dms\n", (double)(endtime - begintime)/CLOCKS_PER_SEC);

  printf("The array after reset is:\n%28s", " ");
  for (i = 0; i < sizeof(s)/sizeof(s[0]); ++i) {
    printf("%5d", s[i]);
  }
  printf("\n");
  return 0;
}
