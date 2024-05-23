#include <stdio.h>

int main(int argc, const char* argv[]) {
  int n, x, i, j, k, count;
  printf("n x? ");
  scanf("%d %d", &n, &x);
  count = 0;

  // iの範囲は1からnまで
  for (i = 1; i <= n; i++) {
    // jの範囲は1からx-i-1まで
    for (j = 1; j < x - i; j++) {
      k = x - i - j;
      // kが正の数であり、n以下であることを確認
      if (k > 0 && k <= n) {
        printf("%d%d%d\n", i, j, k);
        count++;
      }
    }
  }

  printf("組合せの数: %d\n", count);
  return 0;
}
