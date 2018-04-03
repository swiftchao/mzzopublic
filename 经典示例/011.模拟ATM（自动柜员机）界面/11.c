#include <stdio.h>

void main(void)
{
  char selectKey = '0', creditMoney = '0' , debitMoney = '0';
  while (1)
  {
    puts("\n\n=========================================");
    puts("| Please select key:                    |");
    puts("| 1.Query                               |");
    puts("| 2.Credit                              |");
    puts("| 3.Debit                               |");
    puts("| 4.Return                              |");
    puts("=========================================");
    selectKey = getchar();
    while (selectKey != '1' && selectKey != '2' && selectKey != '3' \
      && selectKey != '4')
    {
      selectKey = getchar();
    }
    switch (selectKey)
    {
      case '1':
        puts("================================");
        puts("|    Your balance is $1000.    |");
        puts("|  Press any key to return...  |");
        puts("================================");
        break;
      case '2':
        puts("==================================");
        puts("|   Please select Credit money:  |");
        puts("|   1. $50                       |");
        puts("|   2. $100                      |");
        puts("|   3. Return                    |");
        puts("==================================");
        creditMoney = getchar();
        while (creditMoney != '1' && creditMoney != '2' && creditMoney != '3')
        {
          creditMoney = getchar();
        }
        switch (creditMoney)
        {
          case '1':
            puts("=========================================");
            puts("|  Your Credit money is $50,Thank you!  |");
            puts("|         Press any key to return...    |");
            puts("=========================================");
            break;
          case '2':
            puts("=========================================");
            puts("|  Your Credit money is $100,Thank you! |");
            puts("|         Press any key to return...    |");
            puts("=========================================");
            break;
          case '3':
            break;
        }
        break;
      case '3':
        puts("====================================");
        puts("|   Please select Debit money:     |");
        puts("|   1. $50                         |");
        puts("|   2. $100                        |");
        puts("|   3. $500                        |");
        puts("|   4. $1000                       |");
        puts("|   5. Return                      |");
        puts("====================================");
        debitMoney = getchar();
        while (debitMoney != '1' && debitMoney != '2' && debitMoney != '3' && \
          debitMoney != '4' && debitMoney != '5')
        {
          debitMoney = getchar();
        }
        switch (debitMoney)
        {
          case '1':
            puts("===========================================");
            puts("|   Your Debit money is $50,Thank you!    |");
            puts("|        Press any key to return...       |");
            puts("===========================================");
            break;
          case '2':
            puts("===========================================");
            puts("|   Your Debit money is $100,Thank you!   |");
            puts("|        Press any key to return...       |");
            puts("===========================================");
            break;
          case '3':
            puts("===========================================");
            puts("|   Your Debit money is $500,Thank you!   |");
            puts("|        Press any key to return...       |");
            puts("===========================================");
            break;
          case '4':
            puts("===========================================");
            puts("|   Your Debit money is $1000,Thank you!  |");
            puts("|        Press any key to return...       |");
            puts("===========================================");
            break;
          case '5':
            break;
        }
        break;
      case '4':
        puts("================================");
        puts("|   Thank you for your using!  |");
        puts("|            Good bye!         |");
        puts("================================");
        return;
    }
  }
}
