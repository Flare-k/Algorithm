#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    vector<int> scores(5);

    while (T--) {
        scores.clear();
        scores.resize(5);
        
        for (int i = 0; i < 5; i++) {
            cin >> scores[i];
        }

        sort(scores.begin(), scores.end());

        if (scores[3] - scores[1] >= 4) cout << "KIN" << '\n';
        else cout << scores[1] + scores[2] + scores[3] << '\n';
    }

    return 0;
}