#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

// 10 = 벽

int map[4][5] = {
    0, 0, 0, 2, 1,
    10, 10, 0, 4, 10,
    4, 10, 2, 10, 1,
    3, 0, 0, 3, 0
};
bool visit[4][5];

struct Node {
    int x, y, level;
};
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};


int run(int& x, int& y, int target) {
    queue<Node> q;
    memset(visit, false, sizeof(visit));
    q.push({x, y, 0});

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 4 || ny >= 5) continue;
            if (visit[nx][ny]) continue;
            if (map[nx][ny] == 10) continue;

            visit[nx][ny] = true;
            q.push({nx, ny, now.level + 1});

            if (target == map[nx][ny]) {
                x = nx;
                y = ny;
                return now.level + 1;
            }
        }
    }
    
    return -1;
}

int main() {

    int x = 0, y = 0;
    int dist = 0;
    // 1 ~ 4를 돌아다니며 가장 최단 거리로 가는 경우
    for (int i = 1; i <= 4; i++) {
        dist += run(x, y, i);
    }

    x = 0;
    y = 0;
    dist += run(x, y, 4);   // 4에서 0으로 돌아가는 경우 = 0에서 4로 가는 경우

    cout << dist;

    return 0;
}