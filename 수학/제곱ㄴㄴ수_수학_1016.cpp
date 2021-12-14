#include <iostream>
using namespace std;

long long arr[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long minn, maxx;
    int cnt = 0;

    cin >> minn >> maxx;

    for (long long i = 2; i * i <= maxx; i++) {
        long long n = minn / (i * i);

        if (minn % (i * i)) n++;

        while (n * i * i <= maxx) {
            arr[n * i * i - minn] = 1;
            cout << n * i * i - minn << ' ';
            n++;
        }
    }
    cout << '\n';
    for (int i = 0; i <= maxx - minn; i++) {
        if (arr[i] == 0) cnt++;
    }

    cout << cnt;

    return 0;
}