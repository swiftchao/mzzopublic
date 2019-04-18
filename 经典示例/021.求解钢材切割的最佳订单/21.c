/*************************************************************************
    > File Name: 21.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2019-04-18 12:40:13
 ************************************************************************/

#include <stdio.h>

#define N 20
#define DELTA 2 /*约定切割一次耗损固定长度的钢材(约定该值为2)*/

/*
 * eg:
 * Please enter total length of the steel:
 * 5
 * Please enter number of order which is < 20:
 * 3
 * Please enter the orders:
 * 1 2 3
 *
 * orderlen[0]:1 len:3 
 * orderlen[0]:1 len:3 orderlen[1]:2 len:7 
 * orderlen[0]:1 len:3 orderlen[1]:2 len:7 orderlen[2]:3 len:12 
 * orderlen[0]:1 len:3 orderlen[2]:3 len:8 
 * orderlen[1]:2 len:4 
 * orderlen[0]:1 len:3 orderlen[1]:2 len:7 
 * orderlen[0]:1 len:3 orderlen[1]:2 len:7 orderlen[2]:3 len:12 
 * orderlen[1]:2 len:4 orderlen[2]:3 len:9 
 * orderlen[2]:3 len:5 
 * orderlen[0]:1 len:3 orderlen[2]:3 len:8 
 * orderlen[1]:2 len:4 orderlen[2]:3 len:9 
 * order 3 length = 3
 * */
int solve(int n, int total, int orderlen[], int sele[], int bestlen, int bestsele[]) {
  int i, len;
  for (len = 0, i = 0; i < n; ++i) { /*求当前选中的用料量*/
    if (sele[i]) {
      len += orderlen[i] + DELTA;
      //printf("orderlen[%d]:%d len:%d ", i, orderlen[i], len);
    }
  }
  //printf("\n");
  if ((len - DELTA) <= total) { /*注意最后一段不需要切割*/
    if (bestlen < len) {
      /*找到一个更好的解*/
      bestlen = len;
      for (i = 0; i < n; ++i) {
        bestsele[i] = sele[i];
      }
    }
    for (i = 0; i < n; ++i) { /*对所有未选定单逐一选中尝试循环*/
      if (!sele[i]) {
        sele[i] = 1; /*做选中尝试*/
        solve(n, total, orderlen, sele, bestlen, bestsele);
        sele[i] = 0;
      }
    }
  }
  return 0;
}

int main(void) {
  int i;
  int total; /*钢材总长度*/
  int n; /*订单数*/
  int orderlen[N]; /*订单数组,各订单需要的钢材长度*/
  int bestlen = 0; /*最佳解用料的初始值*/
  int bestsele[N]; /*最佳选择数组*/
  int sele[N]; /*当前选择数组*/
  printf("Please enter total length of the steel:\n");
  scanf("%d", &total);
  printf("Please enter number of order which is < %d:\n", N);
  scanf("%d", &n);
  printf("Please enter the orders:\n");
  for (i = 0; i < n; ++i) {
    scanf("%d", &orderlen[i]);
  }
  for (i = 0; i < n; ++i) {
    /*置当前选择和最佳选择初值*/
    sele[i] = 0;
    bestsele[i] = 0;
  }

  /*调用函数求解*/
  solve(n, total, orderlen, sele, bestlen, bestsele);

  /*输出结果*/
  for (i = 0; i < n; ++i) {
    if (bestsele[i]) {
      printf("order %d length = %d\n", i + 1, orderlen[i]);
    }
  }
  return 0;
}
