#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int K;
        cin >> K;

        priority_queue<long long, vector<long long>, greater<long long>> pq;

        long long num;
        for (int i = 0; i < K; i++) {
            cin >> num;
            pq.push(num);
        }

        long long sum = 0;

        while (!pq.empty()) {

            if (pq.size() == 1) break;

            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();

            sum += (a + b);
            pq.push(a + b);
        }

        cout << sum << '\n';
    }

    return 0;
}