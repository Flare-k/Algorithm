#include <iostream>
#include <algorithm>
using namespace std;

int S, K;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> S >> K;

    long long maxAns = 1;
    long long value = S / K;
    long long idx = S % K;

    for (int i = 0; i < K - idx; i++) {
        maxAns *= value;
    }

    for (int i = 0; i < idx; i++) {
        maxAns *= (value + 1);
    }

    cout << maxAns;

    return 0;
}