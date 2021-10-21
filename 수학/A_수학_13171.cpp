#include <iostream>
#define ll long long
#define MAX 1000000007
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll A, X;

    cin >> A >> X;

    ll answer = 1;

    while (X > 0) {
        if (X % 2 == 1) answer = (answer * A) % MAX;

        X /= 2;
        A = (A % MAX) * (A % MAX) % MAX;
    }

    cout << answer % MAX;

    return 0;
}