#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 1001
using namespace std;

int N;
int map[MAX];
int road[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> map[i];
    }

    fill(road, road + MAX, 21e8);
    road[1] = 0;

    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= i + map[i]; j++) {
            if (j > N) break;
            road[j] = min(road[i] + 1, road[j]);
        }
    }

    if (road[N] != 21e8) cout << road[N] << '\n';
    else cout << -1 << '\n';

    return 0;
}