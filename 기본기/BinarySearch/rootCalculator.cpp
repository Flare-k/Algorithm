#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int vec[n];
    for (int i = 0; i < n; i++) {
        vec[i] = i * i;
    }

    int s = 0;
    int e = n;

    while (1) {
        int m = (s + e) / 2;

        if (s > e) {
            cout << m;
            break;
        }

        if (vec[m] == n) {
            cout << m;
            break;
        }

        if (vec[m] < n) {
            s = m + 1;
        }
        else {
            e = m - 1;
        }
    }

    return 0;
}