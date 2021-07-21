#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, bool> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> arr(3);

    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
        m[arr[i]] = true;
    }

    sort(arr.begin(), arr.end());

    int diff = 21e8;
    for (int i = 0; i < 2; i++) {
        diff = min(diff, arr[i + 1]- arr[i]);
    }

    int num;
    num = arr.front();
    for (int i = 0; i < 4; i++) {
        if (!m.count(num)) cout << num;
        num += diff;
    }

    return 0;
}