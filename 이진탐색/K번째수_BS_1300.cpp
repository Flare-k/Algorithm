#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    
    long long start = 1;
    long long end = K;
    long long cnt = 0, mmin;
    long long answer;

    while (start <= end) {
        int mid = (start + end) / 2;

        mmin = min(N, mid);

        for (int i = 1; i <= mmin; i++) {
            cnt += min(N, mid / i);
        }

        if (cnt >= K) {
            cnt = 0;
            answer = mid;
            end = mid - 1;
        }
        else {
            cnt = 0;
            start = mid + 1;
        }
    }

    cout << answer;

    return 0;
}