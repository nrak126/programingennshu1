#include <stdio.h>

int main(int argc, const char *argv[]) {
    int a[5], x, y, temp;
    for(int i = 0; i < 5; i++)
        a[i] = i + 1;

    printf("何番目を入れ替えますか? ");
    scanf("%d %d", &x, &y);
    if(1 <= x && x <= 5 || 1 <= y && y <= 5) {
        x -= 1;
        y -= 1;

        temp = a[x];
        a[x] = a[y];
        a[y] = temp;

        for(int i = 0; i < 5; i++)
            printf("a[%d] = %d\n", i, a[i]);
    }
    return 0;
}