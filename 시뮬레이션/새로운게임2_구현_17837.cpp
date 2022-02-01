#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_HORSE = 4;
const int MAX_ITER = 1000;
const int MAX = 13;
const int dx[] = {0, 0, 0, -1, 1};
const int dy[] = {0, 1, -1, 0, 0};

struct Node {
    int x, y, dir;
};

int N, K;
vector<int> horse[MAX][MAX];
int chess[MAX][MAX];        // 흰색, 빨간색, 파란색 확인만..
vector<Node> cur;

enum {
    WHITE, RED, BLUE
};

bool exitCond() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int size = horse[i][j].size();
            if (size >= MAX_HORSE) return true;
        }
    }
    return false;
}

bool outOfRange(int nx, int ny) {
    if (nx < 1 || nx > N || ny < 1 || ny > N) return true;
    return false;
}

void run() {
    int turn;

    for (turn = 1; turn <= MAX_ITER; turn++) {
        for (int h = 0; h < K; h++) {
            if (exitCond()) {
                cout << turn << '\n';
                return;
            }

            Node now = cur[h];
            vector<int> tmp;
            bool flag = false;

            int nx = now.x + dx[now.dir];
            int ny = now.y + dy[now.dir];
            int ndir = now.dir;

            if (chess[nx][ny] == BLUE || outOfRange(nx, ny)) {
                ndir = now.dir < 3 ? 3 - now.dir : 7 - now.dir;
                nx = now.x + dx[ndir];
                ny = now.y + dy[ndir];

                if (chess[nx][ny] == BLUE || outOfRange(nx, ny)) {
                    cur[h].dir = ndir;
                    continue;
                }

                flag = true;    // 다음 칸이 파란칸이 아니거나 흰칸인 경우
            }

            // 특정 좌표에서 현재 말의 위치
            tmp = horse[now.x][now.y];
            int idx = 0;
            int size = tmp.size();

            for (int i = 0; i < size; i++) {
                if (tmp[i] == h) {
                    idx = i;
                    break;
                }
            }

            cur[h] = {nx, ny, now.dir};

            if (flag) cur[h].dir = ndir;

            // 빨간 칸인 경우 순서 변경
            if (chess[nx][ny] == RED) {
                if (idx == 0) reverse(tmp.begin(), tmp.end());
                else reverse(tmp.begin() + idx, tmp.end());
            }

            // 흰칸 또는 빨간 칸인 경우 업어야 할 때가 있음
            for (int i = idx; i < size; i++) {
                cur[tmp[i]].x = nx;
                cur[tmp[i]].y = ny;
                horse[nx][ny].push_back(tmp[i]);
            }

            if (idx == 0) horse[now.x][now.y].clear();
            else horse[now.x][now.y].erase(horse[now.x][now.y].begin() + idx, horse[now.x][now.y].end());
        }

        if (exitCond()) {
            cout << turn << '\n';
            return;
        }
    }

    cout << -1 << '\n';

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> chess[i][j];
        }
    }

    cur.resize(K);

    int x, y, dir;
    for (int num = 0; num < K; num++) {
        cin >> x >> y >> dir;   // 행, 열, 방향
        
        cur[num] = {x, y, dir};
        horse[x][y].push_back(num);
    }

    run();

    return 0;
}