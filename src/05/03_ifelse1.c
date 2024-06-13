#include <stdio.h>
int main(int argc, const char *argv[]) {
    int a;
    printf("a? ");
    scanf("%d", &a);

    if(0 <= a)
        printf("a正の値もしくは0です\n");
    else
        printf("aは負の数です\n");
    printf("計算終了\n");

    return 0;
}
