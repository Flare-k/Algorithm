#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> K >> N;

    vector<ll> kRope;
    ll rope;

    for (int i = 0; i < K; i++) {
        cin >> rope;
        kRope.push_back(rope);
    }

    sort(kRope.begin(), kRope.end());

    ll res = -21e8;
    ll s = 1;
    ll e = kRope.back();

    while (s <= e) {
        ll mid = (s + e) / 2;

        int sum = 0;
        for (ll num : kRope) {
            sum += (num / mid);
        }

        if (sum >= N) {
            if (res < mid) res = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }

    cout << res;

    return 0;
}