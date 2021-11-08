#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Shark {
    int x, y, speed, dir, size;
};

const int MAX = 101;
const int dx[] = {0, -1, 1, 0, 0};
const int dy[] = {0, 0, 0, 1, -1};
int R, C, M;
Shark arr[MAX][MAX];
Shark tmp[MAX][MAX];
bool used[MAX][MAX];

void moveShark() {
    memset(tmp, {}, sizeof(tmp));

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (i == 2 && j == 4) {
                int sum = 1;
            }
            if (used[i][j]) {
                Shark now = arr[i][j];
                arr[i][j] = {};
                
                int d = now.dir;
                int s = now.speed;

                int nx = now.x;
                int ny = now.y;

                for (int k = 0; k < s; k++) {
                    if (nx + dx[d] < 1 || ny + dy[d] < 1 || nx + dx[d] > R || ny + dy[d] > C) {
                        d = d > 2 ? 7 - d : 3 - d;
                    }

                    nx += dx[d];
                    ny += dy[d];
                }

                now = {nx, ny, s, d, now.size};

                tmp[nx][ny] = now.size > tmp[nx][ny].size ? now : tmp[nx][ny];
                used[i][j] = false;
            }
        }
    }

    memset(used, false, sizeof(used));

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (tmp[i][j].size > 0) {
                used[i][j] = true;
                arr[i][j] = tmp[i][j];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C >> M;

    for (int i = 0; i < M; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        
        // 불필요한 왕복 제거 (중요)
        if (d <= 2) s %= (R - 1) * 2;
        else s %= (C - 1) * 2;

        arr[r][c] = {r, c, s, d, z};
        used[r][c] = true;
    }

    int answer = 0;
    // 낚시꾼이 한칸씩 이동

    if (M > 0) {
        for (int j = 1; j <= C; j++) {
            // j열에서 땅에서 가까운 상어 제거
            for (int i = 1; i <= R; i++) {
                if (used[i][j]) {
                    answer += arr[i][j].size;
                    arr[i][j] = {};
                    used[i][j] = false;
                    break;
                }
            }

            // 상어 이동
            moveShark();
        }
    }

    cout << answer;

    return 0;
}