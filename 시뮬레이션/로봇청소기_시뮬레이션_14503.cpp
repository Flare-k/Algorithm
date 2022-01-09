#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

// 벽을 세 개 세웠을 때의 최대 안전영역의 크기는?
const int MAX = 51;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int N, M;
int map[MAX][MAX];
int tmp_map[MAX][MAX];
bool clean[MAX][MAX];
int answer;
enum {
    EMPTY, WALL
};

struct Robot {
    int x, y, dir;
};

queue<Robot> q;

void run() {

    while (!q.empty()) {
        Robot now = q.front();
        q.pop();

        // 1. 현재 위치 청소
        if (!clean[now.x][now.y]) answer++;
        clean[now.x][now.y] = true;

        int dir = now.dir;
        int nx, ny;
        int cnt = 0, wall = 0, _clean = 0;
        bool flag = false;

        // 2. 현재 위치에서 현재 방향을 기준으로 왼쪽 방향부터 차례대로 인접한 칸을 탐색
        // 0:북, 1:동, 2:남, 3:서
        while (cnt < 4) {
            cnt++;
            dir = dir - 1 < 0 ? 3 : dir - 1;

            nx = now.x + dx[dir];
            ny = now.y + dy[dir];

            if (nx < 0 || nx < 0 || nx >= N || ny >= M) continue;
            if (map[nx][ny] == WALL) wall++;
            if (map[nx][ny] == EMPTY && clean[nx][ny]) _clean++;
            if (map[nx][ny] == EMPTY && !clean[nx][ny]) {
                flag = true;
                break;
            }
        }

        if (flag) {
            q.push({nx, ny, dir});
        }
        else {
            if (wall <= 4 || _clean <= 4) {
                int d = now.dir % 2 == 0 ? 2 - now.dir : 4 - now.dir;
                nx = now.x + dx[d];
                ny = now.y + dy[d];

                if (map[nx][ny] == EMPTY) q.push({nx, ny, now.dir});
                else if (map[nx][ny] == WALL) return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    int x, y, dir;
    cin >> x >> y >> dir;
    q.push({x, y, dir});

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    run();

    cout << answer;

    return 0;
}