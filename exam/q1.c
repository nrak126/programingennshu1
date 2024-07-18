/*****************
問１
このプログラムの実行結果を書きなさい。
 *****************/

#include <stdio.h>

int main() {
    int d[] = {10, 5, -3, 28, 30};

    int d1 = d[0];
    int d2 = d[0];

    for(int i = 1; i < 5; i++) {
        if(d1 < d[i])
            d1 = d[i];
        if(d[i] < d2)
            d2 = d[i];
    }
    printf("%d, %d\n", d1, d2);
    return 0;
}

// 解説
// d1...配列dの最大値
// d2...配列dの最小値

// 答え
// 30, -3