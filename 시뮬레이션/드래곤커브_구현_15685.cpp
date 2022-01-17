#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
0 = 0
1 = 01
2 = 0121
3 = 01212320
...
*/

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
const int MAX = 101;
int N, x, y, d, g;
vector<int> dirs;
int map[MAX][MAX];

void dragonCurve() {
    int size = dirs.size() - 1;

    for (int i = size; i >= 0; i--) {
        int dir = (dirs[i] + 1) % 4;

        x += dx[dir];
        y += dy[dir];
        map[x][y] = 1;
        dirs.push_back(dir);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    while (N--) {
        cin >> x >> y >> d >> g;
        dirs.clear();
        swap(x, y);

        map[x][y] = 1;
        x += dx[d];
        y += dy[d];
        map[x][y] = 1;

        dirs.push_back(d);

        while (g--) {
            dragonCurve();
        }
    }

    int cnt = 0;

    // 모든 꼭짓점
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (map[i][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j] == 1 && map[i + 1][j + 1] == 1) cnt++;
        }
    }

    cout << cnt;

    return 0;
}