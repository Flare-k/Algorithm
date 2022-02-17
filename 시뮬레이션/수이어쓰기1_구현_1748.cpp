#include <iostream>
#define ll long long
using namespace std;

ll length(int N) {
    ll len = 0;

    for (int start = 1, i = 1; start <= N; start *= 10, ++i) {
        int end = (start * 10) - 1;
        if (end > N) end = N;

        len += (ll)(end - start + 1) * i;
    }

    return len;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    cout << length(N) << '\n';

    return 0;
}