#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

set<string> bucekt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string S;
    cin >> S;

    for (int i = 0; i < S.length(); i++) {
        string tmp = "";
        for (int j = i; j < S.length(); j++) {
            tmp += S[j];
            bucekt.insert(tmp);
        }
    }

    cout << bucekt.size();

    return 0;
}