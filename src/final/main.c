#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 21
#define HEIGHT 21

#define WALL '#'
#define PATH ' '
#define GOAL 'G'

typedef struct {
    int x, y;
} Point;

void initializeMaze(char maze[HEIGHT][WIDTH]);        // 迷路を全て壁で埋める関数
void printMaze(char maze[HEIGHT][WIDTH]);             // 迷路を表示させる関数
void digMaze(char maze[HEIGHT][WIDTH], int x, int y); // 穴掘り法で迷路を整形する関数

int main() {
    srand(time(NULL));

    char maze[HEIGHT][WIDTH];

    // 迷路の生成
    initializeMaze(maze);
    digMaze(maze, 1, 1);
    // GOAL位置の設定
    maze[HEIGHT - 2][WIDTH - 2] = GOAL;
    printMaze(maze);

    // プレイヤーの初期位置

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

void digMaze(char maze[HEIGHT][WIDTH], int x, int y) { // 深さ湯煎探索を使用して穴掘り法を行う
    const int directions[4][2] = {{0, -2}, {2, 0}, {0, 2}, {-2, 0}};
    int order[4] = {0, 1, 2, 3};

    maze[y][x] = PATH;

    for(int i = 0; i < 4; i++) { // ランダムな順序で掘る方向を決める
        int r = rand() % 4;
        int temp = order[i];
        order[i] = order[r];
        order[r] = temp;
    }

    for(int i = 0; i < 4; i++) {
        int nx = x + directions[order[i]][0];
        int ny = y + directions[order[i]][1];

        if(nx > 0 && nx < WIDTH && ny > 0 && ny < HEIGHT && maze[ny][nx] == WALL) { // もし掘り進められるのならば掘り進める
            maze[ny - directions[order[i]][1] / 2][nx - directions[order[i]][0] / 2] = PATH;
            digMaze(maze, nx, ny);
        }
    }
}