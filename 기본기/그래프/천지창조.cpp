#include <iostream>
#include <cstring>
#include <string>
using namespace std;

char picture[8][10];
bool check[8][9];
struct Node {
    int x, y, level;
};

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int minDist = 21e8;

Node q[80];
int head, tail;

void BFS(int x, int y) {
    check[x][y] = true;
    head = 0;
    tail = 1;

    q[head] = {x, y, 0};

    while (head != tail) {
        Node now = q[head++];

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 8 || ny >= 9) continue;
            if (picture[nx][ny] == '_') continue;
            if (check[nx][ny]) continue;

            check[nx][ny] = true;
            q[tail++] = {nx, ny, 0};
        }
    }
}

void near() {
    head = 0;
    while (head != tail) {
        Node now = q[head++];

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 8 || ny >= 9) continue;
            if (!check[nx][ny] && picture[nx][ny] == '#') {
                if (minDist > now.level) {
                    minDist = now.level;
                }
            }
            if (check[nx][ny] || picture[nx][ny] == '#') continue;

            q[tail++] = {nx, ny, now.level + 1};
            check[nx][ny] = true;

        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(check, false, sizeof(check));

    string p;
    for (int i = 0; i < 8; i++) {
        cin >> p;
        for (int j = 0; j < 9; j++) {
            picture[i][j] = p[j];
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 9; j++) {
            if (picture[i][j] == '#' && !check[i][j]) {
                BFS(i, j);
                near();
            }
        }
    }
    
    cout << minDist;
    
    return 0;
}