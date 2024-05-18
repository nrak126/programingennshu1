//
//  04_06_if1.c
//  prg1
//
//  Created by k24142kk on 2024/05/09.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    int a;
    printf("a? ");
    scanf("%d", &a);
    if(0 < a) printf("aは正の値です\n");
    printf("計算終了\n");
    return 0;
}
