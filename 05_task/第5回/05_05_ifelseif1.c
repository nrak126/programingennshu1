#include <stdio.h>
int main(int argc, const char* argv[]) {
  int a;
  printf("a? ");
  scanf("%d", &a);

  if (0 < a)
    printf("a は 正の値です\n");
  else if (a == 0)
    printf("aは0です\n");
  else
    printf("a は 負の値です\n");
  printf("計算終了\n");

  return 0;
}
