#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int dx[] = {0, -1, 1, 0, 0};
const int dy[] = {0, 0, 0, -1, 1};
const int MAX = 21;
int N, M, k;
int arr[MAX][MAX];
bool visit[MAX][MAX];

struct Dir {
    int x, y, sharkNum, dir;
};

struct Node {
    int sharkNum;
    int smell;
};

Dir check[MAX][MAX];
Node smells[MAX][MAX];

struct Shark {
    int x, y;
    int dir;
    bool live;
    vector<int> priorDir[5];
};

vector<Shark> sharks;

void updateSmell(int t) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (visit[i][j]) {
                int time = t - smells[i][j].smell;
                if (time == k) {
                    smells[i][j] = {};
                    visit[i][j] = false;
                }
            }
        }
    }
}

void run(int seconds) {
    memset(check, {}, sizeof(check));

    for (int idx = 1; idx <= M; idx++) {
        bool live = sharks[idx].live;
        if (live == false) continue;

        int x = sharks[idx].x;
        int y = sharks[idx].y;
        int dir = sharks[idx].dir;
        bool flag = false;

        // 1) 인접한 칸에 아무 냄새가 없는 칸으로 방향 잡기
        vector<int> prior = sharks[idx].priorDir[dir];

        for (auto d : prior) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if (visit[nx][ny]) continue;
            
            Dir now = {nx, ny, idx, d};
            
            if (check[nx][ny].sharkNum == 0) {
                check[nx][ny] = now;
            }
            else {
                Dir pre = check[nx][ny];
                Dir post = now;
                check[nx][ny] = pre.sharkNum < post.sharkNum ? pre : post;
            }

            arr[x][y] = 0;
            flag = true;
            break;
        }

        // 2) 주변에 본인의 냄새가 있다면
        if (!flag) {
            for (auto d : prior) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 1 || nx > N || ny < 1 || ny > N) continue;

                if (visit[nx][ny] && smells[nx][ny].sharkNum == idx) {
                    Dir now = {nx, ny, idx, d};

                    if (check[nx][ny].sharkNum == 0) {
                        check[nx][ny] = now;
                    } 
                    else {
                        Dir pre = check[nx][ny];
                        Dir post = now;
                        check[nx][ny] = pre.sharkNum < post.sharkNum ? pre : post;
                    }

                    arr[x][y] = 0;
                    break;
                }
            }
        }

    }

    // sharkNum의 우선순위가 높은 값으로 smells, arr 값 갱신
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (check[i][j].sharkNum != 0) {
                int sharkNum = check[i][j].sharkNum;
                visit[i][j] = true;
                arr[i][j] = sharkNum;

                smells[i][j] = {sharkNum, seconds};

                sharks[sharkNum].x = check[i][j].x;
                sharks[sharkNum].y = check[i][j].y;
                sharks[sharkNum].dir = check[i][j].dir;
            }
        }
    }
}

void checkSharkLive() {
    vector<bool> tmp(M + 1);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] != 0) tmp[arr[i][j]] = true;
        }
    }

    for (int i = 1; i <= M; i++) {
        if (tmp[i] == false) sharks[i].live = false;
    }
}

bool checkExitCondition() {
    bool one = false;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] > 1) return false;
            if (arr[i][j] == 1) one = true;
        }
    }

    return one;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> k;

    sharks.resize(M + 1);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];

            if (arr[i][j] != 0) {
                sharks[arr[i][j]].x = i;
                sharks[arr[i][j]].y = j;
                sharks[arr[i][j]].live = true;
                smells[i][j] = {arr[i][j], 0};
                visit[i][j] = true;
            }
        }
    }

    for (int i = 1; i <= M; i++) {
        int dir;
        cin >> dir;
        sharks[i].dir = dir;
    }

    int u, d, l, r;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= 4; j++) {
            cin >> u >> d >> l >> r;
            sharks[i].priorDir[j].push_back(u);
            sharks[i].priorDir[j].push_back(d);
            sharks[i].priorDir[j].push_back(l);
            sharks[i].priorDir[j].push_back(r);
        }
    }

    for (int sec = 1; sec <= 1000; sec++) {
        run(sec);   // 상어 이동
        checkSharkLive();   // 상어 생사 여부
        updateSmell(sec);   // 냄새 시간 업데이트

        // 1만 남았는지 확인
        if (checkExitCondition()) {
            cout << sec;
            break;
        }
        else if (sec == 1000) {
            cout << -1;
        }
    }

    return 0;
}