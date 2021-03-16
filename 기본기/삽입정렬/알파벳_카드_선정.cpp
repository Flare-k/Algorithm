#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int card[27] = {0};

    string cards;
    cin >> cards;

    sort(cards.rbegin(), cards.rend());

    int n;
    cin >> n;

    string ans = "";

    for (int i = 0; i < n; i++) {
        ans += cards[i];
    }

    for (auto s : ans) {
        card[s - 65]++;
    }

    char res;
    int maxNum = -1;
    for (int i = 1; i < 27; i++) {
        if (card[i] && card[i] > maxNum) {
            maxNum = card[i];
            res = 'A' + i;
        }
    }

    cout << res;

    return 0;
}