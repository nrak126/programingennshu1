//
//  04_challenge2_K24142.c
//  prg1
//
//  Created by k24142kk on 2024/05/09.
//
#include <stdio.h>

int main(int argc, const char *argv[]) {
    int total, legs, crane, tortoise;

    printf("total? ");
    scanf("%d", &total);
    printf("legs? ");
    scanf("%d", &legs);

    crane = total * 2 - legs / 2;
    tortoise = total - crane;

    if(total = crane + tortoise && legs == 2 * crane + 4 * tortoise) {
        printf("crane = %d, tortoise = %d\n", crane, tortoise);
    } else {
        printf("cannot be combined\n");
    }
    return 0;
}
