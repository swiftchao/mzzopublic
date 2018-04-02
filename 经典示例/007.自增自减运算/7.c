/* */
#include <stdio.h>
int main(void)
{
  int a = 5, b, c, i = 10;
  b = a++; /*a = 6 b = 5*/
  c = ++b; /*b = 6 c = 6 */
  
  printf("a = %d, b = %d, c = %d\n", a, b, c); /*6 6 6*/
  /*这是因为printf函数的计算是从右向左进行的*/
  printf("i = %d, i++ = %d, i++ = %d\n", i, i++, i++); /*12 11 10*/
  printf("%d\n", ++i); /*13*/
  printf("%d\n", --i); /*12*/
  printf("%d\n", i++); /*12*/
  printf("%d\n", i--); /*13*/
  printf("%d\n", -i++); /*-12*/
  printf("%d\n", -i--); /*-13*/
  return 0;
}