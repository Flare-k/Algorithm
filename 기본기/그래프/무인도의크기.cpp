#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

struct Node {
    int x, y;
};

int map[4][4];
bool visit[4][4];

queue<Node> island;

int totalSize = 0;

void BFS() {
    memset(visit, false, sizeof(visit));
    island.push({0, 0});
    visit[0][0] = true;

    while (!island.empty()) {
        Node now = island.front();
        island.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;
            if (map[nx][ny] == 0) continue;
            if (visit[nx][ny]) continue;

            visit[nx][ny] = true;
            island.push({nx, ny});
            totalSize++;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> map[i][j];
        }
    }

    BFS();

    cout << totalSize + 1;

    return 0;
}

/*
1 1 1 0
1 1 1 0
1 1 0 0
1 1 1 0
*/