#include <iostream>
#include <queue>
using namespace std;

int map[3][7] = {
    0, 1, 1, 1, 1, 1, 0,
    0, 1, 0, 0, 1, 0, 1,
    0, 1, 1, 1, 1, 1, 0
};
bool visit[3][7] = { false };

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

struct Node {
    int x, y;
};

int main() {

    // (0, 1)이 포함되어 있는 섬의 크기를 구하라
    queue<Node> q;
    q.push({0, 1});
    visit[0][1] = true;

    int maxSize = 0;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 3 || ny >= 7) continue;
            if (map[nx][ny] == 0 || visit[nx][ny]) continue;

            visit[nx][ny] = true;
            q.push({nx, ny});
            maxSize++;
        }
    }
    
    cout << maxSize;

    return 0;
}