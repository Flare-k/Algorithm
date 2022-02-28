#include <iostream>
#include <algorithm>
#include <map>
#define ll long long
using namespace std;

ll N, P, Q;
map<ll, ll> m;

ll run(ll n) {
    if (m.count(n)) return m[n];
    else return m[n] = run(n / P) + run(n / Q);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    m[0] = 1;
    cin >> N >> P >> Q;
    cout << run(N) << '\n';

    return 0;
}
/* map은 모든 원소를 참조하지 않는다. */