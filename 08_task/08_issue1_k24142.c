#include <stdio.h>

int main(int argc, const char* argv[]) {
  int bank = 1000, wallet = 1000, amount;

  while (1) {
    printf("amount? ");
    scanf("%d", &amount);

    if (amount == 0 || bank <= 0 || wallet <= 0) {
      printf("取引終了\n");
      break;
    }

    if (amount > 0) {
      wallet -= amount;
      bank += amount;
    } else {
      bank += amount;
      wallet -= amount;
    }

    printf("銀行: %d 財布: %d\n", bank, wallet);
  }

  return 0;
}
