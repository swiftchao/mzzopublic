/*************************************************************************
    > File Name: 18.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2019-04-18 02:59:07
 ************************************************************************/


#include <stdio.h>

/*函数将无符号整数n翻译成d(2<=d<=16)进制的字符串s*/
#define M (sizeof(unsigned int) * 8)
int trans(unsigned n, int d, char s[]) {
  static char digits[] = "0123456789ABCDEF"; /*十六进制数字的字符*/
  int j, i = M + 1;
  char buf[M + 1];
  if (d < 2 || d > 16) {
    s[0] = '\0'; /*不合理的进制,置s为空字符串*/
    return 0; /*不合理的进制,函数返回0*/
  }
  buf[M+1] = '\0';
  while (n) {
    /*算出取余后的数赋值给最后一位存储字符的位置*/
    buf[--i] = digits[n % d]; /*翻译出最低位,对应字符存入对应工作数组中*/
    /*除以进制,得到余数赋值给n*/
    n /= d;
  }

  /*将buf的值赋值给s*/
  for (j = 0; ((s[j] = buf[i]) != '\0'); ++j, ++i);
  return j;
}

int main(void) {
  unsigned int num = 253;
  int scale[] = {2, 3, 6, 8, 10, 16, 1};
  char str[33];
  int i;
  printf("sizof(unsigned int):%d\n", sizeof(unsigned int));
  for (i = 0; i < sizeof(scale) / sizeof(scale[0]); ++i) {
    if (trans(num, scale[i], str)) {
      printf("%5d = %s(%d)\n", num, str, scale[i]);
    } else {
      printf("%5d => (%d) Error!\n", num, scale[i]);
    }
  }
  return 0;
}
