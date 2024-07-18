/*****************
問４
二次関数
ax^2 + bx + c = 0
のbとcを入力した時、
実数解の個数を出力するプログラムを書け。
 *****************/

// 以下回答
#include <stdio.h>

int main(int argc, const char *argv[]) {
    double b, c;
    printf("b c? ");
    scanf("%lf %lf", &b, &c);

    int ans;

    if(c < 0 || (b == 0 && c > 0)) // 虚数解
        ans = 0;
    else if(c == 0 || (b / 2 * b / 2 == c && c > 0))
        ans = 1;
    else
        ans = 2;

    printf("この関数の実数解は %d 個\n", ans);
    return 0;
}
// 回答終了

// 解説
// 自分は無理やりこの方法で解いたけど、判別式を使って解いた方がいいと思う。