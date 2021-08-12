#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int A[51], P[51] = {-1, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        P[i] = 0;

        for (int j = 0; j < n; j++) {
            if (A[j] > A[i]) P[j]++;
        }

        while (1) {
            bool flag = false;
            for (int k = 0; k < n; k++) {
                if (i != k && i > k && P[i] == P[k]) {
                    P[i]++;
                    flag = true;
                }
            }

            if (!flag) break;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << P[i] << ' ';
    }

    return 0;
}