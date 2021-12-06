#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

/*
바이러스 N개가 있는데 그중 M개는 활성상태이다.
활성 상태일 때 주변을 똑같이 복제시킬 수 있다.
바이러스를 퍼뜨리는 최소시간 구하기
M에 대한 모든 케이스 구할것
*/
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

const int MAX = 51;
int acc[MAX][MAX];
int inst[MAX][MAX];
bool visit[MAX][MAX];
bool enabled[MAX][MAX];

int N, M;
struct Dir {
    int x, y, val;
};

vector<Dir> dir;

int run(queue<Dir>& q) {
    int maxx = 0;

    while (!q.empty()) {
        Dir now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (inst[nx][ny] == 1) continue;
            if (visit[nx][ny]) continue;
            
            if (enabled[now.x][now.y] == true && inst[nx][ny] == 2 && enabled[nx][ny] == false) {
                enabled[nx][ny] = true;
            }

            q.push({nx, ny, now.val + 1});
            acc[nx][ny] = now.val + 1;
            visit[nx][ny] = true;
            
            if (inst[nx][ny] == 0) maxx = max(maxx, acc[nx][ny]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (acc[i][j] == 0 && !enabled[i][j]) {
                return -1;
            }
        }
    }

    return maxx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int viruscnt = 0;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> inst[i][j];
            if (inst[i][j] == 2) {
                viruscnt++;
                dir.push_back({i, j});
            }
        }
    }

    vector<int> rand(viruscnt, 0);

    for (int i = viruscnt - M; i < viruscnt; i++) {
        rand[i] = 1;
    }

    int answer = 21e8;
    int cnt = 0;
    int minus = 0;

    do {
        memset(enabled, false, sizeof(enabled));
        memset(visit, false, sizeof(visit));
        memcpy(acc, inst, sizeof(acc));
        queue<Dir> q;

        for (int i = 0; i < rand.size(); i++) {
            if (rand[i] == 1) {
                q.push({dir[i].x, dir[i].y, 0});
                acc[dir[i].x][dir[i].y] = 3;
                enabled[dir[i].x][dir[i].y] = true;
                visit[dir[i].x][dir[i].y] = true;
            }
        }

        int result = run(q);
        
        if (result == -1) minus++;
        else answer = min(answer, result);

        cnt++;
    } while (next_permutation(rand.begin(), rand.end()));

    if (cnt == minus) answer = -1;

    if (answer == 21e8) cout << -1;
    else cout << answer;

    return 0;
}