#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 16
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int arr[MAX][MAX];
int cpy[MAX][MAX];
bool visit[MAX][MAX];
int N, M, D;
int answer;
struct Node {
    int x, y,  dist;
};
vector<Node> list;

bool cmp(Node& A, Node& B) {
    if (A.dist < B.dist) return true;
    else if (A.dist == B.dist) return A.y < B.y;
    return false;
}

void moveOpponent() {
    for (int j = 0; j < M; j++) {
        for (int i = N - 1; i >= 0; i--) {
            if (i != 0) arr[i][j] = arr[i - 1][j];
            else arr[i][j] = 0;
        }
    }
}

int run() {
    int iter = N;
    int cnt = 0;
    vector<Node> target; // 각 궁수의 타겟 후보
    vector<Node> result;    // 타겟 중 하나 선점

    while (iter--) {
        queue<Node> q;
        result.clear();

        for (auto v : list) {
            memset(visit, false, sizeof(visit));
            target.clear();
            q.push({v.x, v.y, 0});
            visit[v.x][v.y] = true;

            while (!q.empty()) {
                Node now = q.front();
                q.pop();

                if (now.dist > D) continue;
                if ((now.dist > 0 && now.dist <= D) && arr[now.x][now.y] == 1) target.push_back(now);

                for (int i = 0; i < 4; i++) {
                    int nx = now.x + dx[i];
                    int ny = now.y + dy[i];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    if (visit[nx][ny]) continue;

                    q.push({nx, ny, now.dist + 1});
                    visit[nx][ny] = true;
                }
            }

            if (target.size() > 0) {
                sort(target.begin(), target.end(), cmp);
                result.push_back(target.front());
            }
        }

        for (auto r : result) {
            if (arr[r.x][r.y] != 0) {
                arr[r.x][r.y] = 0;
                cnt++;
            }
        }

        moveOpponent();
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> D;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    vector<int> archer(M, 0);
    memcpy(cpy, arr, sizeof(cpy));

    for (int i = 0; i < 3; i++) {
        archer[i] = 1;
    }

    sort(archer.begin(), archer.end());

    do {
        memcpy(arr, cpy, sizeof(arr));
        list.clear();   // 궁수 경우의 수

        for (int i = 0; i < M; i++) {
            if (archer[i] == 1) {
                list.push_back({N, i});
            }
        }

        answer = max(answer, run());
    } while (next_permutation(archer.begin(), archer.end()));
    
    cout << answer << '\n';

    return 0;
}