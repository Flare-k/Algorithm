#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int line[4];

    for (int i = 0; i < 4; i++) {
        cin >> line[i];
    }

    sort(line, line + 4);

    cout << line[0] * line[2] << '\n';

    return 0;
}