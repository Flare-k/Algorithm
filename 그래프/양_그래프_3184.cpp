#include <iostream>
#include <queue>
using namespace std;

const int MAX = 251;
bool visit[MAX][MAX];
char field[MAX][MAX];

int wolf, sheep;
int r, c;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

struct Node {
    int x, y;
};

void run(int i, int j) {
    visit[i][j] = true;
    queue<Node> q;
    q.push({i, j});
    
    int w = 0, s = 0;

    if (field[i][j] == 'v') w++;
    else if (field[i][j] == 'o') s++;
    
    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if (field[nx][ny] == '#' || visit[nx][ny] == true) continue;

            q.push({nx, ny});
            visit[nx][ny] = true;

            if (field[nx][ny] == 'v') w++;
            else if (field[nx][ny] == 'o') s++;
        }
    }

    if (w < s) sheep += s;
    else wolf += w;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> field[i][j];
        }
    }
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (field[i][j] != '#' && !visit[i][j]) run(i, j);
        }
    }

    cout << sheep << ' ' << wolf;

    return 0;
}