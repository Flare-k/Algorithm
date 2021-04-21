#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

struct Node {
    int x, y, level;
};

char map[4][6];
bool visit[3][5];
int cnt = 0;

int BFS(int& x, int& y, int target) {
    memset(visit, false, sizeof(visit));
    queue<Node> q;

    q.push({x, y, 0});
    visit[x][y] = true;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 3 || ny >= 5) continue;
            if (map[nx][ny] == '#') continue;
            if (visit[nx][ny]) continue;

            visit[nx][ny] = true;
            q.push({nx, ny, now.level + 1});
            
            if (map[nx][ny] - '0' == target) {
                x = nx;
                y = ny;
                cnt = now.level + 1;
                return cnt;
            }
        }
    }

    return 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string num;
    for (int i = 0; i < 3; i++) {
        cin >> num;
        for (int j = 0; j < 5; j++) {
            map[i][j] = num[j];
        }
    }

    int ans = 0;
    int x = 0, y = 0;
    for (int i = 1; i <= 4; i++) {
        ans += BFS(x, y, i);
    }

    cout << ans << "회";

    return 0;
}
