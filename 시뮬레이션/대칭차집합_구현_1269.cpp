#include <iostream>
#include <map>
#include <set>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    map<ll, ll> arr;
    set<ll> ss;

    ll num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr[num]++;
        ss.insert(num);
    }

    for (int i = 0; i < m; i++) {
        cin >> num;
        arr[num]++;
        ss.insert(num);
    }

    int cnt = 0;
    for (ll s : ss) {
        if (arr[s] == 1) cnt++;
    }

    cout << cnt;

    return 0;
}