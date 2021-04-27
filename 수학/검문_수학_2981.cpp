#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr;

long long gcd(long long a, long long b) {
    // ex 24, 18
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());

    int gcdNum = arr[1] - arr[0];
    for (int i = 2; i < arr.size(); i++) {
       gcdNum = gcd(gcdNum, arr[i] - arr[i - 1]);
    }

    int ans[500];
    fill(ans, ans + 500, 0);
    int idx = 0;
    for (int m = 1; m * m <= gcdNum; m++) {
        if (gcdNum % m == 0) {  // 최대 공약수의 약수인 경우
            ans[idx++] = m;
            if (m != gcdNum / m) ans[idx++] = gcdNum / m;
        }
    }

    sort(ans, ans + idx);

    for (int i = 0; i < idx; i++) {
        if (ans[i] != 1) {
            cout << ans[i] << ' ';
        }
    }


    return 0;
}