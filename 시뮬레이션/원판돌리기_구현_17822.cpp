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
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[i].dq[j] == 0) continue;
            
            // 좌우
            if (j > 0 && j < M - 1) {
                if (v[i].dq[j] == v[i].dq[j - 1]) {
                    visit[i][j] = true;
                    visit[i][j - 1] = true;
                    cnt++;
                }
                if (v[i].dq[j] == v[i].dq[j + 1]) {
                    visit[i][j] = true;
                    visit[i][j + 1] = true;
                    cnt++;
                }
            }
            else if (j == 0) {
                if (v[i].dq[j] == v[i].dq[M - 1]) {
                    visit[i][j] = true;
                    visit[i][M - 1] = true;
                    cnt++;
                }
                if (v[i].dq[j] == v[i].dq[1]) {
                    visit[i][j] = true;
                    visit[i][1] = true;
                    cnt++;
                }
            }
            else if (j == M - 1) {
                if (v[i].dq[j] == v[i].dq[j - 1]) {
                    visit[i][j] = true;
                    visit[i][j - 1] = true;
                    cnt++;
                }
                if (v[i].dq[j] == v[i].dq[0]) {
                    visit[i][j] = true;
                    visit[i][0] = true;
                    cnt++;
                }
            }

            // 다음 원판
            if (i > 1 && i < N) {
                if (v[i].dq[j] == v[i - 1].dq[j]) {
                    visit[i][j] = true;
                    visit[i - 1][j] = true;
                    cnt++;
                }
                if (v[i].dq[j] == v[i + 1].dq[j]) {
                    visit[i][j] = true;
                    visit[i + 1][j] = true;
                    cnt++;
                }
            }
            else if (i == 1) {
                if (v[i].dq[j] == v[2].dq[j]) {
                    visit[i][j] = true;
                    visit[2][j] = true;
                    cnt++;
                }
            }
            else if (i == N) {
                if (v[i].dq[j] == v[N - 1].dq[j]) {
                    visit[i][j] = true;
                    visit[N - 1][j] = true;
                    cnt++;
                }
            }
        }
    }

    if (cnt == 0) {
        int sum = 0, t = 0;

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                if (v[i].dq[j] != 0) {
                    sum += v[i].dq[j];
                    t++;
                }
            }
        }

        double avg = double(sum) / double(t);

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                if (v[i].dq[j] == 0) continue;
                
                if (v[i].dq[j] == avg) continue;
                else if (v[i].dq[j] > avg) v[i].dq[j]--;
                else if (v[i].dq[j] < avg) v[i].dq[j]++;
            }
        }
    }
}

void clearAdj() {
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (visit[i][j] == true) v[i].dq[j] = 0;
        }
    }

    memset(visit, false, sizeof(visit));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> T;
    v.resize(N + 1);

    int num;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> num;
            v[i].dq.push_back(num);
        }
    }

    int x, d, k;
    for (int t = 0; t < T; t++) {
        // x의 배수인 원판을 d방향으로 k칸 회전
        cin >> x >> d >> k;
        
        // 회전 후, 인접한 원판 확인
        for (int i = x; i <= N; i += x) {
            v[i].shuffle(d, k);
        }

        checkAdj();
        clearAdj();
    }

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            answer += v[i].dq[j];
        }
    }
    
    cout << answer;

    return 0;
}