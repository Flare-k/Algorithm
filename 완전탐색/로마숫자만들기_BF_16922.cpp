#include <iostream>
#include <vector>
#define MAX 1001
using namespace std;

int N, cnt;
vector<int> arr = {1, 5, 10, 50};
bool visit[MAX];

void run(int level, int start, int sum) {
    if (level == N) {
        if (!visit[sum]) {
            visit[sum] = true;
            cnt++;
        }
        return;
    }

    for (int i = start; i < 4; i++) {
        run(level + 1, i, sum + arr[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    run(0, 0, 0);

    cout << cnt;

    return 0;
}