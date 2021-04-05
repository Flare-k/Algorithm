#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 41;
int res[MAX];
int path[MAX];
int minGop = 21e8;
int N, M;
vector<int> cards;

void run(int level, int start, int gop) {
    if (level == M) {
        if (minGop > gop) {
            minGop = gop;
            memcpy(res, path, 4 * 41);
        }
        return;
    }

    for (int i = start; i < N; i++) {
        path[level] = cards[i];
        run(level + 1, i + 1, gop * cards[i]);
        path[level] = 0;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;  // N개의 패가 주어지고 상대에게 M개의 패를 전달해주어야 한다.
                    // M개 패의 곱이 최소이면 나의 승리이다.

    int c;
    for (int i = 0; i < N; i++) {
        cin >> c;
        cards.push_back(c);
    }

    sort(cards.begin(), cards.end());
    
    run(0, 0, 1);

    for (int i = 0; i < MAX; i++) {
        if (res[i]) cout << res[i] << ' ';
    }

    return 0;
}
