#include <stdio.h>

int main(int argc, const char* argv[]) {
  int x, sum = 0;

  while (1) {
    printf("x? ");
    scanf("%d", &x);

    if (x == 0) {
      printf("end\n");
      break;
    }

    sum += x;
    printf("sum: %d\n", sum);
  }

  return 0;
}
