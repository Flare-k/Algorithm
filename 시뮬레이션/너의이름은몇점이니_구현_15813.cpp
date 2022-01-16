#include <iostream>
using namespace std;

int len, sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> len;

    for (int i = 0; i < len; i++) {
        char ch;
        cin >> ch;

        sum += (ch - 'A' + 1);
    }

    cout << sum;

    return 0;
}