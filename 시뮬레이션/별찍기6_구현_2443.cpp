#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << ' ';
        }

        int idx = 2 * (n - i) - 1;
        for (int k = 0; k < idx; k++) {
            cout << '*';
        }

        cout << '\n';
    }

    return 0;
}