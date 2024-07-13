#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 21
#define HEIGHT 21

#define WALL '#'
#define PATH ' '
#define GOAL 'G'

typedef struct { // 座標を格納する構造体
    int x, y;
} Point;

void initializeMaze(char maze[HEIGHT][WIDTH]);        // 迷路を全て壁で埋める関数
void printMaze(char maze[HEIGHT][WIDTH]);             // 迷路を表示させる関数
void digMaze(char maze[HEIGHT][WIDTH], Point crrent); // 穴掘り法で迷路を整形する関数

int main() {
    srand(time(NULL));

    // 迷路の生成
    char maze[HEIGHT][WIDTH];
    Point startPoint = {1, 1};
    initializeMaze(maze);
    digMaze(maze, startPoint);

    // GOAL位置の設定
    maze[HEIGHT - 2][WIDTH - 2] = GOAL;
    printMaze(maze);

    // プレイヤーの移動処理
    Point playerPoint = startPoint;

    while(playerPoint.x != WIDTH && playerPoint.y != HEIGHT) {
        switch(getchar()) {
        case 'w':
            break;

        case 'a':
            break;

        case 's':
            break;

        case 'd':
            break;
        }
    }

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

void digMaze(char maze[HEIGHT][WIDTH], Point current) { // 深さ湯煎探索を使用して穴掘り法を行う
    const int directions[4][2] = {{0, -2}, {2, 0}, {0, 2}, {-2, 0}};
    int order[4] = {0, 1, 2, 3};

    maze[current.y][current.x] = PATH;

    for(int i = 0; i < 4; i++) { // ランダムな順序で掘る方向を決める
        int r = rand() % 4;
        int temp = order[i];
        order[i] = order[r];
        order[r] = temp;
    }

    for(int i = 0; i < 4; i++) {
        Point next = {current.x + directions[order[i]][0], current.y + directions[order[i]][1]};

        if(next.x > 0 && next.x < WIDTH && next.y > 0 && next.y < HEIGHT && maze[next.y][next.x] == WALL) { // もし掘り進められるのならば掘り進める
            maze[next.y - directions[order[i]][1] / 2][next.x - directions[order[i]][0] / 2] = PATH;
            digMaze(maze, next);
        }
    }
}