#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 101
using namespace std;

const int dx[] = {0, -1, 1, 0, 0};
const int dy[] = {0, 0, 0, 1, -1};
int R, C, M;
struct Node {
    int speed, dir, size;
};
Node map[MAX][MAX];
Node cpy[MAX][MAX];

int fishing(int idx) {
    int size = 0;
    for (int i = 1; i <= R; i++) {
        if (map[i][idx].size > 0) {
            size += map[i][idx].size;
            map[i][idx] = {0, 0, 0};
            break;
        }
    }

    return size;
}

void moving() {
    memset(cpy, {}, sizeof(cpy));

    for (int x = 1; x <= R; x++) {
        for (int y = 1; y <= C; y++) {
            if (map[x][y].size > 0) {

                int speed = map[x][y].speed;
                int dir = map[x][y].dir;
                int size = map[x][y].size;
                int nx = x;
                int ny = y;

                while (speed--) {
                    nx += dx[dir];
                    ny += dy[dir];

                    if (nx < 1 || nx > R || ny < 1 || ny > C) {
                        speed++;
                        nx -= dx[dir];
                        ny -= dy[dir];
                        dir = dir >= 3 ? 7 - dir : 3 - dir;
                    }
                }

                if (size > cpy[nx][ny].size) cpy[nx][ny] = {map[x][y].speed, dir, size};
            }
        }
    }

    memcpy(map, cpy, sizeof(map));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C >> M;

    int x, y, speed, dir, size;
    int answer = 0;

    if (M > 0) {
        for (int i = 0; i < M; i++) {
            cin >> x >> y >> speed >> dir >> size;

            // ********* 불필요한 왕복 제거 (중요) *********
            if (dir <= 2) speed %= (R - 1) * 2;
            else speed %= (C - 1) * 2;
            
            map[x][y] = {speed, dir, size};
        }


        for (int i = 1; i <= C; i++) {
            answer += fishing(i);
            moving();
        }
    }

    cout << answer;

    return 0;
}