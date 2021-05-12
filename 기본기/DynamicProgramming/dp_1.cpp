// DP: 기존의 데이터를 기반으로 거듭하여 다음 데이터를 구해 최선의 값을 도출
#include <iostream>
using namespace std;

int acc[5][5];
int dir[4][4];

int road[4][4] = {
    0, 3, 2, 1,
    4, 5, 1, 5,
    6, 1, 3, 4,
    1, 5, 2, 1
};

enum {
    DOWN,
    RIGHT
};

void init() {
    for (int i = 0; i < 5; i++) {
        acc[i][4] = 999;
        acc[4][i] = 999;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    
    for (int i = 3; i >= 0; i--) {
        for (int j = 3; j >= 0; j--) {
            if (i == 3 && j == 3) continue;

            int right = acc[i][j + 1];
            int down = acc[i + 1][j];

            if (right <= down) {
                dir[i][j] = RIGHT;
                acc[i][j] = road[i][j] + right;
            }
            else {
                dir[i][j] = DOWN;
                acc[i][j] = road[i][j] + down;
            }
        }
    }

    cout << acc[0][0] << '\n';

    int nx = 0;
    int ny = 0;

    while (1) {
        cout << "(" << nx << ", " << ny << ")\n";

        if (nx == 3 && ny == 3) break;
        if (dir[nx][ny] == RIGHT) ny++;
        else nx++;
    }

    return 0;
}