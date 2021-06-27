#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int n, m;
ll minn = 21e8;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    vector<ll> arr;

    ll num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    int start = 0;
    for (int end = 1; end < n; end++) {
        if (arr[end] - arr[start] < m) continue;    // 두 수의 차가 m보다 작다면 continue
        else if (minn > m) {    // 두 수의 차가 m보다 크거나 같고, minn이 m보다 크다면..
            minn = min(minn, arr[end--] - arr[start++]);    // 다음 end와 차가 더 최소일 수도 있으므로 end는 --해주고 start는 ++
        }
        
    }

    cout << minn;

    return 0;
}