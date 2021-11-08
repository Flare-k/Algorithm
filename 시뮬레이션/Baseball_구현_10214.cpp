#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int yonsei = 0, korea = 0;

        for (int i = 0; i < 9; i++) {
            int y, k;
            cin >> y >> k;

            yonsei += y;
            korea += k;
        }

        if (yonsei > korea) cout << "Yonsei" << '\n';
        else if (yonsei < korea) cout << "Korea" << '\n';
        else cout << "Draw" << '\n';
    }

    return 0;
}