#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int sx[] = {-1, 0, 1, 0};
const int sy[] = {0, -1, 0, 1};
const int MAX = 4;
int arr[MAX][MAX];
int smell[MAX][MAX];
bool used[5];
int M, S;

struct Fish {
    int x, y, dir;
};

Fish shark;
vector<string> mc;

void moveCase(int level, string path) {
    if (level == 3) {
        mc.push_back(path);
        return;
    }

    for (int i = 1; i <= 4; i++) {
        moveCase(level + 1, path + to_string(i));
    }
}

queue<Fish> sharkMove(queue<Fish>& fish, int time) {
    int x = shark.x;
    int y = shark.y;

    string target;
    int max_eat = -21e8;
    
    bool visit[MAX][MAX];

    for (auto dir : mc) {
        memset(visit, false, sizeof(visit));
        int s_x = x;
        int s_y = y;
        int eat = 0;
        bool flag = false;

        for (int i = 0; i < dir.length(); i++) {
            int idx = (dir[i] - '0') - 1;
            s_x += sx[idx];
            s_y += sy[idx];

            if (s_x < 0 || s_y < 0 || s_x >= MAX || s_y >= MAX) {
                flag = false;
                break;
            }
            if (!visit[s_x][s_y]) {
               visit[s_x][s_y] = true;
               eat += arr[s_x][s_y];
               flag = true;
            }
        }

        if (max_eat < eat && flag) {
            max_eat = eat;
            target = dir;
        }
    }

    for (char ch : target) {
        int i = (ch - '0') - 1;
        x += sx[i];
        y += sy[i];

        if (arr[x][y] != 0) {
            arr[x][y] = 0;
            smell[x][y] = time;
        }
    }

    shark = {x, y};

    int size = fish.size();

    while (size--) {
        Fish now = fish.front();
        fish.pop();
        if (arr[now.x][now.y] == 0) continue;
        fish.push(now);
    }

    return fish;
}

bool canNotMove(int x, int y, int time) {
    if (smell[x][y] != 0 && time - smell[x][y] <= 2) return true;
    if (shark.x == x && shark.y == y) return true;
    if (x < 0 || y < 0 || x >= MAX || y >= MAX) return true;
    return false;
}

void run(queue<Fish>& fish, int time) {
    queue<Fish> nq;
    int size = fish.size();

    while (size--) {
        Fish now = fish.front();
        fish.pop();

        int x = now.x;
        int y = now.y;
        int dir = now.dir;

        int nx, ny, ndir;
        bool flag = false;

        for (int i = 0; i < 8; i++) {
            ndir = (8 + dir - i) % 8;
            nx = x + dx[ndir];
            ny = y + dy[ndir];

            if (canNotMove(nx, ny, time)) continue;

            flag = true;
            arr[x][y]--;
            arr[nx][ny]++;
            fish.push({nx, ny, ndir});

            break;
        }

        if (!flag) {
            fish.push({x, y, dir});
        }

        nq.push(now);
    }

    fish = sharkMove(fish, time);

    // 복제 마법 완료
    while (!nq.empty()) {
        Fish now = nq.front();
        fish.push(now);
        arr[now.x][now.y]++;
        nq.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> S;

    queue<Fish> fish;
    int x, y, dir;

    for (int i = 0; i < M; i++) {
        cin >> x >> y >> dir;
        fish.push({x - 1, y - 1, dir - 1});
        arr[x - 1][y - 1]++;
    }   

    cin >> x >> y;

    shark = {x - 1, y - 1};

    moveCase(0, "");

    for (int time = 1; time <= S; time++) {
        run(fish, time);
    }

    cout << fish.size();

    return 0;
}