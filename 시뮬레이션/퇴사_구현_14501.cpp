#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int answer;
struct Node {
    int T, P;
};

vector<Node> days;

void run(int level, int price) {
    if (level == N) answer = max(answer, price);
    if (level >= N) return;

    run(level + days[level].T, price + days[level].P);
    run(level + 1, price);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    int T, P;
    for (int i = 0; i < N; i++) {
        cin >> T >> P;
        days.push_back({T, P});
    }

    run(0, 0);

    cout << answer;

    return 0;
}