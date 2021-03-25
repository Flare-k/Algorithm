#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    char cloud[n][n + 1];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cloud[i][j];
        }
    }

    int s = 0;
    int e = n - 1;
    int dx = 0, dy = 0;
    // 가로
    while (1) {
        int mid = (s + e) / 2;

        if (s > e) {
            break;
        }

        if (cloud[mid][0] == '#') {
            dx = max(dx, mid);
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }

    // 세로
    s = 0;
    e = n - 1;

    while (1) {
        int mid = (s + e) / 2;

        if (s > e) {
            break;
        }

        if (cloud[dx][mid] == '#') {
            dy = max(dy, mid);
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }

    cout << dx << " " << dy;

    return 0;
}
/*
input
8
########
########
########
########
########
###00000
00000000
00000000

output
> 5 2
*/