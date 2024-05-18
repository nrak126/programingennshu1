//
//  04_issue2_K24142.c
//  prg1
//
//  Created by k24142kk on 2024/05/09.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    int x;
    printf("x? ");
    scanf("%d", &x);
    
    if(x % 2 == 0) printf("even\n");
    else printf("odd\n");
    
    return 0;
}
