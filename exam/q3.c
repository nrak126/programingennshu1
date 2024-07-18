/*****************
問３
このプログラムの実行結果を書きなさい。
 *****************/

#include <stdio.h>

int myabs(int x) {
    if(x > 0)
        return x;
    else
        return -x;
}

int main() {
    int i, temp;

    for(i = 1; i <= 12; i++) {
        if(i != 2) {
            temp = myabs(i - 7.5) % 2;
            printf("%d ", 31 - temp);
        } else
            printf("?? ");
    }
    printf("\n");
    return 0;
}

// 解説
// 各月の日数を答えるプログラム

// 答え
// 31 ?? 31 30 31 30 31 31 30 31 30 31