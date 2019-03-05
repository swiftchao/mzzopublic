/* */
#include <stdio.h>
int main()
{
  char ch, nch;  /* */
  int count;  /* */
  int k;    /* */

  printf("Please input a string with a # in the end.\n");
  scanf("%c",&ch);  /* */
  while(ch != '#')  /* 直到输入以#结尾结束循环，否则一直循环 */
  {
    if(ch >= '0' && ch <= '9')
    {
      /* */
      count = ch - '0' + 1;  /* */
      scanf("%c", &nch);  /* */
      for(k=0; k < count; k++)  /* */
      {
        printf("%c", nch);  /* 遇到输入的是数字 后面的字符 重复输出数字加一次*/
      }
    }
    else
    {
      printf("%c", ch);  /* */
    }
    
    printf(" ");      /* */
    scanf("%c", &ch);    /* */
  }
  printf("#\n");        /* */
  return 0;
}
