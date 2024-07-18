/*****************
問４
このプログラムは
data[0] = 15
data[1] = 12
data[2] = 3
data[3] = 4
data[4] = -4
と入力した時、
   15 :***** ***** *****
   12 :***** ***** **
    3 :***
    4 :****
   -4 :
を出力する。
棒グラフは、５文字おきにスペースを開ける。
（ヒント：%5dとすると綺麗に揃う）

データの入力と棒グラフを表示させるプログラムを答える問題。

プログラムを完成させよ。
 *****************/

#include <stdio.h>

int graph(int d) {
    int i;
    // 以下回答１
    printf("%5d :", d);
    for(i = 1; i <= d; i++) {
        printf("*");
        if(i % 5 == 0)
            printf(" ");
    }
    // 回答１終了
    printf("\n");
    return 0;
}

int main(int argc, const char *argv[]) {

    int data[5] = {};

    for(int i = 0; i < 5; i++) {
        // 以下回答２
        printf("data[i] = ");
        scanf("%d", &data[i]);
        // 回答２終了
    }

    for(int i = 0; i < 5; i++) {
        graph(data[i]);
    }

    return 0;
}