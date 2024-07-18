#include <stdio.h>

int main() {
    char array[11] = {'\0'}; // 10文字の文字列を格納する配列を初期化

    // キーボードから文字列を入力
    printf("入力(10文字以内): ");
    scanf("%10s", array); // 最大10文字を読み込む

    // 入力された文字列を印字
    printf("%s\n", array);

    return 0;
}