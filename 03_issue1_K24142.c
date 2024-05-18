//
//  03_issue1_K24142.c
//  prg1
//
//  Created by k24142kk on 2024/04/25.
//

#include <stdio.h>

int main(int argc, const char * argv[]){
    int a, b, c;
    a = 6;
    b = 4;
    c = 2;
    printf("%d - (%d / %d) = %d\n", a, b, c, a - (b / c));
    return 0;
}
