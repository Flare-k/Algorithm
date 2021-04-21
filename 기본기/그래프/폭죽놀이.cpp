#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

struct Node {
    int x, y, bomb;
};

int map[4][5];
bool visit[4][5];
int head, tail;
int maxBomb = -21e8;

queue<Node> fireWork;

void BFS() {
    memset(visit, false, sizeof(visit));

    while (!fireWork.empty()) {
        Node now = fireWork.front();
        fireWork.pop();

        for (int i = 0; i < 8; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 4 || ny >= 5) continue;
            if (map[nx][ny] == 1) continue;
            if (visit[nx][ny]) continue;

            visit[nx][ny] = true;
            fireWork.push({nx, ny, now.bomb + 1});
            
            map[nx][ny] = 1;
            
            maxBomb = max(maxBomb, now.bomb + 1);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(visit, false, sizeof(visit));

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                fireWork.push({i, j, 0});
                visit[i][j] = true;
            }
        }
    }

    BFS();

    cout << maxBomb;

    return 0;
}