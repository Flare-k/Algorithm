#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int num;
        int sum = 0;
        int minNum = 21e8;

        for (int i = 0; i < 7; i++) {
            cin >> num;
            if (num % 2 == 0) {
                sum += num;
                minNum = min(minNum, num);
            }
        }

        cout << sum << ' ' << minNum << '\n';
    }

    return 0;
}