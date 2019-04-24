/*************************************************************************
    > File Name: 38.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2019-04-25 00:29:26
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define PAGELINE 20
#define PAGESPLINE 2
#define TXTWIDTH 30
#define TXTGAP 10

/*输出空行,调用一次pline值增加一次*/
void linecount() { /*完成对输出行的计数和一页满后,输出空行*/
  static int pline = 0; /*linecount函数调用一次pline增加一次*/
  int i;
  if (++pline == PAGELINE) { /*当pline等于PAGELINE(20)时输出一行空行*/
    for (i = 0; i < PAGESPLINE; ++i) { /*输出一页后的空行,输出PAGESPLINE行空行*/
      printf("\n");
    }
    pline = 0;
  }
}

/*读取一行,或者读取30个字符(当一行字符数大于30)*/
int readline(FILE *fpt) { /*完成从指定的文件中读出一行多至30个字符并输出*/
  int c, cpos = 0;
  while ((c = fgetc(fpt)) != '\n') {
    if (feof(fpt)) {
      break; /*文件结束退出循环*/
    }
    printf("%c", c);
    ++cpos;
    if (cpos >= TXTWIDTH) {
      break;
    }
  }
  return cpos; /*返回读入并输出的字符数*/
}

int main(void) {
  /*初始化值和对象*/
  FILE *fpt1, *fpt2; 
  char fname[120]; /*储存文件名*/
  int fill1, fill2; /*分别记录连个当前行读入并输出的字符数*/

  printf("Enter file 1 name:\n");
  scanf("%s", fname);
  fpt1 = fopen(fname, "r"); /*打开文件1*/
  if (fpt1 == NULL) {
    printf("Can't open file %s.\n", fname);
    exit(1);
  }

  printf("Enter file 2 name:\n");
  scanf("%s", fname);
  fpt2 = fopen(fname, "r");
  if (fpt2 == NULL) {
    printf("Can't open file %s.\n", fname);
    fclose(fpt1);
    exit(2);
  }

  /*读取输出内容*/
  while (!feof(fpt1) || !feof(fpt2)) { /*在有文件还未结束时循环*/
    fill1 = fill2 = 0;
    if (!feof(fpt1)) {
      fill1 = readline(fpt1); /*在文件末结束时读文件*/
    }
    /*
     * 不加占位符,输出是紧接着前面的输出,加上之后就是多少位输出之后再输出一个字符
     * 在printf中*代表占位符,第一次代表输出的总跳过(TXTWIDTH - fill1 + TXTGAP)读出的字符
     * */
    printf("%*c", TXTWIDTH - fill1 + TXTGAP, ' ');
    if (!feof(fpt2)) {
      fill2 = readline(fpt2);
    }
    printf("%*c%2d\n", TXTWIDTH - fill2 + 4, ' ', fill1 + fill2);
    linecount(); /*调用行计数函数*/
  }
  return 0;
}
