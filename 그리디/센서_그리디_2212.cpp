#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> censor;
vector<int> iter;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    censor.resize(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> censor[i];
    }

    if (!censor.empty()) sort(censor.begin(), censor.end());

    int answer = 0;

    if (K >= N) cout << 0;
    else {

        vector<int> diff(N - 1, 0);

        for (int i = 0; i < N - 1; i++) {
            diff[i] = censor[i + 1] - censor[i];
        }

        sort(diff.begin(), diff.end());

        for (int i = 0; i < N - K; i++) {
            answer += diff[i];
        }

        cout << answer;
    }
    return 0;
}