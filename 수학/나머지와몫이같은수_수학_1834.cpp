#include <iostream>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    ll sum = (n * (n - 1) * (n + 1)) / 2;

    cout << sum;

    return 0;
}
/*
3 = 4, 8
4 = 5, 10, 15
5 = 6, 12, 18, 24
n = n+1, 2(n+1), 3(n+1), (n-1)(n+1)
  = (1+2+...+n-1)(n+1)
  = (1+2+...+n-1+n-n) -> n(n+1)/2 - n = n(n-1)/2 -> n(n-1)/2 * (n+1)
  = n(n-1)(n+1) / 2
*/