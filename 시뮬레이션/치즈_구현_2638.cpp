#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 101;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int visitCheese[MAX][MAX];
bool visitAir[MAX][MAX];
int map[MAX][MAX];
int r, c;

struct Node {
    int x, y;
};

// 모두 녹았는지 확인
bool checkMapEnd() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] == 1) return true;
        }
    }

    return false;
}

void run() {
    // 공기 확인(0)인 배열과 치즈 확인(1)인 배열 초기화
    memset(visitAir, false, sizeof(visitAir));
    memset(visitCheese, false, sizeof(visitCheese));

    queue<Node> q;
    q.push({0, 0});

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if (visitAir[nx][ny]) continue;
            if (map[nx][ny] == 1) {
                visitCheese[nx][ny]++;
                // 두 군에 이상 노출된다면..
                if (visitCheese[nx][ny] >= 2) {
                    map[nx][ny] = 0;
                    visitAir[nx][ny] = true;
                }

                continue;
            }

            visitAir[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main() {

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0 ; j < c; j++) {
            cin >> map[i][j];
        }
    }

    int cnt = 0;
    while (checkMapEnd()) {
        run();
        cnt++;
    }

    cout << cnt;
    
    return 0;
}