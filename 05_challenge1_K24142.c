#include <stdio.h>

int main() {
  int dayOfWeek;
  int time;
  int isOpen = 0;  // 0: 診察は行っていません, 1: 診察を行っています

  printf("曜日? ");
  scanf("%d", &dayOfWeek);

  printf("時間帯? ");
  scanf("%d", &time);

  if (time == 0) {
    if (dayOfWeek >= 1 && dayOfWeek <= 5) {
      isOpen = 1;
    }
  } else if (time == 1) {
    if ((dayOfWeek >= 1 && dayOfWeek <= 2) ||
        (dayOfWeek >= 4 && dayOfWeek <= 6)) {
      isOpen = 1;
    }
  }

  if (isOpen == 1) {
    printf("診察を行っています\n");
  } else {
    printf("診察は行っていません\n");
  }

  return 0;
}
