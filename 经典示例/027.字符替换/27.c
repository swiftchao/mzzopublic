/*************************************************************************
    > File Name: 27.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2019-04-19 07:58:40
 ************************************************************************/

#include <stdio.h>
#define MAX 50 

void rep(char *s, char *s1, char *s2) {
  char *p;
  for (; *s; ++s) { /*顺序访问字符串s中的每个字符*/
    for (p = s1; *p && *p != *s; ++p); /*检查当前字符串是否在字符串s1中出现*/
    if (*p) {
      *s = *(p - s1 + s2); /*当前字符串在字符串s1中出现,用字符串s2中的对应字符代替s中的字符*/
    }
  }
}

int main(void) {
  char s[MAX]; /*=ABCABC*/
  char s1[MAX], s2[MAX];
  puts("Please input the string for s:");
  scanf("%s", s);
  puts("Please input the string for s1:");
  scanf("%s", s1);
  puts("Please input the string for s2:");
  scanf("%s", s2);

  printf("s:%s\ts1:%s\ts2:%s\n", s, s1, s2);
  rep(s, s1, s2);
  printf("s:%s\ts1:%s\ts2:%s\n", s, s1, s2);
  return 0;
}
