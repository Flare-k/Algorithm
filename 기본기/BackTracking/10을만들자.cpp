#include <iostream>
using namespace std;

int cnt = 0;

void run(int level, int n, int sum) {
    if (level > n) return;
    
    if (level == n && sum == 10) {
        cnt++;
        return;
    }

    for (int i = 1; i < 10; i++) {
        run(level + 1, n, sum + i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    run(0, n, 0);

    cout << cnt;

    return 0;
}