/*************************************************************************
    > File Name: 26.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2019-04-19 04:12:59
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 4
#define COLS 4

/*参数合法性检查*/
void checknum(int val) { 
  if (val < 1 || val > 9999) {
    printf("The number must be in range 1..9999.\n");
    exit(0);
  }
}

/*将整数整数转换成罗马数字表示*/
/*
 * eg1:
 * decimal:88 roms[2][1] -> L(50)  roman:L
 * decimal:38 roms[2][3] -> X(10)  roman:LX
 * decimal:28 roms[2][3] -> X(10)  roman:LXX
 * decimal:18 roms[2][3] -> X(10)  roman:LXXX
 * decimal: 8 roms[3][1] -> V(5)   roman:LXXXV
 * decimal: 3 roms[3][3] -> I(1)   roman:LXXXVI
 * decimal: 2 roms[3][3] -> I(1)   roman:LXXXVII
 * decimal: 1 roms[3][3] -> I(1)   roman:LXXXVIII
 * 88 LXXXVIII
 *
 * eg2:
 * decimal:89 roms[2][1] -> L(50)  roman:L
 * decimal:39 roms[2][3] -> X(10)  roman:LX
 * decimal:29 roms[2][3] -> X(10)  roman:LXX
 * decimal:19 roms[2][3] -> X(10)  roman:LXXX
 * decimal: 9 roms[3][0] -> IX(9)  roman:LXXXIX
 * 89 LXXXIX
 * */
void to_roman(int decimal, char roman[], int nums[ROWS][COLS], char *roms[ROWS][COLS]) {
  memset(roman, '\0', sizeof(roman) / sizeof(roman[0]));
  int power, index;
  for (power = 0; power < ROWS; ++power) {
    for (index = 0; index < COLS; ++index) {
      while (decimal >= nums[power][index]) {
        /*一次将对应的罗马数字赋值给字符串roman*/
        strcat(roman, roms[power][index]);
        //printf("decimal:%2d roms[%d][%d] -> %s(%2d)  roman:%s\n", decimal, power, index, roms[power][index], nums[power][index], roman);
        /*要转换的整数减去已经转化的部分数字,再讲剩余的部分数字继续转换,并拼接在一起*/
        decimal -= nums[power][index];
      }
    }
  }
}

int main(int argc, char *argv[]) {
  int low, high;
  char roman[25];
  if (argc < 2) {
    printf("Usage: roman decimal_number\n"); /*运行程序需带整数参数*/
    printf("Example: %s 89 88\n", argv[0]); /*运行程序需带整数参数*/
    exit(0);
  }
  int i;
  printf("argc: %d\n", argc);
  for (i = 0; i < argc; ++i) {
    printf("argv[%d]: %s\n", i, argv[i]);
  }

  high = low = atoi(argv[1]); /*将第一个参数转换成整数*/
  checknum(low);
  if (argc > 2) { /*带两个参数*/
    high = atoi(argv[2]);
    checknum(high);
    /*保证high取到大值,low取到小值*/
    if (low > high) {
      low = high;
      high = atoi(argv[1]);
    } else {
      low = 1;
    }
  }
  printf("low = %d\thigh = %d\n", low, high);


  /*罗马数字7个基本字符: I(1)、V(5)、X(10)、L(50)、C(100)、D(500)、 M(1000)*/
  static int nums[ROWS][COLS] = {{1000, 1000, 1000, 1000}, {900, 500, 400, 100}, {90, 50, 40, 10}, {9, 5, 4, 1}};
  static char *roms[ROWS][COLS] = {{"M", "M", "M", "M"}, {"CM", "D", "CD", "C"}, {"XC", "L", "XL", "X"}, {"IX", "V", "IV", "I"}};
  for (; low <= high; ++low) {
    /*依次调用转换整数位罗马数字的方法*/
    to_roman(low, roman, nums, roms);
    printf("%d\t%s\n", low, roman);
  }
  return 0;
}
