/*************************************************************************
    > File Name: 32.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2019-04-24 04:18:29
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ZIPLEN 10 /*邮政编码数组的长度*/
#define PHONLEN 15 /*电话号码数组的长度*/

struct addr {
  char *name; /*姓名*/
  char *address; /*地址*/
  char zip[ZIPLEN]; /*邮政编码*/
  char phone[PHONLEN]; /*电话号码*/
};

/*函数readaddr用于输入一个通信录函数*/
int readaddr(struct addr *dpt) {
  int len;
  char buf[120]; /*输入字符串缓冲区*/
  memset(buf, '\0', sizeof(buf) / sizeof(buf[0]));

  printf("Please input the Name:\n"); /*输入姓名*/
  if (scanf("%s", buf) == 1) {
    len = strlen(buf);
    dpt->name = (char *)malloc(len + 1); /*申请存储姓名的空间*/
    strcpy(dpt->name, buf);
  } else {
    return 0; /*WindowsCtrl+z结束输入,Linux/Unix下使用Ctrl+d结束输入*/
  }

  printf("Please input the Address:\n"); /*输入地址*/
  if (scanf("%s", buf) == 1) {
    len = strlen(buf);
    dpt->address = (char *)malloc(len + 1); /*申请存储地址的空间*/
    strcpy(dpt->address, buf);
  } else {
    free(dpt->name); /*释放存储姓名的空间*/
    return 0; /*WindowsCtrl+z结束输入,Linux/Unix下使用Ctrl+d结束输入*/
  }

  printf("Please input the Zip code:\n"); /*输入邮编*/
  if (scanf("%s", buf) == 1) {
    strcpy(dpt->zip, buf);
  } else {
    free(dpt->name); /*释放存储姓名的空间*/
    free(dpt->address); /*释放存储地址的空间*/
    return 0; /*WindowsCtrl+z结束输入,Linux/Unix下使用Ctrl+d结束输入*/
  }

  printf("Please input the Phone number:\n"); /*输入电话号码*/
  if (scanf("%s", buf) == 1) {
    strcpy(dpt->phone, buf);
  } else {
    free(dpt->name);
    free(dpt->address);
    return 0; /*WindowsCtrl+z结束输入,Linux/Unix下使用Ctrl+d结束输入*/
  }
  return 1;
}

int writeaddr(struct addr *dpt) {
  printf("Name    : %s\n", dpt->name); /*输出姓名*/
  printf("Address : %s\n", dpt->address); /*输出地址*/
  printf("Zip     : %s\n", dpt->zip); /*输出邮编*/
  printf("Phone   : %s\n\n", dpt->phone); /*输出电话号码*/
  return 0;
}

int main(void) {
  struct addr p[100];
  int i, j;
  /*读取通讯录*/
  for (i = 0; readaddr(p + i); ++i);
  /*输出通讯录*/
  for (j = 0; j < i; ++j) {
    writeaddr(p + j);
  }
  return 0;
}
