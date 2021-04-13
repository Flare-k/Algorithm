#include <iostream>
#include <cstring>
using namespace std;

int used[8];
int n;
int score[8];
int maxSum = -21e8;
int path[8];
int res[8];

bool check(int n) {
    for (int i = 0; i < n; i++) {
        if (!used[i]) return false;
    }
    return true;
}

void run(int level, int sum) {
    if (check(n)) {
        if (maxSum < sum) {
            maxSum = sum;
            memcpy(res, path, 4 * 8);
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (used[i] >= 1) continue;

        if (i - 1 >= 0) used[i - 1]++;
        used[i]++;
        if (i + 1 < n) used[i + 1]++;

        path[level] = score[i];
        run(level + 1, sum + score[i]);
        path[level] = 0;

        if (i - 1 >= 0) used[i - 1]--;
        used[i]--;
        if (i + 1 < n) used[i + 1]--;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> score[i];
    }

    run(0, 0);

    cout << res[0];
    for (int i = 1; i < 8; i++) {
        if (res[i]) {
            cout << "+" << res[i];
        }
    }
    cout << "=" << maxSum << '\n';

    return 0;
}