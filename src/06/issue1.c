#include <stdio.h>

int main(int argc, const char* argv[]) {
  int n;
  double sum = 0.0;
  int height;

  printf("人数? ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    printf("%d人目の身長は? ", i);
    scanf("%d", &height);
    sum += height;
  }

  printf("平均身長: %lf\n", sum / n);

  return 0;
}
