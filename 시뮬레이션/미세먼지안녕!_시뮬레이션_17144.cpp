#include <iostream>
#include <cstring>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const int MAX = 51;
int R, C, T;
int map[MAX][MAX];
int tmp[MAX][MAX];
bool visit[MAX][MAX];

struct Dir {
    int x, y;
};

Dir cleaner1, cleaner2;

void diffuseFineDust() {
    memset(tmp, 0, sizeof(tmp));
    tmp[cleaner1.x][cleaner1.y] = -1;
    tmp[cleaner2.x][cleaner2.y] = -1;

    for (int x = 1; x <= R; x++) {
        for (int y = 1; y <= C; y++) {
            if (map[x][y] > 0) {
                int cnt = 0;
                int amount = (map[x][y] / 5);

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx < 1 || nx > R || ny < 1 || ny > C) continue;
                    if (map[nx][ny] == -1) continue;

                    cnt++;
                    tmp[nx][ny] += amount;
                }

                tmp[x][y] += (map[x][y] - amount * cnt);
            }
        }
    }

    memcpy(map, tmp, sizeof(map));
}

void runAirCleaner() {
    // cleaner 1
    int x = cleaner1.x;
    int y = cleaner1.y;
    
    for (int i = x - 1; i > 1; i--) {
        map[i][1] = map[i - 1][1];
    }
    
    for (int j = 1; j < C; j++) {
        map[1][j] = map[1][j + 1];
    }

    for (int i = 1; i < x; i++) {
        map[i][C] = map[i + 1][C];
    }

    for (int j = C; j > 2; j--) {
        map[x][j] = map[x][j - 1];
    }
    
    map[x][2] = 0;

    // cleaner 2
    x = cleaner2.x;
    y = cleaner2.y;

    for (int i = x + 1; i < R; i++) {
        map[i][1] = map[i + 1][1];
    }

    for (int j = 1; j < C; j++) {
        map[R][j] = map[R][j + 1];
    }

    for (int i = R; i > x; i--) {
        map[i][C] = map[i - 1][C];
    }

    for (int j = C; j > 2; j--) {
        map[x][j] = map[x][j - 1];
    }

    map[x][2] = 0;
}

int amountOfFineDust() {
    int sum = 0;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (map[i][j] != -1) sum += map[i][j];
        }
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C >> T;

    int cnt = 0;
    for (int x = 1; x <= R; x++) {
        for (int y = 1; y <= C; y++) {
            cin >> map[x][y];
            if (map[x][y] == -1 && cnt == 0) {
                cleaner1 = {x, y};
                cnt++;
            }
            else if (map[x][y] == -1 && cnt == 1) cleaner2 = {x, y};
        }
    }

    while (T--) {
        diffuseFineDust();
        runAirCleaner();
    }

    cout << amountOfFineDust();

    return 0;
}