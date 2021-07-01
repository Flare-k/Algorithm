#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string phone;

    for (int i = 0; i < 3; i++) {
        int cnt = 1;
        int s = 0;
        int maxx = -1;

        cin >> phone;

        for (int j = 1; j < 8; j++) {
            if (phone[s] == phone[j]) {
                cnt++;
            }
            else {
                maxx = max(maxx, cnt);
                cnt = 1;
                s = j;
            }
        }

        maxx = max(maxx, cnt);

        cout << maxx << '\n';
    }

    return 0;
}