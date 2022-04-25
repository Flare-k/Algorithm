#include <iostream>
#include <algorithm>
#define MAX 10
using namespace std;

int board[MAX][MAX];
int N, score;

void moveBlock(int t, int x, int y) {
    int nx, ny;
    bool flag;

    if (t == 1) {
        flag = false;

        for (int i = x; i < MAX - 1; i++) {
            if (board[i + 1][y] != 0) {
                flag = true;
                board[i][y] = t;
                break;
            }
        }

        if (!flag) board[MAX - 1][y] = t;

        flag = false;
        for (int j = y; j < MAX - 1; j++) {
            if (board[x][j + 1] != 0) {
                flag = true;
                board[x][j] = t;
                break;
            }
        }

        if (!flag) board[x][MAX - 1] = t;
    }
    else if (t == 2) {  // 1x2
        flag = false;

        for (int i = x; i < MAX - 1; i++) {
            if (board[i + 1][y] != 0 || board[i + 1][y + 1] != 0) {
                flag = true;
                board[i][y] = t;
                board[i][y + 1] = t;
                break;
            }
        }

        if (!flag) {
            board[MAX - 1][y] = t;
            board[MAX - 1][y + 1] = t;
        }

        flag = false;

        for (int j = y; j < MAX - 1; j++) {
            if (board[x][j + 1] != 0) {
                flag = true;
                board[x][j] = t;
                board[x][j - 1] = t;
                break;
            }
        }

        if (!flag) {
            board[x][MAX - 1] = t;
            board[x][MAX - 2] = t;
        }
    }
    else if (t == 3) {  // 2x1
        flag = false;

        for (int i = x; i < MAX - 1; i++) {
            if (board[i + 1][y] != 0) {
                flag = true;
                board[i][y] = t;
                board[i - 1][y] = t;
                break;
            }
        }

        if (!flag) {
            board[MAX - 1][y] = t;
            board[MAX - 2][y] = t;
        }

        flag = false;

        for (int j = y; j < MAX - 1; j++) {
            if (board[x][j + 1] != 0 || board[x + 1][j + 1] != 0) {
                flag = true;
                board[x][j] = t;
                board[x + 1][j] = t;
                break;
            }
        }

        if (!flag) {
            board[x][MAX - 1] = t;
            board[x + 1][MAX - 1] = t;
        }
    }
}

void checkGreenMuddyArea(int& green) {
    // 초록의 연한 곳
    for (int i = 4; i <= 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != 0) {
                green++;
                break;
            }
        }
    }
}

void checkBlueMuddyArea(int& blue) {
    // 파랑의 연한 곳
    for (int j = 4; j <= 5; j++) {
        for (int i = 0; i < 4; i++) {
            if (board[i][j] != 0) {
                blue++;
                break;
            }
        }
    }
}

bool checkGreenArea(int& cnt, int& row) {
    // 초록의 가득찬 행
    bool flag = false;

    for (int i = MAX - 1; i >= 6; i--) {
        int line = 0;
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != 0) line++;
        }

        if (line == 4) {
            row = max(row, i);
            cnt++;
            flag = true;
        }
    }

    if (flag) score += cnt;

    return flag;
}

bool checkBlueArea(int& cnt, int& col) {
    // 파랑의 가득찬 열
    bool flag = false;

    for (int j = MAX - 1; j >= 6; j--) {
        int line = 0;
        for (int i = 0; i < 4; i++) {
            if (board[i][j] != 0) line++;
        }

        if (line == 4) {
            col = max(col, j);
            cnt++;
            flag = true;
        }
    }

    if (flag) score += cnt;

    return flag;
}

void pullGreenArea(int& cnt, int& row) {
    for (int k = 0; k < cnt; k++) {
        for (int i = row - 1; i >= 3; i--) {
            for (int j = 0; j < 4; j++) {
                board[i + 1][j] = board[i][j];
            }
        }
    }
}

void pullBlueArea(int& cnt, int& col) {
    for (int k = 0; k < cnt; k++) {
        for (int j = col - 1; j >= 3; j--) {
            for (int i = 0; i < 4; i++) {
                board[i][j + 1] = board[i][j];
            }
        }
    }
}

void findAnswer() {
    int answer= 0;

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (board[i][j] != 0) answer++;
        }
    }

    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int t, x, y;
        cin >> t >> x >> y;

        moveBlock(t, x, y);

        int cnt, row, col;

        cnt = 0;
        row = 0;
        while (checkGreenArea(cnt, row)) {
            pullGreenArea(cnt, row);
        }

        cnt = 0;
        col = 0;
        while (checkBlueArea(cnt, col)) {
            pullBlueArea(cnt, col);
        }

        int green = 0, blue = 0;    // 땡겨야할 줄의 수
        checkGreenMuddyArea(green);
        checkBlueMuddyArea(blue);

        row = 9;
        col = 9;
        pullGreenArea(green, row);
        pullBlueArea(blue, col);
    }

    cout << score << '\n';
    findAnswer();

	return 0;
}