#include <iostream>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll X;
    int N;
    cin >> X >> N;

    ll answer = 0;
    while (N--) {
        int a, b;
        cin >> a >> b;
        answer += (a * b);
    }

    if (X == answer) cout << "Yes" << '\n';
    else cout << "No" << '\n';

    return 0;
}