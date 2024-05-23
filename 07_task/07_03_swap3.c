#include <stdio.h>

int main(int argc, const char* argv[]) {
  int x, y, z, temp;
  printf("x y z? ");
  scanf("%d %d %d", &x, &y, &z);

  if (x > y) {
    temp = x;
    x = y;
    y = temp;
  }
  if (y > z) {
    temp = y;
    y = z;
    z = temp;
  }
  if (x > y) {
    temp = x;
    x = y;
    y = temp;
  }

  printf("%d %d %d\n", x, y, z);
  return 0;
}
