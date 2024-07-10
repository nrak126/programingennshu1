#include <stdio.h>
#define MAP_SIZE 10
#define WALL '#'

void showMap(char map[][MAP_SIZE]) {
    for(int i = 0; i < MAP_SIZE; i++) {
        for(int j = 0; j < MAP_SIZE; j++)
            printf("%c", map[i][j]);
        printf("\n");
    }
}

void generateMap(char map) {}

int main(int argc, const char *argv[]) {
    int timeOfMove = 0;
    printf("ROTATION MAZE\n");
    printf("一手の制限時間を指定してください...");
    scanf("%d", &timeOfMove);

    char map[MAP_SIZE][MAP_SIZE];

    for(int i = 0; i < MAP_SIZE; i++) {
        for(int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = WALL;
        }
    }

	

    showMap(map);

    return 0;
}