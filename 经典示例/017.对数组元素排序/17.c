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

/*快速排序*/

int main(void) {
  int i;
  //int s[] = {8, 4, 0, -1, 6, 0, -5, 1, -20, 200, 2, 10, 53, 7, 9};
  //int s[] = {8, 4, 0, -1, 6, 0, -5, 1, -20, 200, 2, 10, 53, 7, 9, 8, 13, 16, 28};
  int s[] = {21, 25, 48, 25, 16, 8};
  printf("The array before reset is:");
  for (i = 0; i < sizeof(s)/sizeof(s[0]); ++i) {
    printf("%4d", s[i]);
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
  sort = shell_sort;
  sort(s, n);
  endtime = clock();
  printf("Sort Running Time: %dms\n", (double)(endtime - begintime)/CLOCKS_PER_SEC);

  printf("The array after reset is:");
  for (i = 0; i < sizeof(s)/sizeof(s[0]); ++i) {
    printf("%4d", s[i]);
  }
  printf("\n");
  return 0;
}
