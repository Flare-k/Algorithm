#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string ppap = "";
    string target = "pPAp";

    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        ppap += ch;
    }

    int cnt = 0;
    for (int i = 0; i <= n - 4; i++) {
        string tmp = ppap.substr(i, 4);

        if (tmp == target) {
            i += 3;
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}