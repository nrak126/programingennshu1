#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 6

// 方向を示す定数
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

void initializeMap(char map[][MAP_SIZE]) {
    for(int i = 0; i < MAP_SIZE; i++) {
        for(int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = '#'; // 全てのセルを壁で埋める
        }
    }
}

// 指定されたセルが迷路の境界内かどうかを確認
int isInBounds(int x, int y) {
    return x > 0 && x < MAP_SIZE - 1 && y > 0 && y < MAP_SIZE - 1;
}

// 迷路を生成するための関数
void makeMap(char map[][MAP_SIZE]) {
    // 初期化
    initializeMap(map);
    srand(time(NULL)); // 乱数シードを初期化

    // スタート地点をランダムに選択
    int startX = 2;
    int startY = 2;
    map[startX][startY] = 's';

    // スタックを使用して深さ優先探索を実行
    int stack[MAP_SIZE * MAP_SIZE][2];
    int stackSize = 0;
    stack[stackSize][0] = startX;
    stack[stackSize][1] = startY;
    stackSize++;

    while(stackSize > 0) {
        // 現在の位置を取得
        int x = stack[stackSize - 1][0];
        int y = stack[stackSize - 1][1];
        stackSize--;

        // 掘り進めることができる方向を収集
        int directions[4] = {UP, RIGHT, DOWN, LEFT};
        int possibleDirections[4];
        int numPossibleDirections = 0;

        for(int i = 0; i < 4; i++) {
            int nx = x, ny = y;
            switch(directions[i]) {
            case UP:
                nx = x - 2;
                break;
            case RIGHT:
                ny = y + 2;
                break;
            case DOWN:
                nx = x + 2;
                break;
            case LEFT:
                ny = y - 2;
                break;
            }

            if(isInBounds(nx, ny) && map[nx][ny] == '#') {
                possibleDirections[numPossibleDirections] = directions[i];
                numPossibleDirections++;
            }
        }

        if(numPossibleDirections > 0) {
            // ランダムな方向を選択
            int dir = possibleDirections[rand() % numPossibleDirections];
            int nx = x, ny = y;
            switch(dir) {
            case UP:
                nx = x - 2;
                map[x - 1][y] = ' ';
                break;
            case RIGHT:
                ny = y + 2;
                map[x][y + 1] = ' ';
                break;
            case DOWN:
                nx = x + 2;
                map[x + 1][y] = ' ';
                break;
            case LEFT:
                ny = y - 2;
                map[x][y - 1] = ' ';
                break;
            }

            // 新しい位置を通路に設定し、スタックに追加
            map[nx][ny] = ' ';
            stack[stackSize][0] = nx;
            stack[stackSize][1] = ny;
            stackSize++;
            stack[stackSize][0] = x;
            stack[stackSize][1] = y;
            stackSize++;
        }
    }
}

// 迷路を表示する関数
void showMap(char map[][MAP_SIZE]) {
    for(int i = 0; i < MAP_SIZE; i++) {
        for(int j = 0; j < MAP_SIZE; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, const char *argv[]) {
    char map[MAP_SIZE][MAP_SIZE];

    // 迷路を生成
    makeMap(map);

    // 迷路を表示
    showMap(map);

    return 0;
}