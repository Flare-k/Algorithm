#include <iostream>
#include <queue>
#include <utility>

using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    init();

    queue<pair<int, int>> player;
    player.push({0, 0});

    int maxNum = -1;
    for (int i = 0; i < 5; i++) {
        int sum = 0;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        sum += (a + b + c + d);

        if (sum > player.front().second) {
            player.pop();
            player.push({i + 1, sum});
        }
    }

    cout << player.front().first << " " << player.front().second;

    return 0;
}