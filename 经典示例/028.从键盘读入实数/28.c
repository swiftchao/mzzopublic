/*************************************************************************
    > File Name: 28.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2019-04-19 10:37:12
 ************************************************************************/

#include <stdio.h>
#define ERR 5
#define OK 6

int status;
double result, sig, scale;

/*处理数的符号函数*/
int sign(int c) {
  /*若为负号,置负数标记*/
  if (c == '-') {
    sig = -sig;
  }
}

/*转换整数部分,转换一位整数位*/
int integer(int c) {
  result = result * 10.0 + c - '0';
}

/*转换小数部分,转换一位小数位*/
int decimal(int c) {
  result += (c - '0') * scale;
  scale /= 10.0;
}

/*状态表*/
int statbl[][4] = {{1, 2, 3, ERR}, /*0*/
                   {ERR, 2, 3, ERR}, /*1*/
                   {OK, 2, 4, OK}, /*2*/
                   {ERR, 4, ERR, ERR}, /*3*/
                   {OK, 4, OK, OK}}; /*4*/

/*转换函数表*/
int (*funtbl[][4])() = {{sign, integer, NULL, NULL}, 
                        {NULL, integer, NULL, NULL}, 
                        {NULL, integer, NULL, NULL}, 
                        {NULL, decimal, NULL, NULL},
                        {NULL, decimal, NULL, NULL}};

/**/
int readreal(double *pd) {
  int c, ckind;
  sig = 1.0;
  result = 0.0;
  scale = 0.1;
  while ((c = getchar()) == ' ' || c == '\n' || c == '\t'); /*跳过前导空白符*/
  printf("c:%c\n", c);
  printf("c-'0':%d\n", c - '0');
  status = 0; /*置初始状态*/
  for (; ;) {
    /*分类当前字符*/
    if (c = '+' || c == '-')  {
      ckind = 0; /*数的符号字符*/
    } else if (c >= '0' && c <= '9') {
      ckind = 1; /*数字符*/
    } else if (c == '.') {
      ckind = 2; /*小数点*/
    } else {
      ckind = 3; /*其它字符*/
    }

    if (funtbl[status][ckind]) { /*如有转换函数*/
      (*funtbl[status][ckind])(c); /*执行相应的函数*/
    }
    status = statbl[status][ckind]; /*设置新的状态*/
    if (status == ERR || status == OK) {
      break; /*结束:出错或成功*/
    }
    c = getchar();
    printf("22c:%c\n", c);
  }
  ungetc(c, stdin); /*归还数的结束符*/
  if (status == OK) {
    *pd = result * sig; /*读入按指针参数赋给相应变量*/
    return 1;
  }
  return -1;
}

int main(void) {
  double x;
  printf("Please input real numbers (use nooreal char to end input):\n");
  while (readreal(&x) == 1) {
    printf("The real number you input is: %f\n", x);
  }
  return 0;
}
