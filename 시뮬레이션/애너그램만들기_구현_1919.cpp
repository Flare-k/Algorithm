#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int check[28];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string t1, t2;
    cin >> t1 >> t2;

    for (char ch : t1) {
        check[ch - 'a']++;
    }

    for (char ch : t2) {
        check[ch - 'a']--;
    }

    int cnt = 0;

    for (int i = 0; i < 28; i++) {
        cnt += abs(check[i]);
    }

    cout << cnt;

    return 0;
}