#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

string dir;
// <-(좌) 남 서 북 동 (우)->
int ddir = 0;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

const int MAX = 101;
char miro[MAX][MAX];
char mirocpy[MAX][MAX];
int x = MAX / 2, y = MAX / 2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(miro, '#', sizeof(miro));
    memcpy(mirocpy, miro, sizeof(miro));

    int n;
    cin >> n >> dir;

    miro[x][y] = '.';

    for (int i = 0; i < n; i++) {
        if (dir[i] == 'R') {
            ddir++;
            if (ddir == 4) ddir = 0;
        }
        else if (dir[i] == 'L') {
            ddir--;
            if (ddir == -1) ddir = 3;
        }
        else if (dir[i] == 'F') {
            int nx = x + dx[ddir];
            int ny = y + dy[ddir];

            miro[nx][ny] = '.';
            x = nx;
            y = ny;
        }
    }

    int sx = 21e8, sy = 21e8, ex = -21e8, ey = -21e8;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (miro[i][j] != mirocpy[i][j]) {
                sx = min(sx, i);
                sy = min(sy, j);
                ex = max(ex, i);
                ey = max(ey, j);
            }
        }
    }

    for (int i = sx; i <= ex; i++) {
        for (int j = sy; j <= ey; j++) {
            cout << miro[i][j];
        }
        cout << '\n';
    }

    return 0;
}