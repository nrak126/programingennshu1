#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

#define WIDTH 21
#define HEIGHT 21

#define TRICK 2

#define WALL '#'
#define PATH ' '
#define PLAYER 'P'
#define GOAL 'G'

typedef struct {
    int x, y;
} Point;

// 関数プロトタイプ宣言
void initializeMaze(char maze[HEIGHT][WIDTH]);                               // 迷路を全て壁で埋める関数
void placePlayerAndGoal(char maze[HEIGHT][WIDTH], Point player, Point goal); // プレイヤーとゴールの位置を設定する関数
void printMaze(char maze[HEIGHT][WIDTH]);                                    // 迷路を表示させる関数
void digMaze(char maze[HEIGHT][WIDTH], Point current);                       // 穴掘り法で迷路を整形する関数
void movePlayer(char maze[HEIGHT][WIDTH], Point *player, char direction);    // プレイヤーの移動を処理する関数
void shuffleDirections(int directions[4]);                                   // 掘る方向をランダムにシャッフルする関数

void randomTrick(char maze[HEIGHT][WIDTH], Point *player, Point *goal);        // 確率でギミックを発生させる関数
void VerticalInvertMaze(char maze[HEIGHT][WIDTH], Point *player, Point *goal); // 迷路を左右反転させる関数
void UpsideDownMaze(char maze[HEIGHT][WIDTH], Point *player, Point *goal);     // 迷路を上下反転させる関数
void BlindMaze(char maze[HEIGHT][WIDTH]);                                      // 迷路を暗転させる関数

void enableRawMode();  // ターミナルをrawモードに切り替える関数
void disableRawMode(); // ターミナルを元のモードに戻す関数

// グローバル変数
struct termios orig_termios;

int main() {
    srand(time(NULL)); // 乱数の種を設定

    char maze[HEIGHT][WIDTH];                  // 迷路を表す2次元配列
    Point startPoint = {1, 1};                 // スタート地点の座標
    Point goalPoint = {HEIGHT - 2, WIDTH - 2}; // ゴール地点の座標
    Point playerPoint = startPoint;            // プレイヤーの初期位置

    initializeMaze(maze);                            // 迷路を壁で埋める
    digMaze(maze, startPoint);                       // 穴掘り法で迷路を整形
    placePlayerAndGoal(maze, startPoint, goalPoint); // プレイヤーとゴールの位置を設定

    enableRawMode(); // ターミナルをrawモードに切り替える

    printMaze(maze); // 迷路を表示

    while(true) {                             // プレイヤーがゴールに到達するまでループ
        char move = getchar();                // キー入力を取得
        movePlayer(maze, &playerPoint, move); // プレイヤーを移動
        randomTrick(maze, &playerPoint, &goalPoint);
        printMaze(maze);                                                   // 迷路を表示
        if(playerPoint.x == goalPoint.x && playerPoint.y == goalPoint.y) { // プレイヤーがゴールに到達したかを確認
            printf("Goal!!\n");                                            // ゴールメッセージを表示
            break;                                                         // ループを抜ける
        }
    }
    disableRawMode(); // ターミナルを元のモードに戻す
    return 0;         // プログラム終了
}

// 迷路を全て壁で埋める関数
void initializeMaze(char maze[HEIGHT][WIDTH]) {
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            maze[y][x] = WALL; // 全てのセルを壁にする
        }
    }
}

// プレイヤーとゴールの位置を設定する関数
void placePlayerAndGoal(char maze[HEIGHT][WIDTH], Point player, Point goal) {
    maze[player.y][player.x] = PLAYER; // プレイヤーの位置にPを設定
    maze[goal.y][goal.x] = GOAL;       // ゴールの位置にGを設定
}

// 迷路を表示する関数
void printMaze(char maze[HEIGHT][WIDTH]) {
    system("clear"); // 画面をクリア
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            putchar(maze[y][x]); // セルを表示
            putchar(' ');        // セル間のスペースを表示
        }
        putchar('\n'); // 行の終わりに改行を表示
    }
}

