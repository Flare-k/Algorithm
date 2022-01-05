#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX = 21;
int N, M, x, y, K;
int dice[4][3];
int map[MAX][MAX];
int& up = dice[1][1];
int& down = dice[3][1];
const int dx[] = {0, 0, 0, -1, 1};
const int dy[] = {0, 1, -1, 0, 0};

void moveNorth() {
    int tmp = dice[0][1];
    for (int i = 0; i < 3; i++) {
        dice[i][1] = dice[i + 1][1];
    }
    dice[3][1] = tmp;
}

void moveSouth() {
    int tmp = dice[3][1];
    for (int i = 3; i > 0; i--) {
        dice[i][1] = dice[i - 1][1];
    }
    dice[0][1] = tmp;
}

void moveWest() {
    int tmp1 = dice[3][1];
    int tmp2 = dice[1][0];
    for (int i = 0; i < 2; i++) {
        dice[1][i] = dice[1][i + 1];
    }
    dice[1][2] = tmp1;
    dice[3][1] = tmp2;
}

void moveEast() {
    int tmp1 = dice[3][1];
    int tmp2 = dice[1][2];
    for (int i = 2; i > 0; i--) {
        dice[1][i] = dice[1][i - 1];
    }
    dice[1][0] = tmp1;
    dice[3][1] = tmp2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> x >> y >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        int dir;
        cin >> dir;

        x += dx[dir];
        y += dy[dir];

        if (x < 0 || x >= N || y < 0 || y >= M) {
            x -= dx[dir];
            y -= dy[dir];
            continue;
        }

        if (dir == 1) moveEast();
        else if (dir == 2) moveWest();
        else if (dir == 3) moveNorth();
        else moveSouth();

        if (map[x][y] == 0) {
            map[x][y] = down;
        }
        else {
            dice[3][1] = map[x][y];
            map[x][y] = 0;
        }

        cout << up << '\n';
    }

    return 0;
}