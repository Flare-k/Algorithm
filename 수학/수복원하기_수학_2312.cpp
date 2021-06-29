#include <iostream>
using namespace std;

int testCase;

void checkInsu(int num) {
    int div = 2;
    int cnt = 0;

    while (num != 0) {

        if (num % div == 0) {
            num /= div;
            cnt++;
        }
        else {
            if (cnt != 0) cout << div << ' ' << cnt << '\n';
            div++;
            cnt = 0;
            if (num == 1) num = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> testCase;

    while (testCase--) {
        int n;
        cin >> n;

        checkInsu(n);
    }

    return 0;
}