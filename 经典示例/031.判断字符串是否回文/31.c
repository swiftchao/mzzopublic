/*************************************************************************
    > File Name: 31.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2019-04-24 03:20:31
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX 50

int cycle(char *s) {
  char *phead, *ptail;
  ptail = s + strlen(s) - 1;
  /*循环条件ptail > phead,当phead == ptail时,前后的字符串都已比较完毕,都相等*/
  for (phead = s; ptail > phead; ++phead, --ptail) {
    if (*phead != *ptail) {
      return 0;
    }
  }
  /*121这种类型的字符串,循环走完,最后是phead==ptail
   * 123321这种类型的字符串,循环走完,最后是phead > ptail(phead - ptail == 1)
   * */
  return phead >= ptail;
  //return 1;
}

int main(void) {
  char s[MAX];
  memset(s, '\0', sizeof(s) / sizeof(s[0]));
  while (1) {
    puts("Please input the string you want to judge (input ^ to quit)");
    scanf("%s", s);
    if (s[0] == '^') {
      break;
    }
    if (cycle(s)) {
      printf("%s is a cycle string.\n", s);
    } else {
      printf("%s is not a cycle string.\n", s);
    }
  }
  puts("Thank you for you using, bye bye!\n");
  return 0;
}
