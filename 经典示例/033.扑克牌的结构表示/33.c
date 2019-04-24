/*************************************************************************
    > File Name: 33.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2019-04-24 06:02:39
 ************************************************************************/

#include <stdio.h>
#include <string.h>

/*扑克牌花色4种*/
enum suits {
  CLUBS, /*0 梅花club*/
  DIAMONDS, /*1 方块diamond*/
  HEARTS, /*2 红桃heart*/
  SPADES /* 3 黑桃spade*/
};

struct card {
  enum suits suit; /*那种花色的扑克牌*/
  char value[3]; /*扑克牌的值*/
};

int main(void) {
  struct card deck[52]; /*扑克牌总共52张 = 13*4*/
  /*单个元素,最多三个字符10(2个字符)算上'\n',最多3个字符*/
  char cardval[][3] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
  //char *cardval[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
  /*单个元素最多9个字符DIAMONDS(8个字符)算上'\n' = 8 + 1 ==> 9*/
  char suitsname[][9] = {"CLUBS", "DIAMONDS", "HEARTS", "SPADES"};
  //char *suitsname[] = {"CLUBS", "DIAMONDS", "HEARTS", "SPADES"};
  //char *suitsname[4] = {"CLUBS", "DIAMONDS", "HEARTS", "SPADES"};
  int i, j;
  enum suits s;

  /*扑克牌一种花色共13张牌*/
  /*给扑克牌赋值*/
  for (i = 0; i <= 12; ++i) {
    for (s = CLUBS; s <= SPADES; ++s) {
      j = i * 4 + s;
      deck[j].suit = s;
      strcpy(deck[j].value, cardval[i]);
    }
  }

  /*输出扑克牌*/
  for (j = 0; j < 52; ++j) {
    printf("(%s%3s)%c", suitsname[deck[j].suit], deck[j].value, j % 4 == 3 ?'\n':'\t');
  }
  return 0;
}
