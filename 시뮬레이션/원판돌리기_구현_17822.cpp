#include <iostream>
#include <deque>
#include <vector>
#include <cstring>
using namespace std;

int N, M, T;
const int MAX = 51;
bool visit[MAX][MAX];
enum {
    CLOCK, NCLOCK
};

struct Node {
    deque<int> dq;

    void shuffle(int dir, int k) {
        while (k--) {
            
            if (dir == CLOCK) {
                int num = dq.back();
                dq.pop_back();
                dq.push_front(num);
            }
            else if (dir == NCLOCK) {
                int num = dq.front();
                dq.pop_front();
                dq.push_back(num);
            }
        }
    }
};

vector<Node> v;

void checkAdj() {
    memset(visit, false, sizeof(visit));

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[i].dq[j] == 0) continue;
            // 좌우
            if (j > 0 && j < M - 1) {
                if (v[i].dq[j] == v[i].dq[j - 1]) {
                    visit[i][j] = true;
                    visit[i][j - 1] = true;
                }
                if (v[i].dq[j] == v[i].dq[j + 1]) {
                    visit[i][j] = true;
                    visit[i][j + 1] = true;
                }
            }
            else if (j == 0) {
                if (v[i].dq[j] == v[i].dq[M - 1]) {
                    visit[i][j] = true;
                    visit[i][M - 1] = true;
                }
                if (v[i].dq[j] == v[i].dq[j + 1]) {
                    visit[i][j] = true;
                    visit[i][j + 1] = true;
                }
            }
            else if (j == M - 1) {
                if (v[i].dq[j] == v[i].dq[j - 1]) {
                    visit[i][j] = true;
                    visit[i][j - 1] = true;
                }
                if (v[i].dq[j] == v[i].dq[0]) {
                    visit[i][j] = true;
                    visit[i][0] = true;
                }
            }

            // 다음 원판
            if (i != N) {
                if (v[i].dq[j] == v[i + 1].dq[j]) {
                    visit[i][j] = true;
                    visit[i + 1][j] = true;
                }
            }
        }
    }
}

void clearAdj() {
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[i].dq[j] != 0 && visit[i][j]) {
                v[i].dq[j] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> T;
    v.resize(N + 1);

    int num;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> num;
            v[i].dq.push_back(num);
        }
    }

    int x, d, k;
    for (int t = 0; t < T; t++) {
        // x의 배수인 원판을 d방향으로 k칸 회전
        cin >> x >> d >> k;
        // 회전 후, 인접한 원판 확인

        // cout << '\n';
        // for (int a = 1; a <= N; a++) {
        //     for (int b = 0; b < M; b++) {
        //         cout << v[a].dq[b];
        //     }
        //     cout << '\n';
        // }
        for (int i = 1; i <= N; i++) {
            if (i % x == 0) {
                v[i].shuffle(d, k);
            }
        }

        if (t == 2) {
            cout << '\n';
            for (int a = 1; a <= N; a++) {
                for (int b = 0; b < M; b++) {
                    cout << v[a].dq[b];
                }
                cout << '\n';
            }
            int a=  1;
        }

        checkAdj();
        clearAdj();
    }

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[i].dq[j] != 0) answer += v[i].dq[j];
        }
    }
    
    cout << answer;

    return 0;
}