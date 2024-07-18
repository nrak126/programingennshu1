#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

#define WIDTH 21
#define HEIGHT 21

#define TRICK 6

#define WALL '#'
#define PATH ' '
#define PLAYER 'P'
#define GOAL 'G'

// 座標の構造体
typedef struct {
    int x, y;
} Point;

// 関数プロトタイプ宣言
void initializeMaze(char maze[HEIGHT][WIDTH]);                               // 迷路を全て壁で埋める関数
void placePlayerAndGoal(char maze[HEIGHT][WIDTH], Point player, Point goal); // プレイヤーとゴールの位置を設定する関数
void digMaze(char maze[HEIGHT][WIDTH], Point current);                       // 穴掘り法で迷路を生成する関数
void movePlayer(char maze[HEIGHT][WIDTH], Point *player, char direction);    // プレイヤーの移動を処理する関数
void shuffleDirections(int directions[4]);                                   // 掘る方向をランダムにシャッフルする関数
void printMaze(char maze[HEIGHT][WIDTH]);                                    // 迷路を表示させる関数

// トリック関連
void trickMaze(char maze[HEIGHT][WIDTH], Point *player, Point *goal);          // トリックを実行する関数
void verticalInvertMaze(char maze[HEIGHT][WIDTH], Point *player, Point *goal); // 迷路を左右反転させる関数
void upsideDownMaze(char maze[HEIGHT][WIDTH], Point *player, Point *goal);     // 迷路を上下反転させる関数
void rotationMaze(char maze[HEIGHT][WIDTH], Point *player, Point *goal);       // 迷路を回転させる関数
void blindMaze(char maze[HEIGHT][WIDTH]);                                      // 迷路を暗転させる関数
void printTrick(void);                                                         // 今回&次に行うトリックを表示する関数

void printTitle(); // タイトル画面を表示する関数

void enableRawMode();  // ターミナルをrawモードに切り替える関数
void disableRawMode(); // ターミナルを元のモードに戻す関数

// グローバル変数
struct termios orig_termios;

int currentTrick = -1; // 現在のトリックの状態を追跡する変数
int nextTrick = -1;    // 次のトリックの状態を追跡する変数
int trickTurns = 0;    // 次に発生するトリックのターン数を格納する変数
int blindTurns = 0;    // 暗転状態の残りターン数

bool isMovedPlayer = false; // プレイヤーが移動したかどうか

int main() {
    srand(time(NULL)); // 乱数の種を設定

    enableRawMode(); // ターミナルをrawモードに切り替える

    printTitle(); // タイトル画面の表示

    char maze[HEIGHT][WIDTH];                  // 迷路を表す2次元配列
    Point startPoint = {1, 1};                 // スタート地点の座標
    Point goalPoint = {HEIGHT - 2, WIDTH - 2}; // ゴール地点の座標
    Point playerPoint = startPoint;            // プレイヤーの初期位置

    initializeMaze(maze);                            // 迷路を壁で埋める
    digMaze(maze, startPoint);                       // 穴掘り法で迷路を生成
    placePlayerAndGoal(maze, startPoint, goalPoint); // プレイヤーとゴールの位置を設定

    nextTrick = rand() % TRICK; // 次のトリックの状態を追跡する変数
    trickTurns = rand() % 7 + 3;

    printMaze(maze); // 迷路を表示
    printTrick();    // 次に発生するトリックのターン数を格納する

    while(true) {                             // プレイヤーがゴールに到達するまでループ
        char move = getchar();                // キー入力を取得
        movePlayer(maze, &playerPoint, move); // プレイヤーを移動
        if(trickTurns <= 1)
            trickMaze(maze, &playerPoint, &goalPoint);                     // トリックを発生させる関数
        printMaze(maze);                                                   // 迷路を表示
        printTrick();                                                      // 今回&次に行うトリックを表示する
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
    for(int y = 0; y < HEIGHT; y++)
        for(int x = 0; x < WIDTH; x++)
            maze[y][x] = WALL; // 全てのセルを壁にする
}

// プレイヤーとゴールの位置を設定する関数
void placePlayerAndGoal(char maze[HEIGHT][WIDTH], Point player, Point goal) {
    maze[player.y][player.x] = PLAYER; // プレイヤーの位置にPを設定
    maze[goal.y][goal.x] = GOAL;       // ゴールの位置にGを設定
}

// 迷路を表示する関数
void printMaze(char maze[HEIGHT][WIDTH]) {
    if(blindTurns > 1) {
        blindMaze(maze);
        return;
    }

    system("clear"); // 画面をクリア
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            if(maze[y][x] == PLAYER)
                printf("\x1b[96m%c\x1b[39m", maze[y][x]);
            else if(maze[y][x] == GOAL)
                printf("\x1b[91m%c\x1b[39m", maze[y][x]);
            else
                putchar(maze[y][x]); // セルを表示
            putchar(' ');            // セル間のスペースを表示
        }
        putchar('\n'); // 行の終わりに改行を表示
    }
}

