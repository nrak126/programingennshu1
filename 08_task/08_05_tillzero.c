#include <stdio.h>

int main(int argc, const char* argv[]) {
  int wallet = 1000, amount;

  while (1) {
    printf("amount? ");
    scanf("%d", &amount);

    if (amount <= 0) {
      printf("残高: %d\n", wallet);
      break;
    }

    wallet -= amount;
    printf("残高: %d\n", wallet);
  }

  return 0;
}
