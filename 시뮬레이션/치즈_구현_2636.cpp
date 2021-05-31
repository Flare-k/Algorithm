#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
const int MAX = 20;

bool visitAir[MAX][MAX];        // 공기
bool visitCheese[MAX][MAX];     // 치즈
int map[MAX][MAX];
int r, c;   // 전체 map의 행, 열

// 공기인 부분
struct Node {
    int x, y;
};

vector<int> totalCnt;   // 1의 개수

// 1의 개수 카운팅
bool checkMap() {
    int cnt = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] == 1) cnt++;
        }
    }

    totalCnt.push_back(cnt);

    return cnt != 0 ? true : false;
}

void run() {
    memset(visitAir, false, sizeof(visitAir));
    memset(visitCheese, false, sizeof(visitCheese));

    queue<Node> q;
    q.push({0, 0});
    visitAir[0][0] = true;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if (visitAir[nx][ny]) continue;
            if (map[nx][ny] == 1) {
                visitCheese[nx][ny] = true;
                continue;
            }

            visitAir[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (visitCheese[i][j]) map[i][j] = 0;
        }   
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }

    int cnt = 0;
    while (checkMap()) {
        run();
        cnt++;
    }

    int size = totalCnt.size();
    cout << cnt << '\n' << totalCnt[size - 2];  // 가장 끝은 0이므로 끝에서 두번째 값이 1의 최소개수 카운팅 값

    return 0;
}