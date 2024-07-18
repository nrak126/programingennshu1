/*****************
問２
閏年かどうか判定する問題。

閏年であれば「閏年である。」を出力。
閏年でなければ「閏年でない。」を出力。

閏年...
4で割り切れる年は閏年。
４００で割り切れる年を除いて１００で割り切れる年は閏年でない。

プログラムを完成させよ。
 *****************/

#include <stdio.h>

int main() {
    int year;

    printf("year? ");

    // 以下のプログラムを回答
    scanf("%d", &year);
    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        printf("閏年である。");
    else
        printf("閏年でない。");
    // 回答終了

    printf("\n");
    return 0;
}