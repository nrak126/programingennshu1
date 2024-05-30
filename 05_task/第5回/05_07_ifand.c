#include <stdio.h>
int main(int argc, const char* argv[]) {
  int a, b;
  printf("a? ");
  scanf("%d", &a);
  printf("b? ");
  scanf("%d", &b);

  if (0 < a && 0 < b)
    printf("aとbは正です\n");
  else
    printf("aとbのどちらかは負もしくは0です\n");

  return 0;
}
