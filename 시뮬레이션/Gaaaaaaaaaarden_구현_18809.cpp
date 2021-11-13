#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 51;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int garden[MAX][MAX];
int gtmp[MAX][MAX];
int rtmp[MAX][MAX];
bool flower[MAX][MAX];
int N, M, G, R, answer = -21e8;

struct Dir {
    int x, y;
};

vector<Dir> poss;
vector<Dir> green;
vector<Dir> red;
int possSize;

void runGreenRed() {
    queue<Dir> gq;
    queue<Dir> rq;
    
    memset(gtmp, -1, sizeof(gtmp));
    memset(rtmp, -1, sizeof(rtmp));
    memset(flower, false, sizeof(flower));

    for (auto g : green) {
        gq.push({g.x, g.y});
        gtmp[g.x][g.y] = 0;
    }

    for (auto r : red) {
        rq.push({r.x, r.y});
        rtmp[r.x][r.y] = 0;
    }

    int flowerCnt = 0;
    int gqsize, rqsize, nx, ny;

    while (!gq.empty() || !rq.empty()) {
        gqsize = gq.size();
        rqsize = rq.size();

        while (gqsize--) {
            Dir now = gq.front();
            gq.pop();

            if (flower[now.x][now.y]) continue;

            for (int k = 0; k < 4; k++) {
                nx = now.x + dx[k];
                ny = now.y + dy[k];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (gtmp[nx][ny] != -1) continue;
                if (garden[nx][ny] == 0) continue;
                if (rtmp[nx][ny] != -1) continue;

                gtmp[nx][ny] = gtmp[now.x][now.y] + 1;
                gq.push({nx, ny});
            }
        }

        while (rqsize--) {
            Dir now = rq.front();
            rq.pop();

            for (int k = 0; k < 4; k++) {
                nx = now.x + dx[k];
                ny = now.y + dy[k];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (rtmp[nx][ny] != -1) continue;
                if (garden[nx][ny] == 0) continue;

                if (gtmp[nx][ny]== -1) {
                    rtmp[nx][ny] = rtmp[now.x][now.y] + 1;
                    rq.push({nx, ny});
                }
                else if (gtmp[nx][ny] == rtmp[now.x][now.y] + 1) {
                    flower[nx][ny] = true;
                    rtmp[nx][ny] = rtmp[now.x][now.y] + 1;
                    flowerCnt++;
                }
            }
        }
    }

    answer = max(answer, flowerCnt);
}

void select(int idx, int gcnt, int rcnt) {
    if (gcnt + rcnt > (possSize - idx)) return;
    if (gcnt == 0 && rcnt == 0) {
        runGreenRed();
        return;
    }

    if (idx == possSize) return;

    int x = poss[idx].x;
    int y = poss[idx].y;

    select(idx + 1, gcnt, rcnt);

    if (gcnt > 0) {
        green.push_back({x, y});
        select(idx + 1, gcnt - 1, rcnt);
        green.pop_back();
    }

    if (rcnt > 0) {
        red.push_back({x, y});
        select(idx + 1, gcnt, rcnt - 1);
        red.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> G >> R;

    // 0: 호수, 1: 뿌릴 수 없는 땅, 2: 뿌릴 수 있는 땅
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> garden[i][j];
            if (garden[i][j] == 2) poss.push_back({i, j});
        }
    }

    possSize = poss.size();
    select(0, G, R);

    cout << answer << '\n';

    return 0;
}