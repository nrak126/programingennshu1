#include <stdio.h>

int main(int argc, const char* argv[]) {
  int x, max = 0;
  for (int i = 1; i <= 5; i++) {
    printf("%d? ", i);
    scanf("%d", &x);
    if (x > max) {
      max = x;
    }
  }
  printf("max = %d\n", max);
  return 0;
}
