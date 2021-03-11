#include <iostream>
using namespace std;
typedef long long LL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    LL N, M;

    cin >> N >> M;

    int arr[10001];

    for (LL i = 0; i < N; i++) {
        cin >> arr[i];
    }

    LL start = 0, sum = 0, cnt = 0;

    for (int i = 0; i < N; i++) {
        sum += arr[i];

        while (sum >= M) {
            if (sum == M) {
                cnt++;
            }
            sum -= arr[start++];
        }
    }

    cout << cnt;

    return 0;
}