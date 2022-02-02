#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#define MAX 51
using namespace std;

int N, M, T;
deque<int> dq[MAX];
bool visit[MAX][MAX];
enum {
    CLOCKWISE, COUNT_CLOCKWISE
};

void clearAdjacent() {
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (visit[i][j]) dq[i][j] = 0;
        }
    }
}

void rotate(int x, int d, int k) {
    for (int i = x; i <= N; i += x) {
        if (d == CLOCKWISE) {
            for (int j = 0; j < k; j++) {
                int num = dq[i].back();
                dq[i].pop_back();
                dq[i].push_front(num);
            }
        }
        else if (d == COUNT_CLOCKWISE) {
            for (int j = 0; j < k; j++) {
                int num = dq[i].front();
                dq[i].pop_front();
                dq[i].push_back(num);
            }
        }
    }
}

void checkAdjacent(int x, int d, int k) {
    memset(visit, false, sizeof(visit));
    int check = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (dq[i][j] == 0) continue;

            int l = j - 1 < 0 ? M - 1 : j - 1;
            int r = j + 1 >= M ? 0 : j + 1;

            int left = dq[i][l];
            int num = dq[i][j];
            int right = dq[i][r];

            if (left == num) {
                visit[i][l] = true;
                visit[i][j] = true;
                check++;
            }

            if (num == right) {
                visit[i][r] = true;
                visit[i][j] = true;
                check++;
            }
            
            if (i == 1) {
                if (num == dq[i + 1][j]) {
                    visit[i + 1][j] = true;
                    visit[i][j] = true;
                    check++;
                }
            }
            else if (i > 1 && i < N) {
                if (num == dq[i - 1][j]) {
                    visit[i - 1][j] = true;
                    visit[i][j] = true;
                    check++;
                }
                if (num == dq[i + 1][j]) {
                    visit[i + 1][j] = true;
                    visit[i][j] = true;
                    check++;
                }
            }
            else if (i == N) {
                if (num == dq[i - 1][j]) {
                    visit[i - 1][j] = true;
                    visit[i][j] = true;
                    check++;
                }
            }
        }
    }

    if (check == 0) {
        double sum = 0, cnt = 0;

        for (int i = 1; i <= N; i++) {
            for (int k = 0; k < M; k++) {
                if (dq[i][k] != 0) {
                    sum += dq[i][k];
                    cnt++;
                }
            }
        }

        double avg = sum / cnt;

        for (int i = 1; i <= N; i++) {
            for (int k = 0; k < M; k++) {
                if (dq[i][k] == 0) continue;
                
                if (dq[i][k] > avg) dq[i][k]--;
                else if (dq[i][k] < avg) dq[i][k]++;
            }
        }
    }
    else clearAdjacent();
}

void answer() {
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            sum += dq[i][j];
        }
    }

    cout << sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> T;

    // 원판에 적힌 수
    int num;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> num;
            dq[i].push_back(num);
        }
    }

    while (T--) {
        int x, d, k;
        cin >> x >> d >> k;
        rotate(x, d, k);
        checkAdjacent(x, d, k);
    }

    answer();

    return 0;
}