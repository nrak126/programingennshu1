#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // UNIXシステム用のヘッダ
#include <termios.h> // キーボード入力用のヘッダ

#define WIDTH 10   // テトリスの幅
#define HEIGHT 20  // テトリスの高さ
#define EMPTY ' '  // 空のセル
#define BLOCK '*'  // ブロックのセル

char board[HEIGHT][WIDTH];  // テトリスの盤面
int currentX, currentY;     // 現在のブロックの位置
int score = 0;              // 得点

// キーボード入力を非ブロッキングに設定するための関数
void set_conio_terminal_mode() {
    struct termios ttystate;
    tcgetattr(STDIN_FILENO, &ttystate);
    ttystate.c_lflag &= ~(ICANON | ECHO); // カノニカルモードとエコーモードを無効化
    ttystate.c_cc[VMIN] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}

// キーボード入力のモードを元に戻す関数
void reset_terminal_mode() {
    struct termios ttystate;
    tcgetattr(STDIN_FILENO, &ttystate);
    ttystate.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}

// キーボード入力があるかどうかをチェックする関数
int kbhit() {
    struct timeval tv = { 0, 0 };
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);
    return select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv) == 1;
}

// 盤面を初期化する関数
void init_board() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = EMPTY;
        }
    }
}

// 新しいブロックを生成する関数
void new_block() {
    currentX = WIDTH / 2;
    currentY = 0;
}

// ブロックを盤面に描画する関数
void draw_block(int x, int y) {
    board[y][x] = BLOCK;
}

// ブロックを盤面から消す関数
void erase_block(int x, int y) {
    board[y][x] = EMPTY;
}

// ブロックを落とす関数
void drop_block() {
    erase_block(currentX, currentY);
    currentY++;
    draw_block(currentX, currentY);
}

// ブロックを左に移動する関数
void move_left() {
    erase_block(currentX, currentY);
    if (currentX > 0) {
        currentX--;
    }
    draw_block(currentX, currentY);
}

// ブロックを右に移動する関数
void move_right() {
    erase_block(currentX, currentY);
    if (currentX < WIDTH - 1) {
        currentX++;
    }
    draw_block(currentX, currentY);
}

// ブロックを回転する関数（シンプルな実装）
void rotate_block() {
    // 回転処理は省略（基本的なテトリスでは回転は実装しないことが多い）
}

// ラインが揃っているかをチェックし、揃ったらラインを消去する関数
void check_lines() {
    int lines_cleared = 0;
    for (int i = HEIGHT - 1; i >= 0; i--) {
        int line_full = 1;
        for (int j = 0; j < WIDTH; j++) {
            if (board[i][j] == EMPTY) {
                line_full = 0;
                break;
            }
        }
        if (line_full) {
            // ラインを消去
            for (int k = i; k > 0; k--) {
                for (int j = 0; j < WIDTH; j++) {
                    board[k][j] = board[k - 1][j];
                }
            }
            // 一番上の行を空にする
            for (int j = 0; j < WIDTH; j++) {
                board[0][j] = EMPTY;
            }
            lines_cleared++;
        }
    }
    // 得点計算（単純な方法）
    score += lines_cleared * 100;
}

// 盤面を表示する関数
void draw_board() {
    printf("\033[H\033[J"); // ANSIエスケープシーケンスで画面をクリア
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

int main() {
    init_board();
    new_block();

    set_conio_terminal_mode();

    while (1) {
        if (kbhit()) {
            char key = getchar();
            switch (key) {
                case 'a':
                    move_left();
                    break;
                case 'd':
                    move_right();
                    break;
                case 's':
                    drop_block();
                    break;
                case 'q':
                    reset_terminal_mode();
                    exit(0);
                    break;
            }
        }

        // ブロックを落とす
        usleep(300000); // 300ミリ秒ごとに更新（落下速度の調整）
        if (currentY < HEIGHT - 1) {
            erase_block(currentX, currentY);
            currentY++;
            draw_block(currentX, currentY);
        } else {
            // ブロックが底に着いたら次のブロックを生成
            check_lines();
            new_block();
        }

        draw_board();
    }

    reset_terminal_mode();

    return 0;
}