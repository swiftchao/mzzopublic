/*************************************************************************
    > File Name: 35.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2019-04-24 19:58:07
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct ele {
  int no;
  struct ele *link;
};

int main(void) {
  int n, m, i;
  struct ele *h, *u, *p;
  printf("Please input n & m:\n");
  scanf("%d%d", &n, &m); /*输入n和m*/
  h = u = (struct ele *)malloc(sizeof(struct ele)); /*形成首表元*/
  h->no = 1;
  /*形成其余的n-1个表元*/
  for (i = 2; i <= n; ++i) {
    u->link = (struct ele *)malloc(sizeof(struct ele));
    u = u->link; /*u依次等于后面的结构体*/
    u->no = i; /*第i个表元素置编号i*/
  }
  u->link = h; /*末表元后继首表元,形成环*/

  puts("The numbers of who will quit the cycle in turn are:");
  while (n) {
    for (i = 1; i < m; ++i) { /*掠过m-1个表元*/
      u = u->link;
    }
    p = u->link; /*p指向第m个表元u->link*/
    u->link = p->link; /*第m个表元从环中脱钩,m-1->link指向m+1的位置,即m->link*/
    printf("%4d", p->no);
    free(p); /*释放第m个元素的占用空间*/
    --n;
  }
  printf("\n");
  return 0;
}
