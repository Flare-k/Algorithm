#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
#include <cstring>
using namespace std;

const int MAX = 11;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int N, M;
int hole_x, hole_y;
int map[MAX][MAX];
bool check[MAX][MAX];
struct Marble {
    int rx, ry, bx, by;
};

enum {
    EMPTY, WALL, HOLE, RED, BLUE
};

Marble marble;
using edge = tuple <int, int, int, int>;
set<edge> visit;

struct Dir {
    int x, y;
};

bool samePos(int x, int y, int r, int c) {
    if (x == r && y == c) return true;
    return false;
}

bool checkPossibility() {
    memset(check, false, sizeof(check));
    queue<Dir> q;
    q.push({marble.rx, marble.ry});
    check[marble.rx][marble.ry] = true;

    while (!q.empty()) {
        Dir now = q.front();
        q.pop();

        if (now.x == hole_x && now.y == hole_y) return true;

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (map[nx][ny] == WALL) continue;
            if (check[nx][ny]) continue;

            check[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    return false;
}

void run() {
    queue<Marble> q;
    q.push(marble);
    int cnt = 0;

    while (!q.empty()) {
        int size = q.size();

        while (size--){
            Marble now = q.front();
            q.pop();

            int rx = now.rx, ry = now.ry;
            int bx = now.bx, by = now.by;


            for (int i = 0; i < 4; i++) {
                int nrx = rx, nry = ry;
                int nbx = bx, nby = by;

                while (map[nrx + dx[i]][nry + dy[i]] != WALL && map[nrx][nry] != HOLE) {
                    nrx += dx[i];
                    nry += dy[i];
                }
                while (map[nbx + dx[i]][nby + dy[i]] != WALL && map[nbx][nby] != HOLE) {
                    nbx += dx[i];
                    nby += dy[i];
                }
                
                if (map[nrx][nry] == HOLE && map[nrx][nry] != map[nbx][nby]) {
                    cout << cnt + 1;
                    return;
                }

                // 구슬끼리 만나는 경우
                if (samePos(nrx, nry, nbx, nby)) {
                    if (map[nrx][nry] == HOLE && map[nbx][nby] == HOLE) continue;
                    int red_dist = abs(nrx - rx) + abs(nry - ry);
                    int blue_dist = abs(nbx - bx) + abs(nby - by);

                    if (red_dist < blue_dist) {
                        nbx -= dx[i];
                        nby -= dy[i];
                    }
                    else {
                        nrx -= dx[i];
                        nry -= dy[i];
                    }
                }

                if (visit.find({nrx, nry, nbx, nby}) != visit.end()) continue;  // 없으면 end()

                q.push({nrx, nry, nbx, nby});
                visit.insert({nrx, nry, nbx, nby});
            }
        }

        cnt++;
    }

    cout << -1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    char ch;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> ch;
            if (ch == '#') {
                map[i][j] = WALL;
            }
            else if (ch == '.') {
                map[i][j] = EMPTY;
            }
            else if (ch == 'O') {
                map[i][j] = HOLE;
                hole_x = i;
                hole_y = j;
            }
            else if (ch == 'R') {
                marble.rx = i;
                marble.ry = j;
                map[i][j] = RED;
            }
            else if (ch == 'B') {
                marble.bx = i;
                marble.by = j;
                map[i][j] = BLUE;
            }
        }
    }

    if (checkPossibility() == true) run();
    else cout << - 1;

    return 0;
}