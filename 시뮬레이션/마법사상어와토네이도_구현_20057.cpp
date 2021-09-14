#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

// 서 남 동 북
const int MAX = 500;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

int N, dir;
int num = 1, answer;
int arr[MAX][MAX];    // [MAX]
double sandRate[5][5] = {
    {0, 0, 0.02, 0, 0},
    {0, 0.1, 0.07, 0.01, 0},
    {0.05, 0.45, 0, 0, 0},
    {0, 0.1, 0.07, 0.01, 0},
    {0, 0, 0.02, 0, 0}
};

void rotateSandRate() {
    double temp[5][5];

    memcpy(temp, sandRate, sizeof(sandRate));

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            sandRate[5 - (j + 1)][i] = temp[i][j];
        }
    }
}

int alphaValue(int original) {
    int sandSum = floor(original * 0.01) * 2 
                + floor(original * 0.02) * 2 
                + floor(original * 0.07) * 2 
                + floor(original * 0.1) * 2 
                + floor(original * 0.05);
    return original - sandSum;
}

void moveSand(int x, int y) {
    int originalSand = arr[x][y];
    arr[x][y] = 0;

    if (originalSand == 0) return;

    // 상하좌우 이동을 고려하여 -2~2로 설정 (중요)
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            double percent = sandRate[i + 2][j + 2];

            if (percent == 0) continue;

            int moveSand;

            if (percent < 0.40) {
                moveSand = floor(originalSand * percent);
            }
            else {
                moveSand = alphaValue(originalSand);
            }

            int nx = x + i;
            int ny = y + j;

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
                answer += moveSand;
                continue;
            }

            arr[nx][ny] += moveSand;
        }
    }
}

// 토네이도
void run(int x, int y) {
    int len = 1;

    while (1) {
        if (x == 0 && y == 0 ) break;

        for (int k = 0; k < 2; k++) {
            for (int i = 0; i < len; i++) {
                int nx = x + dx[dir % 4];
                int ny = y + dy[dir % 4];

                moveSand(nx, ny);
                
                x = nx;
                y = ny;
                
                if (x == 0 && y == 0 ) {
                    cout << answer;
                    return;
                }
            }

            dir++;
            rotateSandRate();
        }

        len++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    run(N / 2, N / 2);

    return 0;
}