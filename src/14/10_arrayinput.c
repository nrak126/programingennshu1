#include <stdio.h>

int main() {
    double heights[5] = {0}; // 5人分の身長を格納する配列
    double sum = 0;          // 身長の合計を格納する変数

    // 5人分の身長をキーボードから入力
    for(int i = 0; i < 5; i++) {
        printf("%d人目の身長? ", i + 1);
        scanf("%lf", &heights[i]);
        sum += heights[i];
    }

    // 平均身長を計算
    double average = sum / 5;

    // 平均身長を出力
    printf("平均身長 = %lf\n", average);

    return 0;
}