#include <iostream>
#include <queue>
using namespace std;

int r, c;
const int MAX = 51;
char map[MAX][MAX];

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

bool flag = false;
int endx, endy;

struct Node {
    int x, y;
    int level;
};

queue<Node> q;

void run() {

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        if (map[now.x][now.y] == 'D') {
            cout << now.level;
            flag = true;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if (map[nx][ny] == 'X') continue;

            if (map[now.x][now.y] == '*') {
                if (map[nx][ny] == '.') {
                    map[nx][ny] = '*';
                    q.push({nx, ny, now.level + 1});
                }
            }
            else {
                if (map[nx][ny] == '.') {
                    map[nx][ny] = 'S';
                    q.push({nx, ny, now.level + 1});
                }
                else if (map[nx][ny] == 'D') {
                    q.push({nx, ny, now.level});
                }
                
            }

        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];

            if (map[i][j] == 'D') {
                endx = i;
                endy = j;
            }
        }
    }
    
    // 물 > 고슴도치
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] == '*') q.push({i, j, 1});
        }
    }
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] == 'S') q.push({i, j, 1});
        }
    }

    run();

    if (!flag) cout << "KAKTUS";

    return 0;
}