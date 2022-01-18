#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    int idx = 1;
    vector<int> scores;

    while (T--) {
        int num;
        cin >> num;

        scores.clear();
        scores.resize(num);

        for (int i = 0; i < num; i++) {
            cin >> scores[i];
        }

        sort(scores.begin(), scores.end(), greater<int>());

        int sub = 0;
        for (int i = 0; i < num - 1; i++) {
            sub = max(sub, scores[i] - scores[i + 1]);
        }

        cout << "Class " << idx++ << '\n';
        cout << "Max " << scores.front() << ", Min " << scores.back() << ", Largest gap " << sub << '\n';
    }

    return 0;
}