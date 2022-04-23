#include <iostream>
#include <algorithm>
#define MAX 500
using namespace std;

int percent[9] = {1, 1, 2, 7, 7, 2, 10, 10, 5};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
const int bx[4][10] = {
    {-1, 1, -2, -1, 1, 2, -1, 1, 0, 0},
    {-1, -1, 0, 0, 0, 0, 1, 1, 2, 1},
    {-1, 1, -2, -1, 1, 2, -1, 1, 0, 0},
    {1, 1, 0, 0, 0, 0, -1, -1, -2, -1}
};
const int by[4][10] = {
    {1, 1, 0, 0, 0, 0, -1, -1, -2, -1},
    {-1, 1, -2, -1, 1, 2, -1, 1, 0, 0},
    {-1, -1, 0, 0, 0, 0, 1, 1, 2, 1},
    {-1, 1, -2, -1, 1, 2, -1, 1, 0, 0}
};

int N;
int board[MAX][MAX];
int answer; // 격자밖으로 나간 모래

void spreadSand(int x, int y, int dir) {
    int ret = 0;
    int originSand = board[x][y];

    for (int i = 0; i < 10; i++) {
        int sand;
        if (i != 9) {
            // 날라갈 모래의 양
            sand = originSand * percent[i] / 100;
            // 비율만큼 소멸
            board[x][y] -= sand;
        }
        else {
            // a에 들어갈 모래 = 비율만큼 다 날라가고 남은 값
            sand = board[x][y];
        }

        int nx = x + bx[dir % 4][i];
        int ny = y + by[dir % 4][i];
        
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
            ret += sand;
            continue;
        }
        
        board[nx][ny] += sand;
    }

    // 모래 소멸
    board[x][y] = 0;
    answer += ret;
}

void run() {
    int x = N / 2;
    int y = N / 2;
    int dir = 0;

    for (double i = 1.0; i <= N; i += 0.5) {
        for (int j = 0; j < (int)i; j++) {
            x += dx[dir % 4];
            y += dy[dir % 4];
            spreadSand(x, y, dir);
        }
        dir++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    run();

    cout << answer << '\n';

	return 0;
}
