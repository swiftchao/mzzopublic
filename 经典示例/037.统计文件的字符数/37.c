/*************************************************************************
    > File Name: 37.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2019-04-25 00:13:07
 ************************************************************************/

#include <stdio.h>

int main(void) {
  char fname[80]; /*存储文件名*/
  FILE *rfp;
  long count; /*文件字符计数器*/
  printf("Please input the file's name:\n");
  scanf("%s", fname);
  if ((rfp = fopen(fname, "r")) == NULL) {
    printf("Can't open file %s.\n", fname);
    return 0;
  }
  count = 0;
  while (fgetc(rfp) != EOF) {
    ++count;
  }
  fclose(rfp); /*关闭文件*/
  printf("There are %ld characters in file %s.\n", count, fname);
  return 0;
}
