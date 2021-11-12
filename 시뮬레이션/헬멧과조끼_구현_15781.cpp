#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N, M, helet = 0, vest = 0;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        ll num;
        cin >> num;
        helet = max(helet, num);
    }

    for (int i = 0; i < M; i++) {
        ll num;
        cin >> num;
        vest = max(vest, num);
    }

    cout << helet + vest << '\n';

    return 0;
}