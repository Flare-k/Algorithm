#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int L, R, C;
const int MAX = 32;
const int dz[] = {-1, 1, 0, 0, 0, 0};
const int dx[] = {0, 0, -1, 1, 0, 0};
const int dy[] = {0, 0, 0, 0, -1, 1};

struct Node {
    int z, x, y, cnt;
};

bool visit[MAX][MAX][MAX];
char building[MAX][MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        cin >> L >> R >> C;

        if (L == 0 && R == 0 && C == 0) break;

        queue<Node> q;
        string s;

        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                cin >> s;
                for (int k = 0; k < C; k++) {
                    building[i][j][k] = s[k];

                    if (building[i][j][k] == 'S') {
                        q.push({i, j, k, 0});
                        visit[i][j][k] = true;
                    }
                }
            }
        }

        bool flag = false;

        while (!q.empty()) {
            Node now = q.front();
            q.pop();

            for (int i = 0; i < 6; i++) {
                int nz = now.z + dz[i];
                int nx = now.x + dx[i];
                int ny = now.y + dy[i];

                if (nz < 0 || nz >= L || nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (visit[nz][nx][ny]) continue;
                if (building[nz][nx][ny] == '#') continue;

                if (building[nz][nx][ny] == 'E') {
                    cout << "Escaped in " << now.cnt + 1 << " minute(s).\n";
                    flag = true;
                    break;
                }

                if (building[nz][nx][ny] == '.' && !visit[nz][nx][ny]) {
                   q.push({nz, nx, ny, now.cnt + 1});
                   visit[nz][nx][ny] = true;
                }
            }

            if (flag) break;
        }

        if (!flag) cout << "Trapped!" << '\n';

        memset(visit, false, sizeof(visit));
    }

    return 0;
}