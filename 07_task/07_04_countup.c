#include <stdio.h>

int main(int argc, const char* argv[]) {
  int n, i;
  printf("n? ");
  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    printf("%d\n", i);
  }

  return 0;
}
