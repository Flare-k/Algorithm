#include <iostream>
#include <queue>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    priority_queue<ll> pq;

    ll num;
    for (int i = 0; i < n * n; i++) {
        cin >> num;

        pq.push(-num);
        if (pq.size() > n) pq.pop();
    }

    cout << -pq.top();

    return 0;
}