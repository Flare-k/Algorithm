#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N, T;
vector<int> arr, tmp, answer;

bool promising(int diff) {
    tmp.clear();
    tmp.resize(N, 0);
    copy(arr.begin(), arr.end(), tmp.begin());
    int cnt = 0;

    // -> 방향으로 가면서 갱신
    for (int i = 0; i < N - 1; i++) {
        if (tmp[i + 1] - tmp[i] > diff) {
            cnt += tmp[i + 1] - (tmp[i] + diff);
            tmp[i + 1] = tmp[i] + diff;
        }
    }

    // 위에서 갱신된 값을 기준으로 새로운 차이가 생겼으므로 <- 방향으로도 갱신
    for (int i = N - 1; i > 0; i--) {
        if (tmp[i - 1] - tmp[i] > diff) {
            cnt += tmp[i - 1] - (tmp[i] + diff);
            tmp[i - 1] = tmp[i] + diff;
        }
    }

    if (cnt <= T) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> T;

    arr.resize(N, 0);
    answer.resize(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int maxDiff = -1e9;
    for (int i = 0; i < N - 1; i++) {
        maxDiff = max(maxDiff, abs(arr[i] - arr[i + 1]));
    }

    int start = 0;
    int end = maxDiff;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (promising(mid)) {
            copy(tmp.begin(), tmp.end(), answer.begin());
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << answer[i] << ' ';
    }

    return 0;
}