#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--) {
        int idx;
        string str;
        cin >> idx >> str;

        for (int i = 0; i < str.length(); i++) {
            if (i == idx - 1) continue;
            cout << str[i];
        }
        cout << '\n';
    }

    return 0;
}