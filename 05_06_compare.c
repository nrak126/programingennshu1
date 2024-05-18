#include <stdio.h>
int main(int argc, const char* argv[]) {
  int a, b;
  printf("a b? ");
  scanf("%d %d", &a, &b);

  if (a > b)
    printf("a > b\n");
  else if (a == b)
    printf("a == b\n");
  else
    printf("a < b\n");

  return 0;
}
