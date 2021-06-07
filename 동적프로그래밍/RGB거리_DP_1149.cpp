#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> homes(n + 1, vector<int>(3));
    int r, g, b;

    for (int i = 1; i <= n; i++) {
        cin >> r >> g >> b;
        homes[i][0] = min(homes[i - 1][1], homes[i - 1][2]) + r;
        homes[i][1] = min(homes[i - 1][0], homes[i - 1][2]) + g;
        homes[i][2] = min(homes[i - 1][0], homes[i - 1][1]) + b;
    }

    cout << min(homes[n][0], min(homes[n][1], homes[n][2]));

    
    return 0;
}