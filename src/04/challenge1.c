//
//  04_chalenge1_K24142.c
//  prg1
//
//  Created by k24142kk on 2024/05/09.
//

#include <stdio.h>

int main(int argc, const char * argv[]){
    int x, y;
    printf("x? ");
    scanf("%d", &x);
    
    y = x / 100;
    x = x % 100;
    y += x / 10 * 10;
    x = x % 10;
    y += x * 100;
    
    printf("reverse = %d\n", y);
    return 0;
}
