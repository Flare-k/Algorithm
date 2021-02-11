#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int arr[301][301];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int k;
    cin >> k;
    
    int i, j, x, y;
    while (k--) {
        cin >> i >> j >> x >> y;
        int sum = 0;
        for (int r = i - 1; r < x; r++) {
            for (int c = j - 1; c < y; c++) {
                sum += arr[r][c];
            }
        }
        cout << sum << '\n';
    }

    return 0;
}