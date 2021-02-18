#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N;
    cin >> N;

    int arr[27];
    fill(arr, arr + 27, 0);

    for (int i = 0; i < N; i++) {
        string s;
        int cnt = 1;
        cin >> s;

        for (int j = s.length() - 1; j >= 0; j--) {
            arr[s[j] - 'A'] += cnt;
            cnt *= 10;
        }
    }

    vector<long long> tmp;
    for (int i = 0; i < 27; i++) {
        if (arr[i] != 0) {
            tmp.push_back(arr[i]);
        }
    }

    sort(tmp.begin(), tmp.end());

    int value = 9;
    long long ans = 0;

    for (int i = tmp.size() - 1; i >= 0; i--) {
        ans += tmp[i] * value;
        value--;
    }

    cout << ans << '\n';

    return 0;
}