// // 今回&次に行うトリックを表示する関数
void printTrick(void) {
    if(currentTrick != -1)
        printf("現在のトリック： ");
    switch(currentTrick) {
    case 0:
        printf("左右反転\n");
        break;
    case 1:
        printf("上下反転\n");
        break;
    case 2:
        printf("上下左右反転\n");
        break;
    case 3:
        printf("右回転\n");
        break;
    case 4:
        printf("左回転\n");
        break;
    case 5:
        printf("暗転\n");
        break;
    }

    if(isMovedPlayer) {
        trickTurns--;
        blindTurns--;
    }
    printf("次のトリックまであと %d ターン: ", trickTurns);
    switch(nextTrick) {
    case 0:
        printf("左右反転\n");
        break;
    case 1:
        printf("上下反転\n");
        break;
    case 2:
        printf("上下左右反転\n");
        break;
    case 3:
        printf("右回転\n");
        break;
    case 4:
        printf("左回転\n");
        break;
    case 5:
        printf("暗転\n");
        break;
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
        isMovedPlayer = true;
        maze[player->y][player->x] = PATH;   // 元の位置を通路に戻す
        *player = newPoint;                  // プレイヤーの新しい位置を設定
        maze[player->y][player->x] = PLAYER; // 新しい位置をプレイヤーに設定
    } else
        isMovedPlayer = false;
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

// トリックを実行する関数
void trickMaze(char maze[HEIGHT][WIDTH], Point *player, Point *goal) {
    currentTrick = nextTrick;
    trickTurns = rand() % 7 + 3;
    nextTrick = rand() % TRICK;

    switch(currentTrick) {
    case 0: // 左右反転
        verticalInvertMaze(maze, player, goal);
        break;
    case 1: // 上下反転
        upsideDownMaze(maze, player, goal);
        break;
    case 2: // 上下左右度回転
        verticalInvertMaze(maze, player, goal);
        upsideDownMaze(maze, player, goal);
        break;
    case 3: // 右回転
        rotationMaze(maze, player, goal);
        break;
    case 4: // 左回転
        rotationMaze(maze, player, goal);
        rotationMaze(maze, player, goal);
        rotationMaze(maze, player, goal);
        break;
    case 5: // 暗転
        blindTurns = trickTurns;
        break;
    }
}

// 迷路を左右反転させる関数
void verticalInvertMaze(char maze[HEIGHT][WIDTH], Point *player, Point *goal) {
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
void upsideDownMaze(char maze[HEIGHT][WIDTH], Point *player, Point *goal) {
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

// 迷路を右回転させる関数
void rotationMaze(char maze[HEIGHT][WIDTH], Point *player, Point *goal) {
    int temp[HEIGHT][WIDTH];
    for(int i = 0; i < HEIGHT; i++)
        for(int j = 0; j < WIDTH; j++)
            temp[j][WIDTH - i - 1] = maze[i][j]; // tempに右回転させたmazeを格納

    for(int i = 0; i < HEIGHT; i++)
        for(int j = 0; j < WIDTH; j++)
            maze[i][j] = temp[i][j]; // mazeにtempを格納

    int playerY = player->y;
    player->y = player->x;
    player->x = WIDTH - playerY - 1;

    int goalY = goal->y;
    goal->y = goal->x;
    goal->x = WIDTH - goalY - 1;
}

// 迷路を暗転させて表示する関数
void blindMaze(char maze[HEIGHT][WIDTH]) {
    system("clear"); // 画面をクリア
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            if(maze[y][x] == PLAYER)
                printf("\x1b[96m%c\x1b[39m", maze[y][x]);
            else if(maze[y][x] == GOAL)
                printf("\x1b[91m%c\x1b[39m", maze[y][x]);
            else
                putchar(' ');
            putchar(' '); // セル間のスペースを表示
        }
        putchar('\n'); // 行の終わりに改行を表示
    }
}

// タイトル画面を表示する関数
void printTitle(void) {
    system("clear");
    printf("\x1b[91m######  ####   ####  ##### ### ###    ###   ###    #     ###### ###### \n");
    printf("\x1b[93m# ## #  ## ##   ##  ##  ##  ##  #      ###  ##     ##    ##  ##  ##  # \n");
    printf("\x1b[93m  ##    ## ##   ##  ##      ## #       ### ###    ###    #  ##   ##    \n");
    printf("\x1b[92m  ##    ####    ##  ##      ####       # ## ##    # ##     ##    ###   \n");
    printf("\x1b[92m  ##    ## #    ##  ##      ## ##      # ## ##   #####    ##  #  ##    \n");
    printf("\x1b[94m  ##    ## ##   ##  ### ##  ## ###     #  # ##   #  ###  ##  ##  ##  # \n");
    printf("\x1b[35m ####  ### ### ####  ####  ###  ###   ###   ### ### #### ###### ###### \n");
    printf("\x1b[36mreturnを押してスタート...");
    printf("\x1b[39m");
    while(getchar() != '\n') { // エンターキーが押されるまで止まる
    }
}

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