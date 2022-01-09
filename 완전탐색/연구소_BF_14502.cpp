#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

// 벽을 세 개 세웠을 때의 최대 안전영역의 크기는?
const int MAX = 9;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int N, M;
int map[MAX][MAX];
int tmp_map[MAX][MAX];
bool visit[MAX][MAX];
int answer;
enum {
    EMPTY, WALL, VIRUS
};

struct Node {
    int x, y;
};

void checkVirus(int x, int y) {
    queue<Node> q;
    q.push({x, y});
    visit[x][y] = true;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (visit[nx][ny]) continue;
            
            if (tmp_map[nx][ny] == EMPTY) {
                tmp_map[nx][ny] = VIRUS;
                visit[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int checkSafetyArea() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tmp_map[i][j] == EMPTY) cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    vector<Node> empty_area;    // 새로운 벽을 세워야하는 공간

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];

            if (map[i][j] == EMPTY) empty_area.push_back({i, j});
        }
    }

    vector<int> check(empty_area.size() - 3, 0);
    for (int i = 0; i < 3; i++) {
        check.push_back(1);
    }

    do {
        memcpy(tmp_map, map, sizeof(tmp_map));

        // 세 군데에 벽 세우기
        for (int i = 0; i < check.size(); i++) {
            if (check[i] == 1) {
                Node node = empty_area[i];
                tmp_map[node.x][node.y] = WALL;
            }
        }

        // 방문 초기화
        memset(visit, false, sizeof(visit));

        // 바이러스 전염
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (tmp_map[i][j] == VIRUS && !visit[i][j]) {
                    checkVirus(i, j);
                }
            }
        }
    
        answer = max(answer, checkSafetyArea());
        
    } while (next_permutation(check.begin(), check.end()));

    cout << answer;   

    return 0;
}