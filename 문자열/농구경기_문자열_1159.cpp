#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
using namespace std;

map<char, int> players;
set<char> tmp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    string player;
    for (int i = 0; i < n; i++) {
        cin >> player;

        players[player[0]]++;
        tmp.insert(player[0]);
    }

    string ans = "";
    for (char ch : tmp) {
        if (players[ch] >= 5) ans += ch;
    }

    if (ans != "") {
        sort(ans.begin(), ans.end());
        cout << ans;
    }
    else {
        cout << "PREDAJA";
    }

    return 0;
}