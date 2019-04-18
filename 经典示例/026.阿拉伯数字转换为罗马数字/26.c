/*************************************************************************
    > File Name: 26.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2019-04-19 04:12:59
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*参数合法性检查*/
void checknum(int val) { 
  if (val < 1 || val > 9999) {
    printf("The number must be in range 1..9999.\n");
    exit(0);
  }
}

/*将整数整数转换成罗马数字表示*/
void to_roman(int decimal, char roman[]) {
  #define ROWS 4
  #define COLS 4
  /*罗马数字7个基本字符: I(1)、V(5)、X(10)、L(50)、C(100)、D(500)、 M(1000)*/
  int nums[ROWS][COLS] = {{1000, 1000, 1000, 1000}, {900, 500, 400, 100}, {90, 50, 40, 10}, {9, 5, 4, 1}};
  char *roms[ROWS][COLS] = {{"M", "M", "M", "M"}, {"CM", "D", "CD", "C"}, {"XC", "L", "XL", "X"}, {"IX", "V", "IV", "I"}};
  memset(roman, '\0', sizeof(roman) / sizeof(roman[0]));
  int power, index;
  for (power = 0; power < ROWS; ++power) {
    for (index = 0; index < COLS; ++index) {
      while (decimal >= nums[power][index]) {
        strcat(roman, roms[power][index]);
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

  for (; low <= high; ++low) {
    to_roman(low, roman);
    printf("%d\t%s\n", low, roman);
  }
  return 0;
}
