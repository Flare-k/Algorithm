#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<ll> test;
vector<ll> teacher;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        test.push_back(t);
    }

    for (int i = 0; i < 2; i++) {
        ll t;
        cin >> t;
        teacher.push_back(t);
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ans ++; // 총 감독
        test[i] -= teacher.front();

        if (test[i] > 0) {
            if (test[i] % teacher[1] == 0) ans += (test[i] / teacher[1]);
            else ans += (test[i] / teacher[1]) + 1;
        }
    }

    cout << ans;

    return 0;
}