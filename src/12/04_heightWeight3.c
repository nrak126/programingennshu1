
#include <stdio.h>

int main(int argc, const char *argv[]) {
    int human[3][2] = {0};

    for(int i = 0; i < 3; i++) {
        printf("%d人目の身長と体重? ", i + 1);
        for(int j = 0; j < 2; j++) {
            scanf("%d", &human[i][j]);
        }
    }

    for(int i = 0; i < 3; i++) {
        printf("%d人目の身長と体重は ", i + 1);
        for(int j = 0; j < 2; j++) {
            printf("%d", human[i][j]);
            if(j == 0)
                printf(" ");
            else
                printf("\n");
        }
    }

    return 0;
}
