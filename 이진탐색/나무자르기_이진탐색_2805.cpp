#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

int main() {

    int n;
    ll m;
    cin >> n >> m;

    vector<ll> trees(n);

    for (int i = 0; i < n; i++) {
        cin >> trees[i];
    }

    sort(trees.begin(), trees.end());

    ll s = 0;
    ll e = trees.back();
    ll res = -21e8;

    while (s <= e) {
        ll mid = (s + e) / 2;

        ll sum = 0;
        for (ll tree : trees) {
            if (tree >= mid) sum += (tree - mid);
        }

        if (sum >= m) {
            if (res < mid) res = mid;
        }

        if (sum > m) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }

    cout << res;

    return 0;
}