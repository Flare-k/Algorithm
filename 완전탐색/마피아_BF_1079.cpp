#include <iostream>
#include <algorithm>
#define MAX 17
using namespace std;

int N, mafia;
int arr[MAX][MAX];
bool alive[MAX];
int guilty[MAX];
int answer;

void updateGuilty(int i, int num, int& idx) {
    int maxx = -21e8;
    for (int j = 0; j < N; j++) {
        if (alive[j]) continue;

        guilty[j] += (arr[i][j] * num);

        if (maxx < guilty[j]) {
            idx = j;
            maxx = guilty[j];
        }
    }
}

void run(int cnt, int night, int max_idx) {
    if (cnt == 1 || alive[mafia]) {
        answer = max(answer, night);
        return;
    }

    // 밤에 죽일 사람 고르기
    if (cnt % 2 == 0) {
        for (int i = 0; i < N; i++) {
            if (i == mafia || alive[i]) continue;

            int idx = 0;

            alive[i] = true;
            updateGuilty(i, 1, idx);
            run(cnt - 1, night + 1, idx);
            updateGuilty(i, -1, idx);
            alive[i] = false;
        }
    }
    // 낮에 죽일 사람
    else {
        alive[max_idx] = true;
        run(cnt - 1, night, max_idx);
        alive[max_idx] = false;
    }
}

void init() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> guilty[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    cin >> mafia;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    int idx = 0, maxx = -21e8;

    for (int i = 0; i < N; i++) {
        if (maxx < guilty[i]) {
            maxx = guilty[i];
            idx = i;
        }
    }

    run(N, 0, idx);

    cout << answer;

    return 0;
}
