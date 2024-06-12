#include <stdio.h>
int main(int argc, const char* argv[]) {
  int a;
  printf("a? ");
  scanf("%d", &a);

  if (0 < a) printf("aは正の値です\n");
  printf("計算終了\n");

  return 0;
}
