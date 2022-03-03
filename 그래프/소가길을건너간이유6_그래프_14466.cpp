#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
#define MAX 101
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int N, K, R;
int answer;
int arr[MAX][MAX];
bool visit[MAX][MAX];
using edge = tuple<int, int, int, int>;
set<edge> road;  // int road[MAX][MAX][MAX][MAX]; 로도 풀림. 대신 메모리 많이 씀

struct Dir {
    int x, y;
};

vector<Dir> cow;

// 길없이 만날 수 있는 경우 모두 방문 체크
void run(int x, int y) {
    queue<Dir> q;
    q.push({x, y});
    visit[x][y] = true;

    while (!q.empty()) {
        Dir now = q.front();
        q.pop();

        int cx = now.x;
        int cy = now.y;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;         // 울타리 넘는 경우 무시
            if (visit[nx][ny] || road.count({cx, cy, nx, ny})) continue;    // 이미 방문했거나 길을 이용해서 가야하는 경우라면 패스!

            visit[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K >> R;
    
    int x, y, r, c;

    for (int i = 0; i < R; i++) {
        cin >> x >> y >> r >> c;

        road.insert({x, y, r, c});
        road.insert({r, c, x, y});
    }

    for (int i = 0; i < K; i++) {
        cin >> x >> y;
        cow.push_back({x, y});
    }

    for (int i = 0; i < K; i++) {
        memset(visit, false, sizeof(visit));
        
        run(cow[i].x, cow[i].y);

        // 앞선 경우와의 중복을 없애기 위해 j = i + 1
        // 만약 다른 소를 만난적이 없다면, 길이 없으면 못가는 경우이다.
        for (int j = i + 1; j < K; j++) {
            if (!visit[cow[j].x][cow[j].y]) answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}