#include <iostream>
using namespace std;

int map[4][4];
int acc[5][5] = {0};
int dir[4][4];

void init() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        acc[i][4] = 999;
        acc[4][i] = 999;
    }
}

enum {
    DOWN,
    RIGHT
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    for (int i = 3; i >= 0; i--) {
        for (int j = 3; j >= 0; j--) {
            if (i == 3 && j == 3) continue;

            if (acc[i][j + 1] < acc[i + 1][j]) {    // right가 작을 경우
                acc[i][j] = acc[i][j + 1] + map[i][j];
                dir[i][j] = RIGHT;
            }
            else {
                acc[i][j] = acc[i + 1][j] + map[i][j];
                dir[i][j] = DOWN;
            }
        }
    }

    int nx = 0;
    int ny = 0;

    while (1) {
        cout <<  nx << "," << ny << "\n";

        if (nx == 3 && ny == 3) break;
        if (dir[nx][ny] == RIGHT) ny++;
        else nx++;
    }


    return 0;
}
/*
0 3 5 1
1 1 1 5
1 50 20 10
1 50 5 0

> 
0,0
1,0
1,1
1,2
1,3
2,3
3,3

*/