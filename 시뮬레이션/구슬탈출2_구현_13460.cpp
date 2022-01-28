#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

const int MAX = 11;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int N, M;
int map[MAX][MAX];

struct Marble {
    int rx, ry;
    int bx, by;
};

enum {
    EMPTY, WALL, HOLE, RED, BLUE
};

Marble marble;
using edge = tuple <int, int, int, int>;
set<edge> visit;


bool samePos(int x, int y, int r, int c) {
    if (x == r && y == c) return true;
    return false;
}

int run() {
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

            if (map[rx][ry] == HOLE && map[rx][ry] != map[bx][by]) {
                return cnt;
            }

            for (int i = 0; i < 4; i++) {
                int nrx = rx, nry = ry;
                int nbx = bx, nby = by;

                // 이동
                while (map[nrx + dx[i]][nry + dy[i]] != WALL && map[nrx][nry] != HOLE) {
                    nrx += dx[i];
                    nry += dy[i];
                }
                while (map[nbx + dx[i]][nby + dy[i]] != WALL && map[nbx][nby] != HOLE) {
                    nbx += dx[i];
                    nby += dy[i];
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

        if (cnt == 10) return -1;
        cnt++;
    }

    return -1;
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

    cout << run();

    return 0;
}