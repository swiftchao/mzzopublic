/*************************************************************************
    > File Name: 19.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2019-04-18 09:17:16
 ************************************************************************/

#include <stdio.h>
#include <string.h>

/*用于判断正整数n的d进制数表示是否是回文数*/
int circle(int n, int d, char str[]) {
  int s = 0, m = n;
  static char digits[] = "0123456789ABCDEF"; /*十六进制字符串*/
  memset(str, '\0', sizeof(str));
  int j = 0;
  while (m) {
    /*赋值带出转换为对应进制的字符串*/
    str[j++] = digits[m % d];
    s = (s * d) + (m % d); /*根据d进制*s和加上m % d的数,循环当m=0是为止*/
    /*m除以进制代码循环的次数*/
    m /= d;
  }
  /*返回是否是回文数字,相等(1)就是回文数,否则(0)就不是*/
  return n == s;
}

int main(void) {
  int num[] =  {15, 232, 27, 851, 253}; /*测试数据数组*/
  int scale[] = {2, 10, 16}; /*进制数组*/
  int i, j;
  char str[33];
  for (i = 0; i < sizeof(num) / sizeof(num[0]); ++i) {
    for (j = 0; j < sizeof(scale)/ sizeof(scale[0]); ++j) {
      if (circle(num[i], scale[j], str)) {
        printf("%5d -> %s(%d) decimal is is a circle number.\n", num[i], str, scale[j]);
      } else {
        printf("%5d -> %s(%d) decimal is is not a circle number!\n", num[i], str, scale[j]);
      }
    }
  }
  return 0;
}
