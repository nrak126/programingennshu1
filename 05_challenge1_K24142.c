#include <stdio.h>
int main(int argc, const char* argv[]) {
  int d, t;
  printf("曜日? ");
  scanf("%d", &d);
  printf("時間帯? ");
  scanf("%d", &t);

  int s[2][7] = {{0, 1, 1, 1, 1, 1, 0}, {0, 1, 1, 0, 1, 1, 1}};

  if (s[t][d])
    printf("診察を行なっています\n");
  else
    printf("診察を行なっていません\n");

  return 0;
}