// 穴掘り法で迷路を整形する関数
void digMaze(char maze[HEIGHT][WIDTH], Point current) {
    const int directions[4][2] = {{0, -2}, {2, 0}, {0, 2}, {-2, 0}}; // 掘る方向のリスト
    int order[4] = {0, 1, 2, 3};                                     // 掘る方向の順序

    maze[current.y][current.x] = PATH; // 現在の位置を通路にする
    shuffleDirections(order);          // 掘る方向をランダムにシャッフル

    for(int i = 0; i < 4; i++) {
        Point next = {current.x + directions[order[i]][0], current.y + directions[order[i]][1]};
        if(next.x > 0 && next.x < WIDTH - 1 && next.y > 0 && next.y < HEIGHT - 1 && maze[next.y][next.x] == WALL) {
            maze[current.y + directions[order[i]][1] / 2][current.x + directions[order[i]][0] / 2] = PATH;
            digMaze(maze, next); // 再帰的に掘り進める
        }
    }
}

// プレイヤーの移動を処理する関数
void movePlayer(char maze[HEIGHT][WIDTH], Point *player, char direction) {
    Point newPoint = *player; // 新しい位置を設定
    switch(direction) {
    case 'w':
        newPoint.y--;
        break; // 上に移動
    case 'a':
        newPoint.x--;
        break; // 左に移動
    case 's':
        newPoint.y++;
        break; // 下に移動
    case 'd':
        newPoint.x++;
        break; // 右に移動
    }
    if(newPoint.x > 0 && newPoint.x < WIDTH && newPoint.y > 0 && newPoint.y < HEIGHT && maze[newPoint.y][newPoint.x] != WALL) {
        maze[player->y][player->x] = PATH;   // 元の位置を通路に戻す
        *player = newPoint;                  // プレイヤーの新しい位置を設定
        maze[player->y][player->x] = PLAYER; // 新しい位置をプレイヤーに設定
    }
}

// 掘る方向をランダムにシャッフルする関数
void shuffleDirections(int directions[4]) {
    for(int i = 0; i < 4; i++) {
        int r = rand() % 4;            // ランダムなインデックスを生成
        int temp = directions[i];      // 値を一時変数に保存
        directions[i] = directions[r]; // ランダムな方向に入れ替え
        directions[r] = temp;          // 一時変数の値を代入
    }
}

void randomTrick(char maze[HEIGHT][WIDTH], Point *player, Point *goal) {
    switch(rand() % TRICK) {
    case 0:
        VerticalInvertMaze(maze, player, goal);
        break;
    case 1:
        UpsideDownMaze(maze, player, goal);
        break;
    }
}
// 迷路を左右反転させる関数
void VerticalInvertMaze(char maze[HEIGHT][WIDTH], Point *player, Point *goal) {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH / 2; j++) {
            char temp = maze[i][j];              // 一時的にmaze[i][j]の値を保存
            maze[i][j] = maze[i][WIDTH - j - 1]; // 左側の値を右側に置き換える
            maze[i][WIDTH - j - 1] = temp;       // 一時的に保存しておいた値を右側に置き換える
        }
    }
    player->x = WIDTH - player->x - 1;
    goal->x = WIDTH - goal->x - 1;
}

// 迷路を上下反転させる関数
void UpsideDownMaze(char maze[HEIGHT][WIDTH], Point *player, Point *goal) {
    for(int i = 0; i < HEIGHT / 2; i++) {
        for(int j = 0; j < WIDTH; j++) {
            char temp = maze[i][j];
            maze[i][j] = maze[HEIGHT - i - 1][j];
            maze[HEIGHT - i - 1][j] = temp;
        }
    }
    player->y = HEIGHT - player->y - 1;
    goal->y = HEIGHT - goal->y - 1;
}
void BlindMaze(char maze[HEIGHT][WIDTH]); // 迷路を暗転させる関数

// ターミナルをrawモードに切り替える関数
void enableRawMode() {
    tcgetattr(STDIN_FILENO, &orig_termios);   // 現在のターミナル設定を取得
    struct termios raw = orig_termios;        // 現在の設定をコピー
    raw.c_lflag &= ~(ECHO | ICANON);          // エコーとカノニカルモードを無効にする
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw); // 新しい設定を適用
}

// ターミナルを元のモードに戻す関数
void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios); // 元のターミナル設定を復元
}