#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Y = 0, M = 0;
    int cost;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> cost;

        Y += (cost / 30 + 1);
        M += (cost / 60 + 1);
    }

    Y *= 10;
    M *= 15;

    if (Y < M) cout << "Y " << Y << '\n';
    else if (Y > M) cout << "M " << M << '\n';
    else cout << "Y M " << Y << '\n';

    return 0;
}