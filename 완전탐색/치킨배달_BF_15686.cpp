#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAX 51
using namespace std;

int N, M;
int arr[MAX][MAX];
bool used[MAX];
int answer = 21e8;
struct Dir {
    int x, y;
};

vector<Dir> chicken;
vector<Dir> home;

void distOfChicken() {
    int sum = 0;

    for (Dir h : home) {
        // 각 집에서 선정된 M개의 치킨집 간에 가장 가까운 거리
        int dist = 21e8;

        for (int i = 0; i < chicken.size(); i++) {
            if (used[i]) {
                int d = abs(h.x - chicken[i].x) + abs(h.y - chicken[i].y);
                dist = min(d, dist);
            }
        }

        sum += dist;
    }

    answer = min(answer, sum);
}

void run(int level, int start) {
    if (level == M) {
        distOfChicken();
        return;
    }

    for (int i = start; i < chicken.size(); i++) {
        if (used[i]) continue;

        used[i] = true;
        run(level + 1, i + 1);
        used[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 1) home.push_back({i, j});
            else if (arr[i][j] == 2) chicken.push_back({i, j});
        }
    }

    run(0, 0);

    cout << answer << '\n';

    return 0;
}