#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    ll arr[n];

    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    ll sum = 0;

    for (ll i = 0; i < n; i++) {
        sum += (arr[i] * (2 * i - n + 1));
    }

    cout << sum * 2;

    return 0;
}