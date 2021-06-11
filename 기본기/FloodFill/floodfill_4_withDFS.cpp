#include <iostream>
using namespace std;

int map[3][4];
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

void run(int lvl, int x, int y) {

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= 3 || ny >= 4) continue;
        if (map[nx][ny] > 0 && map[x][y] + 1 >= map[nx][ny]) continue;

        map[nx][ny] = map[x][y] + 1;
        run(lvl + 1, nx, ny);
    }
}

int main() {

    map[2][1] = 1;
    run(0, 2, 1);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}