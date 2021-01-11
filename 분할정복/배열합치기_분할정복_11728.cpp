#include <iostream>
#include <algorithm>

using namespace std;

// 분할정복으로 하는게 vector로 풀때보다 0.2초정도 빠르고 메모리도 덜 소비한다.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a[1000001], b[1000001];

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int nNext = 0, mNext = 0;
    while (nNext < n && mNext < m) {
        if (a[nNext] <= b[mNext]) {
            cout << a[nNext] << ' ';
            nNext++;
        }
        else {
            cout << b[mNext] << ' ';
            mNext++;
        }
    }

    while (nNext < n) {
        cout << a[nNext] << ' ';
        nNext++;
    }
    while (mNext < m) {
        cout << b[mNext] << ' ';
        mNext++;
    }

    return 0;
}