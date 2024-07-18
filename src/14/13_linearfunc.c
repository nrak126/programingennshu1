#include <stdio.h>

// 関数のプロトタイプ宣言
int f(int x);

int main() {
    int x;

    // x の値を 0 から 4 まで変化させて、f(x) の結果を出力する
    for(x = 0; x <= 4; x++) {
        printf("f(%d)=%d\n", x, f(x));
    }

    return 0;
}

// f(x)=2x+1 を表現する関数の定義
int f(int x) {
    return 2 * x + 1;
}