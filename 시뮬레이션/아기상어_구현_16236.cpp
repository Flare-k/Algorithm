#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int MAX = 21;
int N, M;
int sec, sharkSize, howManyEat;
int sea[MAX][MAX];
int dist[MAX][MAX];
bool visit[MAX][MAX];

struct Fish {
    int x, y, size;
};

Fish shark;
vector<Fish> eat;

bool cmp(Fish a, Fish b) {
    if (a.size < b.size) return true;
    else if (a.size == b.size) {
        if (a.x < b.x) return true;
        else if (a.x == b.x) return a.y < b.y;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> sea[i][j];
            if (sea[i][j] == 9) {
                shark = {i, j, 2};
                sea[i][j] = 0;
            }
        }
    }

    while (1) {
        memset(visit, false, sizeof(visit));
        memset(dist, 0, sizeof(dist));
        eat.clear();

        sharkSize = shark.size;
        visit[shark.x][shark.y] = true;
        
        queue<Fish> q;
        q.push(shark);

        while (!q.empty()) {
            Fish now = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = now.x + dx[i];
                int ny = now.y + dy[i];

                if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                if (sea[nx][ny] > sharkSize) continue;
                if (visit[nx][ny] == true) continue;

                visit[nx][ny] = true;
                dist[nx][ny] = dist[now.x][now.y] + 1;
                q.push({nx, ny});

                if (sea[nx][ny] != 0 && sea[nx][ny] < sharkSize) {
                    eat.push_back({nx, ny, dist[nx][ny]});  // 위치, 거리
                }
            }
        }

        Fish tmp;
        if (eat.size() >= 1) {
            sort(eat.begin(), eat.end(), cmp);

            tmp = eat.front();
            shark = {tmp.x, tmp.y, sharkSize};
            sea[shark.x][shark.y] = 0;
            howManyEat++;
            sec += tmp.size;
        }
        else break;
        
        if (howManyEat == shark.size) {
            shark.size += 1;
            howManyEat = 0;
        }
    }

    cout << sec;

    return 0;
}