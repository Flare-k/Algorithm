#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N, W, H;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> W >> H;

    double K = sqrt(pow(W, 2) + pow(H, 2));

    for (int i = 0; i < N; i++) {
        int s;
        cin >> s;

        if (s <= W || s <= H || s <= K) cout << "DA" << '\n';
        else cout << "NE" << '\n';
    }

    return 0;
}