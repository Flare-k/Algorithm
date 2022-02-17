#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define RMAX 12
#define CMAX 6
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int map[RMAX][CMAX];
bool visit[RMAX][CMAX];
int answer;
enum {
    EMPTY, R, G, B, P, Y
};
struct Node {
    int x, y;
};

void movePuyo() {
    for (int j = 0; j < CMAX; j++) {
        for (int i = RMAX - 1; i >= 0; i--) {
            if (map[i][j] == EMPTY) {
                for (int k = i - 1; k >= 0; k--) {
                    if (map[k][j] != EMPTY) {
                        swap(map[k][j], map[i][j]);
                        break;
                    }
                }
            }
        }
    }
}

bool bumb() {
    bool flag = false;
    int cnt;
    vector<Node> vect;
    memset(visit, false, sizeof(visit));
    queue<Node> q;

    for (int i = RMAX - 1; i >= 0; i--) {
        for (int j = 0; j < CMAX; j++) {
            if (map[i][j] != EMPTY && !visit[i][j]) {
                int color = map[i][j];
                cnt = 1;

                vect.clear();

                visit[i][j] = true;
                q.push({i, j});
                vect.push_back({i, j});

                while (!q.empty()) {
                    Node now = q.front();
                    q.pop();

                    for (int d = 0; d < 4; d++) {
                        int nx = now.x + dx[d];
                        int ny = now.y + dy[d];

                        if (nx < 0 || nx >= RMAX || ny < 0 || ny >= CMAX) continue;
                        if (visit[nx][ny] || map[nx][ny] != color) continue;

                        visit[nx][ny] = true;
                        cnt++;
                        q.push({nx, ny});
                        vect.push_back({nx, ny});
                    }
                }

            }

            if (cnt >= 4) {
                for (auto v : vect) {
                    map[v.x][v.y] = EMPTY;
                }

                flag = true;
            }
        }
    }

    return flag;
}

void run() {
    while (bumb()) {
        answer++;
        movePuyo();
    }

    cout << answer << '\n';
}

void init() {
    string status;
    
    for (int i = 0; i < RMAX; i++) {
        cin >> status;
        for (int j = 0; j < CMAX; j++) {
            if (status[j] == '.') map[i][j] = EMPTY;
            else if (status[j] == 'R') map[i][j] = R;
            else if (status[j] == 'G') map[i][j] = G;
            else if (status[j] == 'B') map[i][j] = B;
            else if (status[j] == 'P') map[i][j] = P;
            else if (status[j] == 'Y') map[i][j] = Y;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    run();

    return 0;
}