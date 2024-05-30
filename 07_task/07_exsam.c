#include <stdio.h>

int main(int argc, const char* argv[]) {
  int n, x, count = 0;
  printf("n x? ");
  scanf("%d %d", &n, &x);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if (i + j + k == x) {
          printf("%d%d%d\n", i, j, k);
          count++;
        }
      }
    }
  }

  printf("組み合わせの数: %d\n", count);
  return 0;
}
