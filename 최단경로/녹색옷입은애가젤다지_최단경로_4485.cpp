#include <iostream>
#include <queue>
#include <cstring>
#define INF 999
using namespace std;

int n;
const int MAX = 125;
int map[MAX][MAX];
int acc[MAX][MAX];

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

struct Node {
    int x, y;
};

int run() {
    priority_queue<pair<int, pair<int, int>>> q;
    q.push({-map[0][0], {0, 0}});
    acc[0][0] = map[0][0];

    while (!q.empty()) {
        int dist = -q.top().first;
        int x = q.top().second.first;
        int y = q.top().second.second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            int cost = dist + map[nx][ny];

            if (acc[nx][ny] > cost) {
                acc[nx][ny] = cost;
                q.push({-cost, {nx, ny}});
            }
        }
    }

    return acc[n - 1][n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int problem = 1;
    while (cin >> n && n != 0) {
        memset(map, 0, sizeof(map));
        memset(check, false, sizeof(check));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                acc[i][j] = INF;
            }
        }

        cout << "Problem " << problem++ << ": " << run() << '\n';

    }

    return 0;
}
