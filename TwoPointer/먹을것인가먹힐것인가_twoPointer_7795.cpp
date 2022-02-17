#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<int> A(N), B(M);
        
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        for (int i = 0; i < M; i++) {
            cin >> B[i];
        }

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int answer = 0, point = 0;

        // two-pointer
        for (int i = 0; i < N; i++) {
            while ((point < M) && A[i] > B[point]) point++;
            answer += point;
        }

        cout << answer << '\n';
    }

    return 0;
}
