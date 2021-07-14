#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 301;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int map[MAX][MAX];      // 빙산
bool visit[MAX][MAX];   // 빙산 체크

int r, c;

struct Node {
    int x, y;
};

// 빙산 녹이는 BFS
void melt(int x, int y) {
    queue<Node> q;
    q.push({x, y});
    visit[x][y] = true;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= r|| ny >= c) continue;
            if (visit[nx][ny] == true) continue;
            if (map[nx][ny] == 0) {
                cnt++;
                continue;
            }
            visit[nx][ny] = true;
            q.push({nx, ny});
        }

        if (cnt > 0) {
            map[now.x][now.y] = max(map[now.x][now.y] - cnt, 0);
        }
    }
}

// 빙산 덩어리 확인 BFS
void checkIce(int x, int y) {
    queue<Node> q;
    q.push({x, y});
    visit[x][y] = true;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= r|| ny >= c) continue;
            if (visit[nx][ny] == true) continue;
            if (map[nx][ny] == 0) continue;

            visit[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }

    int year = 0;

    while (1) {
        // 첫 행,열 & 마지막 행,열은 제외해준다. (1~r-1, 1~c-1)
        
        // 빙산 확인용 BFS
        memset(visit, false, sizeof(visit));
        bool flag = false;
        int check = 0;
        for (int i = 1; i < r - 1; i++) {
            for (int j = 1; j < c - 1; j++) {
                if (!visit[i][j] && map[i][j] != 0) {
                    check++;
                    // 만약 두덩이 이상이면 checkIce()에 들어가지 않고 끝낸다. (시간줄이기)
                    if (check > 1) {
                        flag = true;
                        break;
                    }   
                    checkIce(i, j); 
                }
            }
            if (flag) break;    // 두덩이 이상이면 브레이크
        }
        
        if (flag) break;    // 두덩이 이상이므로 전체 브레이크

        // 만약 다 녹았는데 두덩이 이상 안나왔다? year는 0으로 출력
        if (check == 0) {
            year = 0;
            break;
        }

        // 1년 증가
        year++;

        // 얼음 녹는 BFS
        memset(visit, false, sizeof(visit));
        for (int i = 1; i < r - 1; i++) {
            for (int j = 1; j < c - 1; j++) {
                if (!visit[i][j] && map[i][j] != 0) 
                    melt(i, j);
            }
        }
    }

    cout << year;

    return 0;
}