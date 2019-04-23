/*************************************************************************
    > File Name: 29.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2019-04-23 18:37:36
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define N 80

/*字符排版函数,将字符行内单字之间的空白字符平均分配插入到单字之间*/
/*
 * a bc  def   ghi    chaofei. ==> a    bc    def    ghi    chaofei.
 * */
void edit(char *s) {
  int i; /*字符串循环变量的值*/
  int sp; /*计算空白的个数的变量*/
  int w; /*计算单词个数的变量*/
  int v; /*计算平均每个单词之间的空白的个数v = sp/(w-1)*/
  int r; /*计算总空白数除以(w-1)还有余数,拿到取余的数字 r = sp%(w - 1)*/
  int inw; /*is not word判断不是单词的标识*/
  char buf[N]; /*赋予s的值给buf,再将str指针指向buf移动,做操作*/
  char *str; /*临时的字符串指针,用于移动获取值*/

  /*计算空格和单词的个数*/
  for (inw = sp = w = i = 0; s[i]; ++i) {
    if (s[i] == ' ') {
      /*统计空白个数*/
      ++sp;
      inw = 0; /*置空白符状态*/
    } else if (!inw) {
      /*统计单字个数*/
      ++w;
      inw = 1; /*只单字状态*/
    }
  }

  if (w <= 1) {
    /*单字数不超过1,不排版*/
    return;
  }

  v = sp / (w - 1); /*每个间隔平均空白符*/
  r = sp % (w - 1); /*多余的空白符*/
  strcpy(buf, s);
  for (str = buf; ;) {
    /*原字符串中有空白都跳过,不做操作,直到有单词*/
    while (*str == ' ') {
      ++str; /*掠过空白符*/
    }

    /*依次将单词赋值给s*/
    for (; *str && *str != ' ';) { 
      /*复制单字*/
      *s++ = *str++;
    }
    /*赋值一个单词,单词个数w减一,单词为零,终止,return*/
    if (--w == 0) {
      return; /*全部单字复制完毕,返回*/
    }
    /*赋值一个单词之后,紧接着赋值计算出的平均空白给s*/
    for (i = 0; i < v; ++i) {
      *s++ = ' '; /*插入间隔空白符*/
    }
    /*如果总空白数sp % (w-1)有余数r非0,则将,多余的空白符,*/
    int tmpr = r;
    while (tmpr) { /*循环r次,保证每个单词之间的间隔都是一样的*/
      *s++ = ' '; /*插入一个多余空白符*/
      --tmpr;
    }
  }
}

int main(void) {
  puts("This is a type set program!\nPlease input a character line:\n");
  char buff[N];
  memset(buff, '\0', sizeof(buff) / sizeof(buff[0]));
  fgets(buff, N, stdin);
  printf("The character line before typeset is address:%p :%s\n", buff, buff);
  edit(buff);
  /*传入函数的指针,是复制了一个指针在函数里操作,函数外的指针还是在字符串开头未变*/
  printf("The character line before typeset is address:%p :%s\n", buff, buff);
  return 0;
}
