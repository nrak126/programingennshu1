#include <stdio.h>

int main(int argc, const char* argv[]) {
  int n;
  int isPrimeNumber = 1;  // 素数であると仮定

  printf("n? ");
  scanf("%d", &n);

  if (n < 2) {
    isPrimeNumber = 0;  // 2未満の数は素数ではない
  } else {
    for (int i = 2; i <= n / 2; i++) {
      if (n % i == 0) {
        isPrimeNumber = 0;  // 割り切れる数があれば素数ではない
        break;
      }
    }
  }

  if (isPrimeNumber) {
    printf("素数です\n");
  } else {
    printf("素数ではありません\n");
  }

  return 0;
}