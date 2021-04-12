#include <iostream>
#include <cmath>
using namespace std;

int n;
int arr[10];

int go(int a, int b, int idx, int i) {
    if (idx == 0) {  // !!
        return (a - b) * (a + b);
    }
    else if (idx == 1) { // #
        return a > b ? a : b;
    }
    else if (idx == 2) { // $
        return pow(a, 2) - pow(b, 2);
    }
    else if (idx == 3) { // &
        return pow((a + b), 2);
    }

    return 1;
}

int cnt = 0;

void run(int level, int start, int sum) {
    if (level == n - 1) {
        if (sum == 100) cnt++;
        return;
    }

    for (int i = start; i < n - 1; i++) {
        run(level + 1, i + 1, go(sum, arr[i + 1], 0, i));
        run(level + 1, i + 1, go(sum, arr[i + 1], 1, i));
        run(level + 1, i + 1, go(sum, arr[i + 1], 2, i));
        run(level + 1, i + 1, go(sum, arr[i + 1], 3, i));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    run (0, 0, arr[0]);

    cout << cnt;

    return 0;
}