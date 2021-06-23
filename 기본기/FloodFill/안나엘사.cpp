#include <iostream>
#include <queue>
using namespace std;

/*
안나와 엘사가 만날 수 있는 최단거리는?
안나와 엘세가 동시에 출발한다.
안나는 상,하,좌,우,제자리 총 다섯가지의 방향으로 움직이고
엘사는 상,하,좌,우 총 네 가지의 방향으로 움직일 수 있다.
> 각 이동마다 5x4 총 20가지의 가짓수가 나온다.
*/
const int MAX = 10;
const int dx[] = {-1, 1, 0, 0, 0};
const int dy[] = {0, 0, -1, 1, 0};

int arr[4][4] = {
    0, 0, 0, 0,
    0, 1, 0, 1,
    0, 0, 0, 1,
    0, 1, 0, 0
};

bool visit[MAX][MAX][MAX][MAX];

struct Node {
    int ax, ay;
    int ex, ey;
    int level;
};

int run(int ax, int ay, int ex, int ey) {

    queue<Node> q;
    q.push({ax, ay, ex, ey, 0});
    visit[ax][ay][ex][ey] = true;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 5; i++) {
            int nax = now.ax + dx[i];
            int nay = now.ay + dy[i];

            if (nax < 0 || nay < 0 || nax >= 4 || nay >= 4) continue;
            if (arr[nax][nay] == 1) continue;

            for (int j = 0; j < 4; j++) {
                int nex = now.ex + dx[j];
                int ney = now.ey + dy[j];

                if (nex < 0 || ney < 0 || nex >= 4 || ney >= 4) continue;
                if (arr[nex][ney] == 1) continue;
                if (visit[nax][nay][nex][ney] == true) continue;

                visit[nax][nay][nex][ney] = true;
                q.push({nax, nay, nex, ney, now.level + 1});

                if (nax == nex && nay == ney) {
                    return now.level + 1;
                }
            }
        }
    }

    return -1;  // 못 만나는 경우
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << run(0, 0, 3, 3);

    return 0;
}