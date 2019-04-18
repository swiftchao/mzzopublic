/*************************************************************************
    > File Name: 22.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2019-04-18 22:45:55
 ************************************************************************/

#include <stdio.h>

int main(void) {
  int x, y, z; /*定义三个int型变量*/
  int *px = &x; /*定义指针变量px,并赋值为x的地址,使px指向x*/
  int *py = &y; /*定义指针变量py,并赋值为y的地址,使py指向y*/
  int *pz = &z; /*定义指针变量pz,并赋值为z的地址,使pz指向z*/
  int t;
  printf("Please input x, y, z:\n");
  scanf("%d%d%d", px, py, pz); /*通过变量的指针为变量输入值*/
  printf("Before replace value:\n");
  printf("px = %p\tpy = %p\tpz = %p\n", px, py, pz);
  printf("x = %d\ty = %d\tz = %d\n", x, y, z);
  if (*px > *py) { /*如果 x > y 互换 x 和 y的值*/
    /*利用指针的解引用替换*/
    t = *px;
    *px = *py;
    *py = t;
  }
  printf("After x and y replaced:");
  printf("x = %d\ty = %d\tz = %d\n", x, y, z);

  /*如果 x > z 互换 x 和 z 的值*/
  if (*px > *pz) {
    t = *px;
    *px = *pz;
    *pz = t;
  }
  printf("After x and z replaced:");
  printf("x = %d\ty = %d\tz = %d\n", x, y, z);

  
  /*普通的替换*/
  /*
  if (*py > *pz) {
    t = *py;
    *py = *pz;
    *pz = t;
  }
  */
  /*异或替换*/
  if (*py > *pz) {
    *py = *py ^ *pz;
    *pz = *py ^ *pz;
    *py = *py ^ *pz;
  }
  /*
   * (a ^ b) ^b = a
   * a和b互换
   * a = a ^ b;
   * b = b ^ a;
   * a = a ^ b;
   * */
  printf("After y and z replaced:");
  printf("x = %d\ty = %d\tz = %d\n", x, y, z);
  return 0;
}
