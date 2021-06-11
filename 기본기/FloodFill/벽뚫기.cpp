#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

// 벽을 2개 뚫었을 때의 최단거리 구하기.
// 뚫는 개수가 2개 밖에 되지 않으므로 2개의 조합을 모두 구한다.
// 각 조합마다 BFS 돌려보기

struct Node {
    int x, y, level;
};
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int map[4][6] = {
    0, 0, 1 ,1 ,1, 1,
    1, 0, 1, 0, 0, 1,
    0, 0, 1, 0, 0, 1,
    0, 1, 1, 1, 1, 0
};

int backup[4][6];
bool visited[4][6];

int run() {
    queue<Node> q;
    memset(visited, false, sizeof(visited));

    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 4 || ny >= 6) continue;
            if (map[nx][ny] == 1) continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({nx, ny, now.level + 1});

            if (nx == 3 && ny == 5) return now.level + 1;
        }
    }

    return 21e8;
}


vector<Node> wall;
void init() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            if (map[i][j] == 1) wall.push_back({i, j});
        }
    }
}

int main() {

    // 벽 리스트업
    init();

    // 제거할 벽 선택
    int minV = 21e8;
    memcpy(backup, map, sizeof(map));
    for (int i = 0; i < wall.size(); i++) {
        for (int j = i + 1; j < wall.size(); j++) {
            memcpy(map, backup, sizeof(backup));

            map[wall[i].x][wall[i].y] = 0;
            map[wall[j].x][wall[j].y] = 0;

            // BFS
            int ret = run();
            if (ret < minV) minV = ret;
        }
    }

    cout << minV;

    return 0;
}