/*************************************************************************
    > File Name: 27.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2019-04-19 07:58:40
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX 50 

/*替换s中的字符,s1中只要在s中出现,都替换成s2对应指针位置的字符,若s2的长度小于s1,赋值的位置的值就可能出现不确定的值*/
void rep(char *s, char *s1, char *s2) {
  char *p;
  for (; *s; ++s) { /*顺序访问字符串s中的每个字符*/
    /*获取s1中和s指针位置相同的字符的指针*/
    for (p = s1; *p && *p != *s; ++p); /*检查当前字符串是否在字符串s1中出现*/
    if (*p) {
      /*将s2指针移动p-s1的位置的值赋值给指针s所在位置*/
      *s = *(p - s1 + s2); /*当前字符串在字符串s1中出现,用字符串s2中的对应字符代替s中的字符*/
    }
  }
}

int main(void) {
  /*s="abcabc" s1="b" s2 ="m" result:s=amcamc*/
  /*s="abcabc" s1="fbac" s2 ="mqr" result:s="rq"*/
  char s[MAX];
  char s1[MAX], s2[MAX];
  memset(s, '\0', sizeof(s) / sizeof(s[0]));
  memset(s1, '\0', sizeof(s1) / sizeof(s1[0]));
  memset(s2, '\0', sizeof(s2) / sizeof(s2[0]));
  puts("Please input the string for s:");
  scanf("%s", s);
  puts("Please input the string for s1:");
  scanf("%s", s1);
  puts("Please input the string for s2:");
  scanf("%s", s2);

  printf("The string before replace:\n");
  printf("s:%s\ts1:%s\ts2:%s\n", s, s1, s2);
  rep(s, s1, s2);
  printf("The string after replace:\n");
  printf("s:%s\ts1:%s\ts2:%s\n", s, s1, s2);
  return 0;
}
