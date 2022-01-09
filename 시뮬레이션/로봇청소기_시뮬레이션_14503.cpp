#include <iostream>
#include <algorithm>
using namespace std;

// 벽을 세 개 세웠을 때의 최대 안전영역의 크기는?
const int MAX = 51;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int N, M;
int map[MAX][MAX];
int answer;
enum {
    EMPTY, WALL
};

struct Robot {
    int x, y, dir;
};

Robot robot;

void run() {

    while (1) {

        if (map[robot.x][robot.y] == EMPTY) {
            map[robot.x][robot.y] = 2;
            answer++;
        }

        int dir = robot.dir;
        bool flag = false;

        for (int i = 0; i < 4; i++) {
            dir = dir - 1 < 0 ? 3 : dir - 1;

            int nx = robot.x + dx[dir];
            int ny = robot.y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (map[nx][ny] == EMPTY) {
                robot = {nx, ny, dir};
                flag = true;
                break;
            }
        }

        if (flag) continue;

        int d = dir % 2 == 0 ? 2 - dir : 4 - dir;
        robot.x += dx[d];
        robot.y += dy[d];

        if (map[robot.x][robot.y] == WALL) break;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    int x, y, dir;
    cin >> x >> y >> dir;

    robot = {x, y, dir};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    run();

    cout << answer;

    return 0;
}