/*************************************************************************
    > File Name: 39.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2019-04-25 06:39:23
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 80
#define MAXLINE 200

char buffer[MAXLEN], fname[120];
char *lineptr[MAXLINE];
FILE *fp;
char comch[] = "EeRrIiDdQq"; /*命令符*/
void edit(), replace(), insert(), delete(), quit();
void (*comfun[])() = {edit, replace, insert, delete, quit}; /*对应的处理函数*/
int modified = 0; /*正文被修改标志*/
int last; /*当前正文行数*/
char *chpt; /*驶入命令行字符指针*/

/*保存文件*/
void save(char *fname) {
  int i;
  FILE *fp;
  if ((fp = fopen(fname, "w")) == NULL) {
    fprintf(stderr, "Can't open %s.\n", fname);
    exit(1);
  }
  for (i = 0; i < last; ++i) {
    fputs(lineptr[i], fp);
    free(lineptr[i]);
  }
  fclose(fp);
}

/*退出函数*/
void quit() {
  int c;
  if (modified) { /*如正文被修改*/
    printf("Save?(y/n)");
    while (!(((c = getchar()) >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
      if (c == 'y' || c == 'Y') {
        save(fname); /*保存修改过的正文*/
      } 
    }
  }
  for (c = 0; c < last; ++c) {
    free(lineptr[c]); /*释放内存*/
  }
  exit(0);
}

void insert() {
  int k, m, i;
  sscanf(chpt, "%d%d", &k, &m); /*读入参数*/
  if (m < 0 || m > last || last + k >= MAXLINE) { /*检查参数合理性*/
    printf("Error!\n");
    return;
  }
  for (i = last; i > m; --i) { /*后继行向后移*/
    lineptr[i + k - 1] = lineptr[i - 1];
  }
  for (i = 0; i < k; ++i) {
    fgets(buffer, MAXLEN, stdin);
    lineptr[m + i] = (char *)malloc(strlen(buffer) + 1);
    strcpy(lineptr[m + i], buffer);
  }
  last += k; /*修正正文函数*/
  modified = 1; /*正文被修改*/
}

void delete() {
  int i, j, m, n;
  sscanf(chpt, "%d%d", &m, &n); /*读入参数*/
  if (m <= 0 || m > last || m < m) { /*检查参数合理性*/
    printf("Error!\n");
    return;
  }
  if (n > last) {
    n = last; /*修正参数*/
  }
  for (i = m; i <= n; ++i) { /*删除正文*/
    free(lineptr[i-1]);
  }
  for (i = m, j = n + 1; j <= last; ++i, ++j) {
    lineptr[i - 1] = lineptr[j-1];
  }
  last = i - 1; /*修正正文行数*/
  modified = 1; /*正文被修改*/
}

void replace() {
  int k, m, n, i, j;
  sscanf(chpt, "%d%d%d", &k, &m, &n); /*读入参数*/
  if (m <= 0 || m > last || n < m || last - (n - m + 1) +k >= MAXLINE) {
    printf("Error!\n");
    return;
  }
  /*先完成删除*/
  if (n > last)  {
    n = last; /*修正参数*/
  }
  for (i = m; i <= n; ++i) { /*删除正文*/
    free(lineptr[i-1]);
  }
  for (i = m, j = n + 1; j <= last; ++i, ++j) {
    lineptr[i - 1] = lineptr[j - 1];
  }
  /*以下完成插入*/
  for (i = last; i >= m; --i) {
    lineptr[i + k - 1] = lineptr[i - 1];
  }
  for (i = 0; i < k; ++i) {
    fgets(buffer, MAXLEN, stdin);
    lineptr[m + i - 1] = (char *)malloc(strlen(buffer) + 1);
    strcpy(lineptr[m + i - 1], buffer);
  }
  last += k; /*修正正文行数*/
  modified = 1; /*正文被修改*/
}


/*编辑命令*/
void edit() {
  int i;
  FILE *fp;
  i = sscanf(chpt, "%s", fname); /*读入文件名*/
  if (i != 1) {
    printf("Enter file name.\n");
    scanf("%s", fname);
  }
  if ((fp = fopen(fname, "r")) == NULL) { /*读打开*/
    fp = fopen(fname, "w"); /*如不存在,则创建文件*/
    fclose(fp);
    fp = fopen(fname, "r"); /*重新打开*/
  }
  i = 0;
  while (fgets(buffer, MAXLEN, fp) == buffer) {
    lineptr[i] = (char *)malloc(strlen(buffer) + 1);
    strcpy(lineptr[i++], buffer);
  }
  fclose(fp);
  last = i;
}

int main(void) {
  /*
  char buffer[MAXLEN], fname[120];
  char *lineptr[MAXLINE];
  FILE *fp;
  char comch[] = "EeRrIiDdQq"; //命令符
  void (*comfun[])() = {edit, replace, insert, delete, quit}; //对应的处理函数
  int modified = 0; //正文被修改标志
  int last; //当前正文行数
  char *chpt; //驶入命令行字符指针
  */

  int j;
  last = 0;
  while (1) {
    printf("Input a command:[e, r, i, d, q].\n");
    //gets(buffer); /*读入命令行*/
    fgets(buffer, MAXLEN, stdin);
    for (chpt = buffer; *chpt ==' ' || *chpt == '\t'; ++chpt); /*掠过空格和tab键*/
    if (*chpt == '\0') {
      continue; /*空行重新输入*/
    }
    for (j = 0; comch[j] != '\0' && comch[j] != *chpt; ++j); /*查命令符,直到comch[j]==*chpt*/
    if (comch[j] == '\0') { /*命令查询完(comch数组已经查完也)没有匹配的,是非法命令符*/
      continue;
    }
    ++chpt; /*掠过命令符,指向参数*/
    (*comfun[j / 2])(); /*执行对应函数*/
    fprintf(stdout, "The text is:\n");
    for (j = 0; j < last; ++j) { /*显示正文*/
      fputs(lineptr[j], stdout);
    }
  }
  return 0;
}
