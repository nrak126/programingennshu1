#include <stdio.h>
#define MAP_SIZE 20

void showMap(char map[][MAP_SIZE]) {
    for(int i = 0; i < MAP_SIZE; i++) {
        for(int j = 0; j < MAP_SIZE; j++)
            printf("%c", map[i][j]);

        printf("\n");
    }
}

int main(int argc, const char *argv[]) {
    int timeOfMove = 0;
    printf("ROTATION MAZE\n");
    printf("一手の制限時間を指定してください...");
    scanf("%d", &timeOfMove);

    char map[MAP_SIZE][MAP_SIZE];

    for(int i = 0; i < MAP_SIZE; i++) {
        for(int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = '#';
        }
    }

    showMap(map);

    return 0;
}