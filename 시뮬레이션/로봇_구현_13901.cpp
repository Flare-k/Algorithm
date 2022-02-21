#include <iostream>
#include <vector>
#define MAX 1000
using namespace std;

const int dx[] = {0, -1, 1, 0, 0};
const int dy[] = {0, 0, 0, -1, 1};
int map[MAX][MAX];
bool visit[MAX][MAX];
int R, C, K, sr, sc;
enum {
    ROAD, WALL
};
vector<int> v;

bool CanMove(int x, int y) {
    for (int i = 1; i <= 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
           if (map[nx][ny] == ROAD && visit[nx][ny] == false) return true;
        }
    }
    return false;
}

void run() {
    int nx = sr, ny = sc;
    visit[nx][ny] = true;
    int idx = 0;

    while (1) {
        if (!CanMove(nx, ny)) break;

        while (1) {
            nx += dx[v[idx]];
            ny += dy[v[idx]];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) break;
            if (map[nx][ny] == WALL) break;
            if (visit[nx][ny] == true) break;
            
            visit[nx][ny] = true;
        }

        nx -= dx[v[idx]];
        ny -= dy[v[idx]];

        idx++;
        if (idx == 5) idx = 0;
    }

    cout << nx << " " << ny << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> K;

    while (K--) {
        int a, b;
        cin >> a >> b;
        map[a][b] = WALL;
    }

    cin >> sr >> sc;

    for (int i = 0; i < 4; i++) {
        int d;
        cin >> d;
        v.push_back(d);
    }

    run();

    return 0;
}