#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> multitap(n);

    for (int i = 0; i < n; i++) {
        cin >> multitap[i];
    }

    sort(multitap.begin(), multitap.end());

    for (int i = 0; i < n - 1; i++) {
        multitap[i] -= 1;           // 맨 마지막 멀티탭을 제외하고 다 하나씩 맞물려야 하므로 한 플러그씩 제거
    }

    int sum = 0;
    for (int tap : multitap) {
        sum += tap;
    }

    cout << sum;

    return 0;
}