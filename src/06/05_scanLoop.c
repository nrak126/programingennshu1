#include <stdio.h>

int main(int argc, const char* argv[]) {
  int a;

  for (int i = 1; i <= 5; i++) {
    printf("a? ");
    scanf("%d", &a);
    printf("%d: %d\n", i, a);
  }

  return 0;
}
