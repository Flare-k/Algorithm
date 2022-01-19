#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const int MAX = 51;
int N, L, R;
int map[MAX][MAX];
int arr[MAX][MAX];
bool visit[MAX][MAX];

struct Node {
    int x, y;
};

vector<Node> line[MAX * MAX + 1];

void initLine() {
    for (int i = 1; i <= N * N; i++) {
        line[i].clear();
    }
}

int nationalLine(int x, int y, int num) {
    queue<Node> q;
    q.push({x, y});
    visit[x][y] = true;
    line[num].push_back({x, y});

    int cnt = 0;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visit[nx][ny]) continue;

            int sub = abs(map[now.x][now.y] - map[nx][ny]);

            if (sub < L || sub > R) continue;

            visit[nx][ny] = true;
            q.push({nx, ny});
            line[num].push_back({nx, ny});
            cnt++;
        }
    }

    return cnt;
}

void movePeople() {
    for (int i = 1; i <= N * N; i++) {
        int size = line[i].size();
        
        if (size > 1) {
            int sum = 0;

            for (int j = 0; j < size; j++) {
                sum += map[line[i][j].x][line[i][j].y];
            }
            
            int avg = sum / size;

            for (int j = 0; j < size; j++) {
                map[line[i][j].x][line[i][j].y] = avg;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> L >> R;

    int idx = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            arr[i][j] = idx++;
        }
    }

    int day = 0;
    
    while (1) {
        initLine();
        memset(visit, false, sizeof(visit));

        int cnt = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visit[i][j]) {
                    cnt += nationalLine(i, j, arr[i][j]);
                }
            }
        }

        if (cnt == 0) break;

        movePeople();

        day++;
    }

    cout << day;

    return 0;
}