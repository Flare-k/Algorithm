#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

// DFS - 각 섬의 이름 분류하기
void changeIslandName(int x, int y, int size, int number, int island[][101], bool visit[][101]) {
    visit[x][y] = true;
    island[x][y] = number;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < size && 0 <= ny && ny < size) {
            if (island[nx][ny] && !visit[nx][ny]) {
                changeIslandName(nx, ny, size, number, island, visit);
            }
        }
    }
}

// BFS - 섬간의 짧은 거리 찾기
int connectBridge(int n, int number, int island[][101], bool visit[][101]) {
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (island[i][j] == number) {   // 특정 경우의 섬에 대한 위치만 담음
                visit[i][j] = true;
                q.push({i, j});
            }
        }
    }

    int dist = 0;

    while (!q.empty()) {
        int iter = q.size();

        for (int i = 0; i < iter; i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                    if (island[nx][ny] && island[nx][ny] != number){    // 다른 섬이라면
                        return dist;
                    }
                    else if (!island[nx][ny] && !visit[nx][ny]) {    // 바다라면
                        visit[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        dist++;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int island[101][101];   // 섬에 대한 배열
    bool visit[101][101];   // 섬 방문 표시

    // 섬 정보 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> island[i][j];
        }
    }

    // 1로 표시되어 있는 섬을 다른 수들로 구분하기 위해 DFS 활용
    int number = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (island[i][j] && !visit[i][j]){
                changeIslandName(i, j, n, number++, island, visit);
            }
        }
    }

    // Find Shortest Distance 
    int res = 987654321;
    for (int exist = 1; exist < number; exist++){
       memset(visit, false, sizeof(visit));
       res = min(res, connectBridge(n, exist, island, visit));
    }
    cout << res;

    return 0;
}