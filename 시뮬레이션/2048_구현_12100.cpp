#include <iostream>
#include <vector>
using namespace std;

const int MAX = 21;
const int MAX_LEVEL = 5;
vector<int> v[MAX];
int N;
int maxx;

void clearV() {
    for (int i = 0; i < N; i++) {
        v[i].clear();
        v[i].resize(N, 0);
    }
}

void collision() {
    vector<int> tmp[MAX];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (v[i][j] == v[i][j + 1]) {
                v[i][j] *= 2;
                v[i][j + 1] = 0;
            }
        }
        
        for (int k = 0; k < N; k++) {
            if (v[i][k] != 0) {
                tmp[i].push_back(v[i][k]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        int size = tmp[i].size();
        
        if (size > 0) {
            v[i].clear();
            v[i].resize(N, 0);

            for (int j = 0; j < size; j++) {
                v[i][j] = tmp[i][j];
            }
        }
    }
}

void checkMAX(vector<vector<int>> board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] != 0) maxx = max(maxx, board[i][j]);
        }
    }
}

void moveUp(vector<vector<int>>& board) {
    clearV();

    for (int i = 0; i < N; i++) {
        int idx = 0;
        for (int j = 0; j < N; j++) {
            if (board[j][i] != 0) {
                v[i][idx++] = board[j][i];
            }
        }
    }

    collision();

    for (int i = 0; i < N; i++) {
        int idx = 0;
        for (int j = 0; j < N; j++) {
            board[j][i] = v[i][idx++];
        }
    }

    checkMAX(board);
}

void moveDown(vector<vector<int>>& board) {
    clearV();

    for (int i = 0; i < N; i++) {
        int idx = 0;
        for (int j = N - 1; j >= 0; j--) {
            if (board[j][i] != 0) {
                v[i][idx++] = board[j][i];
            }
        }
    }

    collision();

    for (int i = 0; i < N; i++) {
        int idx = 0;
        for (int j = N - 1; j >= 0; j--) {
            board[j][i]  = v[i][idx++];
        }
    }

    checkMAX(board);
}

void moveLeft(vector<vector<int>>& board) {
    clearV();

    for (int i = 0; i < N; i++) {
        int idx = 0;
        for (int j = 0; j < N; j++) {
            if (board[i][j] != 0) {
                v[i][idx++] = board[i][j];
            }
        }
    }

    collision();

    for (int i = 0; i < N; i++) {
        int idx = 0;
        for (int j = 0; j < N; j++) {
            board[i][j] = v[i][idx++];
        }
    }
    
    checkMAX(board);
}

void moveRight(vector<vector<int>>& board) {
    clearV();

    for (int i = 0; i < N; i++) {
        int idx = 0;
        for (int j = N - 1; j >= 0; j--) {
            if (board[i][j] != 0) {
                v[i][idx++] = board[i][j];
            }
        }
    }
    
    collision();

    for (int i = 0; i < N; i++) {
        int idx = 0;
        for (int j = N - 1; j >= 0; j--) {
            board[i][j] = v[i][idx++];
        }
    }

    checkMAX(board);
}

void run(vector<vector<int>> board, int dir, int level) {
    // 종료 조건
    if (level == MAX_LEVEL) {
        return;
    }

    vector<vector<int>> tmp = board;

    // 한쪽방향으로 다 옮기고
    if (dir == 0) moveUp(tmp);
    else if (dir == 1) moveDown(tmp);
    else if (dir == 2) moveLeft(tmp);
    else if (dir == 3) moveRight(tmp);

    for (int i = 0; i < 4; i++) {
        run(tmp, i, level + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> board(MAX, vector<int>(MAX));

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    maxx = -21e8;
    int level = 0;

    for (int i = 0; i < 4; i++) {   // 이 부분 참고함.. 시작점이 위, 아래, 좌, 우 일때의 케이스가 다름
        run(board, i, level);
    }
    cout << maxx << '\n';

    return 0;
}