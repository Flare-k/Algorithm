#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int cnt;
ll n, k;

ll func(int a, int b) {
    int num = 0;
    for (ll i = b; (a / i) >= 1; i *= b) {
        num += (a / i);
    }

    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    ll f = 0, t = 0;

    f = func(n, 5) - func(n - k, 5) - func(k, 5);
    t = func(n, 2) - func(n - k, 2) - func(k, 2);

    cout << min(f, t);

    return 0;
}