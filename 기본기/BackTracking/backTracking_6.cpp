#include <iostream>
using namespace std;

int map[3][3] = {
    0, 1, 0,
    0, 0, 0,
    0, 1, 0
};

int used[3][3] = {1};   // (0,0)만 1이고 나머진 다 0

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

void run(int x, int y) {
    if (x == 2 && y == 2) {
        cout << "도착";
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >=3 || ny < 0 || ny >= 3) continue;
        if (map[nx][ny] == 1) continue;
        if (used[nx][ny] == 1) continue;

        used[nx][ny] = 1;
        run(nx, ny);
        used[nx][ny] = 0;
    }
}

int main() {

    run(0, 0);

    return 0;
}