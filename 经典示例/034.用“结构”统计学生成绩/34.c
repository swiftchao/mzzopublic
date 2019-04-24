/*************************************************************************
    > File Name: 34.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2019-04-24 11:36:54
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 200
#define SCORES 5
#define NUMLEN 10

struct std_type {
  char no[NUMLEN]; /*学号*/
  char *name; /*名字字符串指针*/
  int scores[SCORES]; /*五门课的成绩*/
  int total; /*五门课的总成绩*/
  int order; /*总分的排名名次*/
};

int readstu(struct std_type *spt) {
  int i, len;
  char buf[120]; /*输入字符串的缓冲区*/
  printf("Please input the Number:\n"); /*输入学号*/
  if (scanf("%s", buf) == 1) {
    strcpy(spt->no, buf);
  } else {
    return 0; /*Windows Ctrl+z结束输入 Linux/Unix是Ctrl+d结束输入*/
  }

  printf("Please input the Name:\n"); /*输入名字*/
  if (scanf("%s", buf) == 1) {
    len = strlen(buf);
    spt->name = (char *)malloc(len+1); /*申请的空间要加上'\0'的位置所以len+1*/
    strcpy(spt->name, buf);
  } else {
    return 0;
  }

  printf("Please input the Scores:\n"); /*输入成绩*/
  int scoreslen = sizeof(spt->scores) / sizeof(spt->scores[0]);
  for (i = 0; i < scoreslen; ++i) {
    if (scanf("%d", &spt->scores[i]) != 1) { /*当输入不是数字而是其他的时候输入的结果!=1,break*/
      break;
    }
  }
  /*输入scores的时候,开始是就不是数字,就break跳出输入循环i==0*/
  if (i == 0) { /*一个成绩也未输入*/
    free(spt->name); /*释放存储姓名的空间*/
    return 0;
  }
  /*输入scores的时候,开始是数字,后面不是数字,就break跳出输入循环*/
  for (; i < scoreslen; ++i) { /*少数未输入的成绩用0分代之*/
    spt->scores[i] = 0;
  }
  return 1;
}

/*输出一个学生信息的函数*/
int writestu(struct std_type *spt) {
  int i;
  printf("Ranking %d\n", spt->order); /*输出名次*/
  printf("Number : %s\n", spt->no); /*输出学号*/
  printf("Name : %s\n", spt->name); /*输出姓名*/
  printf("Scores : "); /*输出成绩*/
  int scoreslen = sizeof(spt->scores) / sizeof(spt->scores[0]);
  for (i = 0; i < scoreslen; ++i) {
    printf("%4d", spt->scores[i]);
  }
  printf(" Total: %d\n\n", spt->total); /*输出成绩*/
}

int main(void) {
  struct std_type students[N];
  int n, i, j;
  /*输入学生信息n依次递增为输入的总个数*/
  for (n = 0; readstu(students+n); ++n);
  int total[n];
  int order[n];
  int t;
  int tmp = 0;

  /*计算每个学生的总成绩*/
  int scoreslen = sizeof(students[0].scores) / sizeof(students[0].scores[0]);
  for (i = 0; i < n; ++i) {
    order[i] = i; /*预置第i个输入的学生*/
    students[i].order = i;
    for (t = 0, j = 0; j < scoreslen; ++j) { /*求第i个学生的总分*/
      t += students[i].scores[j];
    }
    total[i] = t;
    students[i].total = t;
  }

  /*选择排序用总成绩排序*/
  for (i = 0; i < n -1; ++i) {
    for (j = i; j < n -1; ++j) {
      /*
      if (total[order[i]] < total[order[j+1]]) { //交换名次
        tmp = order[i];
        order[i] = order[j+1];
        order[j+1] = tmp;
      }
      */
      if (students[i].total < students[j+1].total) { //根据总分交换名次
        tmp = order[i];
        order[i] = order[j+1];
        order[j+1] = tmp;
        /*交换赋值学生成绩的排名*/
        tmp = students[i].order;
        students[i].order = students[j+1].order;
        students[j+1].order = tmp;
      }
    }
  }

  printf("\nThis is students info:\n");
  /*输出学生信息*/
  for (j = 0; j < n; ++j) {
    /*名次也刚好是结构体指针的位移*/
    //writestu(students + order[j]);
    writestu(students + order[j]);
  }
  return 0;
}
