#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        string p;
        bool flag = true;
        cin >> p;

        if (p == "0") break;

        for (int i = 0; i < p.length() / 2; i++) {
            if (p[i] != p[p.length() - 1 - i]) {
                cout << "no" << '\n';
                flag = false;
                break;
            }
        }

        if (flag) cout << "yes" << '\n';
    }

    return 0;
}