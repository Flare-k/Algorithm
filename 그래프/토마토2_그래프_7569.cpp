#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MAX = 100 + 1;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const int dz[] = {1, -1};
int box[MAX][MAX][MAX];
bool visit[MAX][MAX][MAX];
int M, N, H;  // 상자의 가로, 상자의 세로, 상자의 높이
queue<pair<pair<int, int>, int> > q;
int success = -1;

void BFS() {
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second;

        success = max(success, box[x][y][z]);

        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (box[nx][ny][z] == 0) {
                    box[nx][ny][z] = box[x][y][z] + 1;
                    q.push(make_pair(make_pair(nx, ny), z));
                }
            }
        }

        for (int i = 0; i < 2; i++) {
            int nz = z + dz[i];
            if (0 <= nz && nz < H) {
                if (box[x][y][nz] == 0) {
                    box[x][y][nz] = box[x][y][z] + 1;
                    q.push(make_pair(make_pair(x, y), nz));
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M >> N >> H;

    for (int h = 0; h < H; h++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> box[i][j][h];
                if (box[i][j][h] == 1) q.push({{i, j}, h});
            }
        }
    }

    BFS();

    for (int h = 0; h < H; h++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (box[i][j][h] == 0) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << success - 1;

    return 0;
}
