#include <iostream>
#include <vector>
using namespace std;

const int dx[3] = {-1, 0, 1};

vector<vector<int>> roads = {{0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0}};

int cnt = 0;

void run(int level, int now) {
    if (level == 7) {
        cnt++;
        return;
    }

    for (int i = 0; i < 3; i++) {
        int nx = now + dx[i];
        int ny = level + 1;

        if (nx < 0 || nx > 2 || ny < 0 || ny > 7) continue;

        run(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char start;
    cin >> start;

    if (start == 'A') {
        run(0, 0);
        cout << cnt;
    }
    else if (start == 'B') {
        run(0, 1);
        cout << cnt;
    }
    else {
        run(0, 2);
        cout << cnt;
    }

    return 0;
}