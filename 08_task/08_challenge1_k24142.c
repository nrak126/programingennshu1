#include <stdio.h>

int main(int argc, const char* argv[]) {
  int input, factor = 2;

  printf("正の整数を入力してください：");
  scanf("%d", &input);

  printf("素因数分解の結果は：");

  while (input > 1) {
    if (input % factor == 0) {
      printf("%d ", factor);
      input /= factor;
    } else {
      factor++;
    }
  }

  printf("\n");

  return 0;
}
