#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
vector<int> vec;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    vec.resize(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }

    int cnt = 0;
    int e = 0, answer = 0;
    
    if (vec[0] % 2) cnt++;

    for (int s = 0; s < N; s++) {

        while (e < N - 1 && cnt + vec[e + 1] % 2 <= K) {
            e++;
            cnt += vec[e] % 2;
        }

        answer = max(answer, e - s + 1 - cnt);
        cnt -= vec[s] % 2;
    }

    cout << answer << '\n';

    return 0;
}