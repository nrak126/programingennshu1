#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 21
#define HEIGHT 21

#define WALL '#'
#define PATH ' '

typedef struct {
    int x, y;
} Point;

void initializeMaze(char maze[HEIGHT][WIDTH]);
void printMaze(char maze[HEIGHT][WIDTH]);
void digMaze(char maze[HEIGHT][WIDTH], int x, int y);

int main() {
    srand(time(NULL));

    char maze[HEIGHT][WIDTH];
    initializeMaze(maze);
    digMaze(maze, 1, 1); // スタート地点を(1, 1)に設定
    printMaze(maze);

    return 0;
}

void initializeMaze(char maze[HEIGHT][WIDTH]) {
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            maze[y][x] = WALL;
        }
    }
}

void printMaze(char maze[HEIGHT][WIDTH]) {
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            putchar(maze[y][x]);
            putchar(' ');
        }
        putchar('\n');
    }
}

void digMaze(char maze[HEIGHT][WIDTH], int x, int y) {
    const int directions[4][2] = {{0, -2}, {2, 0}, {0, 2}, {-2, 0}};
    int order[4] = {0, 1, 2, 3};

    maze[y][x] = PATH;

    // ランダムな順序で掘る方向を決める
    for(int i = 0; i < 4; i++) {
        int r = rand() % 4;
        int temp = order[i];
        order[i] = order[r];
        order[r] = temp;
    }

    for(int i = 0; i < 4; i++) {
        int nx = x + directions[order[i]][0];
        int ny = y + directions[order[i]][1];

        if(nx > 0 && nx < WIDTH && ny > 0 && ny < HEIGHT &&
           maze[ny][nx] == WALL) {
            maze[ny - directions[order[i]][1] / 2]
                [nx - directions[order[i]][0] / 2] = PATH;
            digMaze(maze, nx, ny);
        }
    }
}