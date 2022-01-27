#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 101;
const int dx[] = {-1 ,1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int row, col, sx, sy, ex, ey;
int map[MAX][MAX];
int visit[MAX][MAX];
int answer = 21e8;
enum {
    EMPTY, WALL, C
};
struct Node {
    int x, y, dir, cnt;
};

void run() {
    queue<Node> q;
    for (int dir = 0; dir < 4; dir++) {
        q.push({sx, sy, dir, 0});
    }

    visit[sx][sy] = true;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            int cnt = now.cnt;

            if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
            if (map[nx][ny] == WALL) continue;
            if (now.dir != i) cnt++;

            if (visit[nx][ny] >= cnt) {
                visit[nx][ny] = cnt;
                q.push({nx, ny, i, cnt});
            }

        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> col >> row;

    char ch;
    int check = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> ch;
            if (ch == '.') map[i][j] = EMPTY;
            else if (ch == '*') map[i][j] = WALL;
            else if (ch == 'C') {
                map[i][j] = C;
                if (check == 0) {
                    sx = i;
                    sy = j;
                    check++;
                }
                else {
                    ex = i;
                    ey = j;
                }
            }

            visit[i][j] = 1e9;
        }
    }

    run();

    cout << visit[ex][ey];

    return 0;
}
