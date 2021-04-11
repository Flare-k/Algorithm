#include <iostream>
#include <string>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int cnt = 0;

char syClass[5][6];
bool visit[5][5];

void run(int level, int px, int py, int s, int y) {
    if (y >= 4) return;

    if (level == 7) {
        if (s >= y) cnt++;
        return;
    }

    // visit[px][py] = true;

    for (int i = 0; i < 4; i++) {
        int nx = px + dx[i];
        int ny = py + dy[i];

        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;

        if (!visit[nx][ny]) {
            if (syClass[nx][ny] == 'S') {
                visit[nx][ny] = true;
                run(level + 1, nx, ny, s + 1, y);
                visit[nx][ny] = false;
            }
            else if (syClass[nx][ny] == 'Y') {
                visit[nx][ny] = true;
                run(level + 1, nx, ny, s, y + 1);
                visit[nx][ny] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    string sy;
    for (int i = 0; i < 5; i++) {
        cin >> sy;
        for (int j = 0; j < 5; j++) {
            syClass[i][j] = sy[j];
        }
    }
    visit[0][0] = true;

    if (syClass[0][0] == 'S') {
        run(1, 0, 0, 1, 0);
    }
    else if (syClass[0][0] == 'Y') {
        run(1, 0, 0, 0, 1);
    }

    cout << cnt;

    return 0;
}