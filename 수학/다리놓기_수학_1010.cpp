#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    int N, M;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> N >> M;

        long long bridge = 1;

        if (N > (M/2)) N = (M - N);

        for (int i = (M - N + 1); i <= M; i++) {
            bridge *= i;
        }

        for (int i = 1; i <= N; i++) {
            bridge /= i;
        }

        cout << bridge << '\n';
    }

    return 0;
}