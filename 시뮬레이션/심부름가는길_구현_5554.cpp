#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int sec = 0;
    int n;
    for (int i = 0; i < 4; i++) {
        cin >> n;
        sec += n;
    }

    cout << sec / 60 << '\n' << sec % 60;

    return 0;
}