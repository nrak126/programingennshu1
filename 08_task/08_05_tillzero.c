#include <stdio.h>

int main(int argc, const char* argv[]) {
  int wallet = 1000, amount;

  while (1) {
    printf("amount? ");
    scanf("%d", &amount);
    
    wallet -= amount;
    printf("残高: %d\n", wallet);

    if(wallet <= 0) break;
  }

  return 0;
}
