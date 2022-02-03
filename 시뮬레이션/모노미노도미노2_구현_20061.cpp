#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#define MAX 10
using namespace std;

int board[MAX][MAX];
int removeBlueCnt, removeGreenCnt;
int lightGreen, lightBlue;
bool lightFlag;
int score;
vector<int> green, blue;
int blocks;

// 초록색 보드로 이동
void blockMoveToGreenArea(int t, int x, int y) {
    if (t == 1) {
        for (int i = x; i < MAX; i++) {
            if (board[i][y] != 0) {
                board[i - 1][y] = t;
                break;
            }
            
            if (board[i][y] == 0 && i == MAX - 1) {
                board[i][y] = t;
            }
        }
    }
    else if (t == 2) {
        for (int i = x; i < MAX; i++) {
            if (board[i][y] != 0 || board[i][y + 1] != 0) {
                board[i - 1][y] = t;
                board[i - 1][y + 1] = t;
                break;
            }

            if (board[i][y] == 0 && board[i][y + 1] == 0 && i == MAX - 1) {
                board[i][y] = t;
                board[i][y + 1] = t;
            }
        }
    }
    else if (t == 3) {
        for (int i = x; i < MAX; i++) {
            if (board[i][y] != 0) {
                board[i - 2][y] = t;
                board[i - 1][y] = t;
                break;
            }

            if (board[i][y] == 0 && board[i - 1][y] == 0 && i == MAX - 1) {
                board[i - 1][y] = t;
                board[i][y] = t;
            }
        }
    }
}

// 파란색 보드로 이동
void blockMoveToBlueArea(int t, int x, int y) {
    if (t == 1) {
        for (int j = y; j < MAX; j++) {
            if (board[x][j] != 0) {
                board[x][j - 1] = t;
                break;
            }

            if (board[x][j] == 0 && j == MAX - 1) {
                board[x][j] = t;
            }
        }
    }
    else if (t == 2) {
        for (int j = y; j < MAX; j++) {
            if (board[x][j] != 0) {
                board[x][j - 1] = t;
                board[x][j - 2] = t;
                break;
            }

            if (board[x][j] == 0 && board[x][j - 1] == 0 && j == MAX - 1) {
                board[x][j - 1] = t;
                board[x][j] = t;
            }
        }
    }
    else if (t == 3) {
        for (int j = y; j < MAX; j++) {
            if (board[x][j] != 0 || board[x + 1][j] != 0) {
                board[x][j - 1] = t;
                board[x + 1][j - 1] = t;
                break;
            }

            if (board[x][j] == 0 && board[x + 1][j] == 0 && j == MAX - 1) {
                board[x][j] = t;
                board[x + 1][j] = t;
            }
        }
    }
}

// 가득찬 행/열이 있는지 체크하고 해당 행/열 인덱스를 벡터에 저장
bool checkFullArea() {
    removeBlueCnt = 0;
    removeGreenCnt = 0;
    green.clear();
    blue.clear();

    // green
    for (int i = 6; i < MAX; i++) {
        int cnt = 0;
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != 0) cnt++;
        }

        if (cnt == 4) {
            removeGreenCnt++;
            green.push_back(i);
        }
    }

    // blue
    for (int j = 6; j < MAX; j++) {
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            if (board[i][j] != 0) cnt++;
        }

        if (cnt == 4) {
            removeBlueCnt++;
            blue.push_back(j);
        }
    }

    if (removeBlueCnt != 0 || removeGreenCnt != 0) return true;
    return false;
}

void moveBlock() {
    score += green.size();
    score += blue.size();

    if (removeGreenCnt != 0) {
        for (int col : green) {
            for (int i = col; i >= 4; i--) {
                for (int j = 0; j < 4; j++) {
                    board[i][j] = board[i - 1][j];
                }
            }
        }
    }

    if (removeBlueCnt != 0) {
        for (int row : blue) {
            for (int j = row; j >= 4; j--) {
                for (int i = 0; i < 4; i++) {
                    board[i][j] = board[i][j - 1];
                }
            }
        }
    }
}

// 연한 영역에 있는지 체크
void lightArea() {
    lightFlag = false;
    lightGreen = 0;
    lightBlue = 0;

    for (int i = 4; i <= 5; i++) {
        int cnt = 0;
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != 0) {
                lightFlag = true;
                cnt++;
            }
        }

        if (cnt > 0) lightGreen++;
    }

    for (int j = 4; j <= 5; j++) {
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            if (board[i][j] != 0) {
                lightFlag = true;
                cnt++;
            }
        }

        if (cnt > 0) lightBlue++;
    }
}

// 연한 영역에 있는 경우 한 칸씩 밀기
void lightMove() {
    while (lightGreen--) {
        for (int i = MAX - 1; i >= 4; i--) {
            for (int j = 0; j < 4; j++) {
                board[i][j] = board[i - 1][j];
            }
        }
    }

    while (lightBlue--) {
        for (int j = MAX - 1; j >= 4; j--) {
            for (int i = 0; i < 4; i++) {
                board[i][j] = board[i][j - 1];
            }
        }
    }
}

void checkBlockCnt() {
    for (int i = 6; i < MAX; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != 0) blocks++;
        }
    }

    for (int j = 6; j < MAX; j++) {
        for (int i = 0; i < 4; i++) {
            if (board[i][j] != 0) blocks++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    
    while (N--) {
        int t, x, y;
        cin >> t >> x >> y;

        // 1. 블록 이동
        blockMoveToGreenArea(t, x, y);
        blockMoveToBlueArea(t, x, y);

        // 2. 가득찬 경우 체크
        while (checkFullArea()) {
            moveBlock();
        }

        // 3. 연한 영역 체크
        lightArea();
        if (lightFlag) lightMove();
    }

    checkBlockCnt();

    cout << score << '\n';
    cout << blocks << '\n';

    return 0;
}