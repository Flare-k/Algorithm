#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, S;
    cin >> N >> S;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int start = 0;
    int end = 1;
    int sum = arr[start];
    int minLen = 21e8;

    for (int num : arr) {
        if (num == S) {
            cout << 1;
            return 0;
        }
    }

    while (end != N) {
        if (sum < S) {
            sum += arr[end++];
        }
        else if (sum >= S) {
            if (minLen > end - start) minLen = end - start;
            if (minLen == 2) break;
            sum -= arr[start++];
        }
    }

    cout << minLen;

    return 0;
}

