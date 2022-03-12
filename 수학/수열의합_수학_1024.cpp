#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long N, L;

    cin >> N >> L;
    
    for (long long k = L; k <= 100; k++) {
        long long start = max(0LL, N / k - k + 1);  // 하한
        long long end = N / k + 1;                // 상한

        for (long long i = start; i <= end; i++) {
            long long r1 = (i + k) * (i + k - 1) / 2;
            long long r2 = i * (i - 1) / 2;

            if (r1 - r2 == N) {
                for (int num = i; num < i + k; num++) {
                    cout << num << ' ';
                }
                return 0;
            }
        }

    }

    cout << -1 << '\n';

    return 0;
}